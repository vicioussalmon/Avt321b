#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

string recoding(char* input_cod, char* output_cod, string txt) { //Функция перекодировки
    for (int i = 0; i < txt.length(); i++) { //Символ в изначальной кодировке меняется на символ с таким же порядковым номером в другой кодировке
        for (int j = 0; input_cod[j] != '\0'; j++) {
            if (txt[i] == input_cod[j]) {
                txt[i] = output_cod[j];
            }
        }

    }
    return txt;
}

void error() { //Сообщение об ошибке
    cout << endl;
    cout << "Данные введены неправильно. Попробуйте еще раз!\n\n";
    cin.clear(); // Чистка потока
}

int main()
{
    setlocale(LC_ALL, "RU");

    int num_of_cod; //Номер исх.к
    int num_of_cod2;//Номер ит.к

    char* pointer_cod_1 = NULL; //Указатель на исх.к 
    char* pointer_cod_2 = NULL; //Указатель на ит.к

    //символы кодировок
    char win1251[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    char koi8r[] = "ЮАБЦДЕёФГХИЙКЛМНОПЯРСТУЖВЬЫЗШЭЩЧЪюабцдеЁфгхийклмнопярстужвьызшэщчъ";
    char Mac[] = "абвгдеЮжзийклмнопрстуфхцчшщъыьэюЯЂЃ‚ѓ„…Э†‡€‰Љ‹ЊЌЋЏђ‘’“”•–—™љ›њќћџ";


    while (true) { //ошибка - вопросы
        cout << "Выберите исходную кодировку вашего текста:" << endl;
        cout << "1. win1251" << endl;
        cout << "2. koi8r" << endl;
        cout << "3. Mac" << endl;

        cin >> num_of_cod; //исх.к

        if (num_of_cod != 1 && num_of_cod != 2 && num_of_cod != 3) {
            error(); //некорректный ввод - ошибка
        }
        else break;
    }

    while (true) { //ошибка - вопросы
        cout << "Выберите кодировку итогового текста: ";

        cin >> num_of_cod2; //ит.к

        if (num_of_cod2 != 1 && num_of_cod2 != 2 && num_of_cod2 != 3) { //корректность ввода
            error();
        }
        else break;
        if (num_of_cod == num_of_cod2) //совпадения
        {
            cout << "Кодировки исходного и итогового текста совпадают. Пожалуйста, выберите другую.";
            error();
        }
        else break;
    }

    switch (num_of_cod) { //указатель - исх.к
    case 1:
        pointer_cod_1 = win1251; break;
    case 2:
        pointer_cod_1 = koi8r; break;
    case 3:
        pointer_cod_1 = Mac; break;
    }

    switch (num_of_cod2) { //указатель - ит.к
    case 1:
        pointer_cod_2 = win1251; break;
    case 2:
        pointer_cod_2 = koi8r; break;
    case 3:
        pointer_cod_2 = Mac; break;
    }

    string result, buffer;
    ifstream orig_file("orig.txt"); //открытие файла на чтение
    ofstream res_file("res.txt"); //открытие файла на запись

    //while чимчикует по всем строчкам
    while (getline(orig_file, buffer)) {  //считывает 1ст
        result = recoding(pointer_cod_1, pointer_cod_2, buffer); //перекодирует 1ст
        res_file << result + "\n"; //записывает в файл 1ст
    }

    orig_file.close();
    res_file.close();
}