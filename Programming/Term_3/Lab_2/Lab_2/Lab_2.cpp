#include <iostream>
#include "Header.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    float ve1[3], ve2[3];
    float dl, mnim, dl1, mnim1; 
    complex <float> Y; 
    float b = 0;
    cout << "Введите вещественную часть: "; cin >> dl;
    cout << "Введите мнимую часть: "; cin >> mnim;
    cout << endl;
    complex<float> x(dl, mnim);
    cout << "Введите вещественную часть: "; cin >> dl1;
    cout << "Введите мнимую часть: "; cin >> mnim1;
    cout << endl;
    complex<float> x1(dl1, mnim1);
    x.slog(x, Y);
    cout << endl;
    x.vush(x, Y);
    cout << endl;
    x.ymnog(x, Y);
    cout << endl;
    x.delenie(x, Y);
    cout << endl;
    cout << "Создаем 1 вектор:  " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << "вещественную часть: " << endl; cin >> ve1[i];
        cout << i + 1 << "мнимую часть: " << endl; cin >> ve2[i];
        x.vector(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);
        cout << "Создаем 2 вектор: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << "вещественную часть: " << endl; cin >> ve1[i];
            cout << i + 1 << "мнимую часть: " << endl; cin >> ve2[i];
        }
        Y.vector(ve1[0], ve1[1], ve1[2], ve2[0], ve2[1], ve2[2]);
        x.slogvector(x, Y);
        cin.get();
        cin.get();
    }
}
