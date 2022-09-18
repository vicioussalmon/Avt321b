#include <iostream>
#include <string.h> 
#include <stdio.h> 
#include "Contents.h"
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;
void sch(char* str) {
    int slovo, count = 0;
    int i = 0;
    while (*(str + i) == ' ' && *(str + i) != '\0')
        i++;
    slovo = 0;
    while (*(str + i) != '\0') {
        if (*(str + i) != ' ' && slovo == 0)
        {
            slovo = 1;
            count++;
        }
        else if (*(str + i) == ' ')
            slovo = 0;
        i++;
    }
    cout << "Количество слов в строке: " << endl;
    cout << count;
    cout << endl;
}
void osn() {
    while (true) {
        setlocale(LC_ALL, "Russian");
        int n;
        cout << "Введите количество символов строки" << endl;
        cin >> n;

        char* str = new char[n + 1]; // 0 терминтор
        cout << "Введите строку: " << endl;
        cin.ignore(); //символ пустой строки (\n)
        cin.getline(str, n + 1); //пробел

        sch(str);

        delete[]str;
        str = nullptr;
    }
}