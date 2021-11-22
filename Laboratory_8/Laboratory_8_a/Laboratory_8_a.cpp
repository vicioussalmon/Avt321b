#include <iostream>

#include <math.h>

#include <iomanip>

#include <ctime>

#include <string>

using namespace std;




int main(){
    setlocale(LC_ALL, "Russian");
    int Ar[6];
    int Mass[6];
    int i = 0;
    int b = 0;
    int all_places = 0;
    int smoking_place = 0;
    string a;
    int no_smoking_place = 0;


    //cout << "Вас приветствует компания UkraineAirLines" << endl;

    //cout << "Для бронирования билетов сообщите, пожалуйста, курите вы или нет" << endl;

    for (int i = 0; ;)
    {
        cout << "Вы курите? <yes/no>";

        cin >> a;

        if (a == "yes" && smoking_place < 5)
        {
            i++;
            Ar[i] = i;
            smoking_place = Ar[i];
            cout << "Ваше место:" << smoking_place << endl;
            int all_places = i + b;
            if (all_places == 10)
            {
                cout << "Места закончились" << endl;
                break;
            }
            continue;
        }
        if (a == "no" && no_smoking_place < 10)
        {
            b++;
            Mass[b] = b + 5;
            no_smoking_place = Mass[b];
            cout << "Ваше место:" << no_smoking_place << endl;
            int all_places = i + b;
            if (all_places == 10)
            {
                cout << "Места закончились" << endl;
                break;
            }
            continue;
        }

    }
    return 0;
}