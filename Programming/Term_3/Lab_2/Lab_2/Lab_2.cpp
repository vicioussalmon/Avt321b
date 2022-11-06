#include <iostream>

using namespace std;
float ve1[3], ve2[3];
template <class T>
class complex
{
    T v;
public:
      float c, m;
      int r;
      float vc[3];
      float vm[3];
      float slv1[3];
      float slv2[3];
      float vuc1, vuc2;
      complex(float d, float e)
      {
          c = d;
          m = e;
      };
      complex()
      {}
      void vector(float ve1, float ve2, float ve3, float ve4, float ve5, float ve6)
      {
          vc[0] = ve1;
          vc[1] = ve2;
          vc[2] = ve3;
          vm[0] = ve4;
          vm[1] = ve5;
          vm[2] = ve6;
          cout << "\t\t\tВектор: " << "(" << vc[0] << "+" << "(" << vm[0] << ")" << "i" << "," << vc[1] << "+" << "(" << vm[1] << ")" << "i" << "," << vc[2] << "+" << "(" << vm[2] << ")" << "i" << ")" << "\n";
      }
      void slogvector(complex <float> x, complex <float>Y)
      {
          slv1[0] = x.vc[0] + Y.vc[0];
          slv1[1] = x.vc[1] + Y.vc[1];
          slv1[2] = x.vc[2] + Y.vc[2];
          slv2[0] = x.vm[0] + Y.vm[0];
          slv2[1] = x.vm[1] + Y.vm[1];
          slv2[2] = x.vm[2] + Y.vm[2];
          cout << "\t\t\t\tПолученный вектор " << endl;
          cout << "\t\t\tПервый символ: " << "(" << slv1[0] << ")" << slv2[0] << ")" << "i" << "," << slv1[1] << "+" << slv2[1] << ")" << "i" << "," << slv1[2] << "+" << "(" << slv2[2] << ")" << "i" << ")" << "\n";
      }
      void slog(complex<float> x, complex <float> Y)
      {
          vuc1 = x.c + Y.c;
          vuc2 = x.m + Y.m;
          cout << "Сложение равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
      }
      void vush(complex<float> x, complex <float> Y)
      {

          vuc1 = x.c - Y.c;
          vuc2 = x.m - Y.m;
          cout << "Вычитание равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
      }
      void ymnog(complex<float> x, complex <float> Y)
      {
          vuc1 = x.c * Y.c + x.m * Y.m;
          vuc2 = x.c * Y.m + x.m * Y.c;
          cout << "Умножение равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
      }
      void delenie(complex<float> x, complex <float> Y)
      {
          vuc1 = (x.c * Y.c + x.m * Y.m) / (Y.c * Y.c * Y.m * Y.m);
          vuc2 = (x.m * Y.c - x.c * Y.m) / (Y.c * Y.c * Y.m * Y.m);
          cout << "Деление равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
      }
};
void main()
{
    setlocale(LC_ALL, "Russian");
    float dl, mnim, dl1, mnim1; complex <float> Y; float b = 0;
    cout << "------------------------------------------------" << endl;
    cout << "Введите вещественную часть: "; cin >> dl;
    cout << "Введите мнимую часть: "; cin >> mnim;
    cout << endl;
    complex<float> x(dl, mnim);
    cout << "------------------------------------------------" << endl;
    cout << "Введите вещественную часть: "; cin >> dl1;
    cout << "Введите мнимую часть: "; cin >> mnim1;
    cout << endl;
    complex<float> x1(dl1, mnim1);
    while (true)
    {
        int a;
        cout << "------------------------------------------------" << endl;
        cout << "Выберите номер операции: \n (1)Сложение \n (2)Вычитание \n (3)Умножение \n (4)Деление \n (5)Создать два вектора из комплексных координат \n (0)Выход \n" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> a;
        switch (a)
        {
        case 1: {
            system("cls");
            x.slog(x, Y);
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            system("cls");
            x.vush(x, Y);
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            system("cls");
            x.ymnog(x, Y);
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            system("cls");
            x.delenie(x, Y);
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            system("cls");
            
           /* cout << "Задайте размерность вектора: " << endl;
            cin >> r;*/

            cout << "Создаем 1 вектор:  " << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << " вещественную часть: " << endl; cin >> ve1[i];
                cout << i + 1 << " мнимую часть: " << endl; cin >> ve2[i];
                x.vector(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);
                cout << "Создаем 2 вектор: " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << i + 1 << " вещественную часть: " << endl; cin >> ve1[i];
                    cout << i + 1 << " мнимую часть: " << endl; cin >> ve2[i];
                }
                Y.vector(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);
                x.slogvector(x, Y);
                cin.get();
                cin.get();
            }
            system("pause");
            system("cls");
            break;
        }
        case 0: {
            system("cls");
            exit(0);
            break;
        }

        default:
            system("cls");
            cout << " \t\t\tERROR " << endl;
            break;
        }

    }
}  
    
