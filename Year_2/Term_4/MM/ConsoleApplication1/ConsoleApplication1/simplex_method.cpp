#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <locale>

#include "user_input.h"
#include "simplex_method.h"




using  namespace std;

void simplex::init()		//ініціалізація опорного плану
{
    int i, j;
    func = 0;
    sv = new double* [num_l];
    for (i = 0; i < num_l; i++)
        sv[i] = new double[num_v * 2];
    for (i = 0; i < num_l; i++)
    {       //заповнення введеними даними користувача
        for (j = 0; j < num_v; j++)
            sv[i][j] = system[i][j];
        for (; j < num_v * 2; j++)      //заповненя одиничною матрицею 
            if (i + num_v == j)
                if (way)
                    sv[i][j] = 1;
                else
                    sv[i][j] = -1;
            else
                sv[i][j] = 0;
    }
    istr = new double[num_v * 2];
    bv = new double* [num_l];
    for (i = 0; i < num_l; i++)
    {
        bv[i] = new double[2];
        bv[i][0] = i + num_v;
        bv[i][1] = fm[i];
    }
    for (i = 0; i < num_v * 2; i++)     //Заповнення індексного рядка коефіцієнтами цільової функції зі зворотнім знаком, заповнення другої половини нулями
        if (i < num_v)
            istr[i] = function[i] * -1;
        else
            istr[i] = 0;
    i_lcol = 0;
    for (i = 0; i < num_v * 2 - 1; i++)
    {   //визначаємо позицію ведучого стовпця
        if (istr[i] < 0)
            if (fabs(istr[i + 1]) > fabs(istr[i]))
                i_lcol = i + 1;
    }
    th = new double[num_l];                 //ініціалізація Tetha стовпця
    for (i = 0; i < num_l; i++)
        th[i] = bv[i][1] / sv[i][i_lcol];
    i_lrow = 0;
    for (i = 0; i < num_l - 1; i++)
        if (th[i] > th[i + 1])
            i_lrow = i + 1;
    alm = sv[i_lrow][i_lcol];
    print_result_to_file(0);				//занесення опорного плану в файл
}
bool simplex::plane_is_valid()				//перевірка оптимальності плану
{
    int i;
    bool result = true;
    if (way)
        for (i = 0; i < num_v * 2; i++)
            if (istr[i] < 0)
            {
                result = false;
                break;
            }
    if (!way)
        for (i = 0; i < num_v * 2; i++)
            if (istr[i] >= 0)
            {
                result = false;
                break;
            }

    return result;
}
bool simplex::function_is_undefined()			//перевірка на відсутність розв'язку(на від'ємність тета-елементів)
{
    int i;
    for (i = 0; i < num_l; i++)
        if (th[i] < 0)
        {
            return false;
        }
    return true;
}
void simplex::gen_plane()						//розрахунок оптимального плану
{
    int i, j, it_num = 0;
    double A, B;
    while (!plane_is_valid() && function_is_undefined())
    {
        A = bv[i_lrow][1];
        B = istr[i_lcol];
        func -= A * B / alm;
        double* tmp_bv = new double[num_l];
        bv[i_lrow][0] = i_lcol;
        A = bv[i_lrow][1];
        for (i = 0; i < num_l; i++)
        {
            B = sv[i][i_lcol];
            tmp_bv[i] = bv[i_lrow][1];
            if (i != i_lrow)
                tmp_bv[i] = bv[i][1] - A * B / alm;
            else
                tmp_bv[i] /= alm;
        }
        for (i = 0; i < num_l; i++)
            bv[i][1] = tmp_bv[i];
        double* tmp_istr = istr;
        B = istr[i_lcol];
        for (i = 0; i < num_v * 2; i++)
        {
            A = sv[i_lrow][i];
            tmp_istr[i] = istr[i] - A * B / alm;
        }
        istr = tmp_istr;
        double** tmp_sv = new double* [num_l];
        for (i = 0; i < num_l; i++)
            tmp_sv[i] = new double[num_v * 2];
        for (i = 0; i < num_l; i++)
            for (j = 0; j < num_v * 2; j++)
            {
                tmp_sv[i][j] = sv[i][j];
                A = sv[i_lrow][j];
                B = sv[i][i_lcol];
                if (i == i_lrow)
                    tmp_sv[i][j] /= alm;
                else
                    tmp_sv[i][j] = sv[i][j] - A * B / alm;
            }
        sv = tmp_sv;
        i_lcol = 0;
        for (i = 0; i < num_l; i++)
            th[i] = bv[i][1] / sv[i][i_lcol];
        i_lrow = 0;
        for (i = 0; i < num_l - 1; i++)
            if (th[i] > th[i + 1])
                i_lrow = i + 1;
        alm = sv[i_lrow][i_lcol];
        it_num++;
        print_result_to_file(it_num);
    }

    if (!function_is_undefined())
        cout << "\n\t\tThe objective function is not limited, the problem has no solutions\n" << endl;
    else
    {
        cout << "\nf(x) = " << func << "\n" << endl;
        for (i = 0; i < num_l; i++)
        {
            cout << "x" << bv[i][0] + 1 << " = " << bv[i][1] << endl;
        }
        cout << "\nAll calculations were recorded in a file\n" << endl;
    }
}

void simplex::print_result_to_file(int it_num) // занесення даних до таблиці Excel
{
    std::locale loc("ru_RU.utf8");
    table.imbue(loc);

    int i, j;
    if (!it_num)
    {
        table << "Target function:\n" << endl;
        std::stringstream f_x;
        f_x << "f(x) = ";
        for (i = 0; i < num_v; i++)
        {
            if (!i)
                f_x << function[i] << "x" << i + 1 << " ";
            else
            {
                if (function[i] < 0)
                    f_x << "- " << fabs(function[i]) << "x" << i + 1 << " ";
                if (function[i] > 0)
                    f_x << "+ " << function[i] << "x" << i + 1 << " ";
            }
        }
        std::string minmax;
        if (way)
            minmax = "max";
        else
            minmax = "min";
        f_x << "=> " << minmax << "\n" << endl;
        table << f_x.str();
        table << "System of restrictions:\n" << endl;
        std::stringstream math_sys;
        std::string math_sign;
        for (i = 0; i < num_l; i++)
        {
            int cnt = 1;
            for (j = 0; j < num_v; j++)
            {
                if (!j)
                    math_sys << system[i][j] << "x" << cnt++ << " ";
                else
                    if (system[i][j] == 1)
                        if (!j)
                            math_sys << "x" << cnt++ << " ";
                        else
                            math_sys << "+ x" << cnt++ << " ";
                    else
                        if (system[i][j] == -1)
                            if (!j)
                                math_sys << "-x" << cnt++ << " ";
                            else
                                math_sys << "- x" << cnt++ << " ";
                        else
                        {
                            if (system[i][j] < 0)
                                math_sys << "- " << fabs(system[i][j]) << "x" << cnt++ << " ";
                            else
                                math_sys << "+ " << system[i][j] << "x" << cnt++ << " ";
                            if (!sign[i])
                                math_sign = "<=";
                            if (sign[i] == 1)
                                math_sign = "=";
                            if (sign[i] == 2)
                                math_sign = ">=";
                        }
            }

            math_sys << math_sign << " " << fm[i];
            math_sys << endl;
        }
        std::string min_or_max;
        if (way)
            min_or_max = "Maximization";
        else
            min_or_max = "Minimization";
        table << math_sys.str() << endl;
        table << "The problem on  " << min_or_max << " is solved by the simplex method using the simplex table.\nBaseline:\n" << endl;
    }
    for (i = 0; i < num_l; i++)
    {
        table << "x" << bv[i][0] + 1 << ";" << bv[i][1] << ";";
        for (j = 0; j < num_v * 2; j++)
            table << sv[i][j] << ";";
        if (!plane_is_valid())
            table << th[i];
        table << "\n" << endl;
    }
    table << "f(x);" << func << ";";
    for (i = 0; i < num_v * 2; i++)
        table << istr[i] << ";";
    table << "\n";

    if (plane_is_valid())
    {
        if (plane_is_valid() && function_is_undefined())
            table << "\n\t\tThe given plan is optimal." << endl;
        std::ofstream outfile("table.csv");
        outfile << table.str();
    }
    else
    {
        std::string ln_or_gn;
        if (way)
            ln_or_gn = "Positive";
        else
            ln_or_gn = "Negative";
        std::stringstream num_of_plane;
        if (!it_num)
            num_of_plane << "First baseline";
        else
            num_of_plane << it_num + 1 << "-th plan also";
        table << "\n" << num_of_plane.str() << " is not optimal because there are -L in the line " << ln_or_gn << " elements.\n" << endl;
    }

}
