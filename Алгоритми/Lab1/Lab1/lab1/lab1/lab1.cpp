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

    int num_of_cod; //Номер исходной кодировки
    int num_of_cod2;//Номер итоговой кодировки

    char* pointer_cod_1 = NULL; //Указатель на исходную кодировку (поменяется в зависимости от выбранной кодировки)
    char* pointer_cod_2 = NULL; //Указатель на итоговую кодировку (поменяется в зависимости от выбранной кодировки)

    //Массивы с символами разных кодировок
    char win1251[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    char koi8r[] = "ЮАБЦДЕёФГХИЙКЛМНОПЯРСТУЖВЬЫЗШЭЩЧЪюабцдеЁфгхийклмнопярстужвьызшэщчъ";
    char macintosh[] = "абвгдеЮжзийклмнопрстуфхцчшщъыьэюЯЂЃ‚ѓ„…Э†‡€‰Љ‹ЊЌЋЏђ‘’“”•–—™љ›њќћџ";


    while (true) { //Если данные будут введены не правильно, цикл будет повторять вопросы
        cout << "Выберите исходную кодировку вашего текста:" << endl;
        cout << "1. win1251" << endl;
        cout << "2. koi8r" << endl;
        cout << "3. macintosh" << endl;
        cout << "Введите номер опции (1,2,3): ";

        cin >> num_of_cod; //Номер исходной кодировки

        if (num_of_cod != 1 && num_of_cod != 2 && num_of_cod != 3) {
            error(); //Если ввод данных неправильный - выдается ошибка и повторяется вопрос
        }
        else break;
    }

    while (true) { //Если данные будут введены не правильно, цикл будет повторять вопросы
        cout << "Выберите кодировку итогового текста: ";

        cin >> num_of_cod2; //Номер итоговой кодировки

        if (num_of_cod2 != 1 && num_of_cod2 != 2 && num_of_cod2 != 3) { //Проверка на правильность выбора кодировки из меню
            error();
        }
        else break;
        if (num_of_cod == num_of_cod2) //Проверка на совпадение исходной и итоговой кодировок
        {
            cout << "Кодировки исходного и итогового текста совпадают. Пожалуйста, выберите другую.";
            error();
        }
        else break;
    }

    switch (num_of_cod) { //Меняется значение указателя на выбранную исходную кодировку
    case 1:
        pointer_cod_1 = win1251; break;
    case 2:
        pointer_cod_1 = koi8r; break;
    case 3:
        pointer_cod_1 = macintosh; break;
    }

    switch (num_of_cod2) { //Меняется значение указателя на выбранную итоговую кодировку
    case 1:
        pointer_cod_2 = win1251; break;
    case 2:
        pointer_cod_2 = koi8r; break;
    case 3:
        pointer_cod_2 = macintosh; break;
    }

    string result, buffer;
    ifstream orig_file("Original.txt"); //Входной файловый поток (открытие файла на чтение)
    ofstream res_file("Result.txt"); //Выходной файловый поток (открытие файла на запись)

    //Цикл while будет длиться пока не пройдется по всем строчкам
    while (getline(orig_file, buffer)) {  //Считывает одну строку
        result = recoding(pointer_cod_1, pointer_cod_2, buffer); //Перекодирует одну строку
        res_file << result + "\n"; //Записывает в файл одну строку
    }

    orig_file.close();
    res_file.close();
}