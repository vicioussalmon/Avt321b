#include "pch.h" 
#include "dll2.h"

void complite() {
    setlocale(LC_ALL, "Russian");
    float dl, mnim, dl1, mnim1; complex <float> Y; float b = 0;
    cout << "------------------------------------------------" << endl;
    cout << "������� ������������ �����: "; cin >> dl;
    cout << "������� ������ �����: "; cin >> mnim;
    cout << endl;
    complex<float> x(dl, mnim);
    cout << "------------------------------------------------" << endl;
    cout << "������� ������������ �����: "; cin >> dl1;
    cout << "������� ������ �����: "; cin >> mnim1;
    cout << endl;
    complex<float> x1(dl1, mnim1);
    while (true)
    {
        int a;
        cout << "------------------------------------------------" << endl;
        cout << "�������� ����� ��������: \n (1)�������� \n (2)��������� \n (3)��������� \n (4)������� \n (5)������� ��� ������� �� ����������� ��������� \n (0)����� \n" << endl;
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

            /* cout << "������� ����������� �������: " << endl;
             cin >> r;*/

            cout << "������� 1 ������:  " << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << " ������������ �����: " << endl; cin >> ve1[i];
                cout << i + 1 << " ������ �����: " << endl; cin >> ve2[i];
                x.vector(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);

            }
            x.print(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);
            cout << "������� 2 ������: " << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << " ������������ �����: " << endl; cin >> ve1[i];
                cout << i + 1 << " ������ �����: " << endl; cin >> ve2[i];

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
