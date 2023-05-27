#include "pch.h" 
#include "dll2.h"

void complite() {
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

            }
            x.print(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);
            cout << "Создаем 2 вектор: " << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << " вещественную часть: " << endl; cin >> ve1[i];
                cout << i + 1 << " мнимую часть: " << endl; cin >> ve2[i];

                Y.vector(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);
            }
            Y.print(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);
            x.slogvector(x, Y);
            cin.get();
            cin.get();
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
