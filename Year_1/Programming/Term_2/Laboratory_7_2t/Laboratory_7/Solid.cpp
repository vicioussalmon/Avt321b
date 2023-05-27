#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include "Contents.h" 
#include "Struct.h" 
#define _CRT_SECURE_NO_WARNINGS 
#define M 3
//#define DEBUG
#pragma warning(disable : 4996) 
using namespace std;
void screen()
{
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
    Data in;

    FILE* f1;
    f1 = fopen("t.txt", "w");
    if (f1 == NULL) {
        puts("Ошибка открытия файла");
        exit(0);
    }
    else {
        for (int i = 0; i < M; i++)
        {
            printf("Введите: название, группу, место обитания, численность > ");
            scanf("%s", in.firstValue);
            scanf("%s", in.secondValue);
            scanf("%s", in.thirdValue);
            scanf("%s", in.fourthValue);

            int firstLength = 0;
            int secondLength = 0;
            int thirdLength = 0;
            int fourthLength = 0;
            //длинна 

            for (size_t i = 0; i < 20; i++)
            {
                if (in.firstValue[i] == NULL)
                {
                    break;
                }
                firstLength++;
            }
            for (size_t i = 0; i < 2; i++)
            {
                if (in.secondValue[i] == NULL)
                {
                    break;
                }
                secondLength++;
            }
            for (size_t i = 0; i < 20; i++)
            {
                if (in.thirdValue[i] == NULL)
                {
                    break;
                }
                thirdLength++;
            }
            for (size_t i = 0; i < 5; i++)
            {
                if (in.fourthValue[i] == NULL)
                {
                    break;
                }
                fourthLength++;
            }

            fwrite(in.firstValue, 1, firstLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.secondValue, 1, secondLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.thirdValue, 1, thirdLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.fourthValue, 1, fourthLength, f1);
            fwrite("\n", 1, 1, f1);
        }
    }
    fclose(f1);

#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
}
void random() {
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 

    Data in;
    FILE* f1;
    f1 = fopen("t.txt", "w");
    if (f1 != NULL) {
        char m_name[3][10] = { "Gnu", "Baza", "Jaran" };
        char m_arial[3][10] = { "Asia", "Asia", "Africa" };
        char letters[3][2] = { "A", "B" ,"H" };

        char population[3][10] = { "4213","5018","9032" };
        for (int i = 0; i < M; i++)
        {

            strcpy(in.firstValue, m_name[rand() % 3]);

            strcpy(in.secondValue, letters[rand() % 3]);

            strcpy(in.thirdValue, m_arial[rand() % 3]);

            strcpy(in.fourthValue, population[rand() % 3]);

            int firstLength = 0;
            int secondLength = 0;
            int thirdLength = 0;
            int fourthLength = 0;

            for (size_t i = 0; i < 20; i++)
            {
                if (in.firstValue[i] == NULL)
                {
                    break;
                }
                firstLength++;
            }
            for (size_t i = 0; i < 2; i++)
            {
                if (in.secondValue[i] == NULL)
                {
                    break;
                }
                secondLength++;
            }
            for (size_t i = 0; i < 20; i++)
            {
                if (in.thirdValue[i] == NULL)
                {
                    break;
                }
                thirdLength++;
            }
            for (size_t i = 0; i < 5; i++)
            {
                if (in.fourthValue[i] == NULL)
                {
                    break;
                }
                fourthLength++;
            }

            fwrite(in.firstValue, 1, firstLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.secondValue, 1, secondLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.thirdValue, 1, thirdLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.fourthValue, 1, fourthLength, f1);
            fwrite("\n", 1, 1, f1);
        }
    }
    fclose(f1);
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
}
void print() {
    Data in;
    FILE* f1;
    f1 = fopen("t.txt", "r");
    if (f1 != NULL) {
        for (int i = 0; i < M; i++) {
            fscanf(f1, "%s", in.firstValue);
            printf("%s ", in.firstValue);
            fscanf(f1, "%s", in.secondValue);
            printf("%s ", in.secondValue);
            fscanf(f1, "%s", in.thirdValue);
            printf("%s ", in.thirdValue);
            fscanf(f1, "%s", in.fourthValue);
            printf("%s ", in.fourthValue);

            printf("\n");

        }
    }
    fclose(f1);
}
void start() {
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 

    Data in;
    FILE* f1;
    f1 = fopen("t.txt", "r+");
    if (f1 != NULL) {
        char m_name[3][10] = { "Gnu", "Baza", "Jaran" };
        char m_arial[3][10] = { "Asia", "Asia", "Africa" };
        char letters[3][2] = { "A", "B" ,"H" };
        char population[3][10] = { "4213","5018","9032" };
        for (int i = 0; i < M; i++)
        {

            strcpy(in.firstValue, m_name[rand() % 3]);

            strcpy(in.secondValue, letters[rand() % 3]);

            strcpy(in.thirdValue, m_arial[rand() % 3]);

            strcpy(in.fourthValue, population[rand() % 3]);

            int firstLength = 0;
            int secondLength = 0;
            int thirdLength = 0;
            int fourthLength = 0;

            for (size_t i = 0; i < 20; i++)
            {
                if (in.firstValue[i] == NULL)
                {
                    break;
                }
                firstLength++;
            }
            for (size_t i = 0; i < 2; i++)
            {
                if (in.secondValue[i] == NULL)
                {
                    break;
                }
                secondLength++;
            }
            for (size_t i = 0; i < 20; i++)
            {
                if (in.thirdValue[i] == NULL)
                {
                    break;
                }
                thirdLength++;
            }
            for (size_t i = 0; i < 5; i++)
            {
                if (in.fourthValue[i] == NULL)
                {
                    break;
                }
                fourthLength++;
            }

            fwrite(in.firstValue, 1, firstLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.secondValue, 1, secondLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.thirdValue, 1, thirdLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.fourthValue, 1, fourthLength, f1);
            fwrite("\n", 1, 1, f1);
        }
    }
    fclose(f1);
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
}
void end() {
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
    Data in;
    FILE* f1;
    f1 = fopen("t.txt", "a+");
    if (f1 != NULL) {
        char m_name[3][10] = { "Gnu", "Baza", "Jaran" };
        char m_arial[3][10] = { "Asia", "Asia", "Africa" };
        char letters[3][2] = { "A", "B" ,"H" };
        char population[3][10] = { "4213","5018","9032" };
        for (int i = 0; i < M; i++)
        {

            strcpy(in.firstValue, m_name[rand() % 3]);

            strcpy(in.secondValue, letters[rand() % 3]);

            strcpy(in.thirdValue, m_arial[rand() % 3]);

            strcpy(in.fourthValue, population[rand() % 3]);

            int firstLength = 0;
            int secondLength = 0;
            int thirdLength = 0;
            int fourthLength = 0;

            for (size_t i = 0; i < 20; i++)
            {
                if (in.firstValue[i] == NULL)
                {
                    break;
                }
                firstLength++;
            }
            for (size_t i = 0; i < 2; i++)
            {
                if (in.secondValue[i] == NULL)
                {
                    break;
                }
                secondLength++;
            }
            for (size_t i = 0; i < 20; i++)
            {
                if (in.thirdValue[i] == NULL)
                {
                    break;
                }
                thirdLength++;
            }
            for (size_t i = 0; i < 5; i++)
            {
                if (in.fourthValue[i] == NULL)
                {
                    break;
                }
                fourthLength++;
            }

            fwrite(in.firstValue, 1, firstLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.secondValue, 1, secondLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.thirdValue, 1, thirdLength, f1);
            fwrite(" ", 1, 1, f1);
            fwrite(in.fourthValue, 1, fourthLength, f1);
            fwrite("\n", 1, 1, f1);
        }
    }
    fclose(f1);
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
}
void num() {
    Data in;
    FILE* f1;

    cout << "Введите, какую запись распечатаем:" << endl;
    cout << "(1)Названия" << endl;
    cout << "(2)Группу" << endl;
    cout << "(3)Место обитания" << endl;
    cout << "(4)Численность" << endl;
    int otvet;
    cin >> otvet;
    if (otvet == 1) {
        f1 = fopen("t.txt", "r+");
        if (f1 != NULL) {

            while (fscanf(f1, "%s", in.firstValue) != EOF) {

                printf("%s ", in.firstValue);
                fscanf(f1, "%s", in.secondValue);
                fscanf(f1, "%s", in.thirdValue);

                fscanf(f1, "%s", in.fourthValue);


                printf("\n");

            }
        }
        fclose(f1);
    }
    else if (otvet == 2) {
        f1 = fopen("t.txt", "r+");
        if (f1 != NULL) {

            while (fscanf(f1, "%s", in.firstValue) != EOF) {

                fscanf(f1, "%s", in.secondValue);

                printf("%s ", in.secondValue);
                fscanf(f1, "%s", in.thirdValue);

                fscanf(f1, "%s", in.fourthValue);


                printf("\n");

            }
        }
        fclose(f1);
    }
    else if (otvet == 3) {
        f1 = fopen("t.txt", "r+");
        if (f1 != NULL) {

            while (fscanf(f1, "%s", in.firstValue) != EOF) {

                fscanf(f1, "%s", in.secondValue);


                fscanf(f1, "%s", in.thirdValue);
                printf("%s ", in.thirdValue);
                fscanf(f1, "%s", in.fourthValue);


                printf("\n");

            }
        }
        fclose(f1);
    }
    else if (otvet == 4) {
        f1 = fopen("t.txt", "r+");
        if (f1 != NULL) {

            while (fscanf(f1, "%s", in.firstValue) != EOF) {

                fscanf(f1, "%s", in.secondValue);


                fscanf(f1, "%s", in.thirdValue);

                fscanf(f1, "%s", in.fourthValue);

                printf("%s ", in.fourthValue);
                printf("\n");

            }
        }
        fclose(f1);
    }
    else if (otvet > 4 || otvet < 1) {
        cout << "Такого действия нет" << endl;
    }
}
void print2() {
    Data in;
    FILE* f1;
    f1 = fopen("t.txt", "r");
    if (f1 != NULL) {
        while (fscanf(f1, "%s", in.firstValue) != EOF) {
            printf("%s ", in.firstValue);
            fscanf(f1, "%s", in.secondValue);

            printf("%s ", in.secondValue);
            fscanf(f1, "%s", in.thirdValue);
            printf("%s ", in.thirdValue);
            fscanf(f1, "%s", in.fourthValue);
            printf("%s ", in.fourthValue);

            printf("\n");

        }
    }
    fclose(f1);
}
void osn()
{
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int choice = 0;
    int n = 3;
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "(1)Ввод с экрана и запись в файл" << endl;//d 
        cout << "(2)Ввод случайно и запись в файл" << endl;//d 
        cout << "(3)Добавить запись в начало файла" << endl;//d 
        cout << "(4)Добавить запись в конец файла" << endl;//d 
        cout << "(5)Печать одной из записи файла по номеру" << endl;//d 
        cout << "(6)Чтение всех структур последовательно из файла и печать" << endl;
        cout << "(7)Выход" << endl;
        cin >> choice;
        if (choice == 1) {
            screen();
            print();
        }
        else if (choice == 2) {
            random();
            print();
        }
        else if (choice == 3) {
            cout << "Файл заполняется случайным способом" << endl;
            start();
            print();
        }
        else if (choice == 4) {
            cout << "Файл заполняется случайным способом" << endl;
            end();
            print();

        }
        else if (choice == 5) {
            num();
        }
        else if (choice == 6) {

            print2();
        }
        else if (choice == 7) {

            exit(0);
        }
        else if (choice > 7) {
            cout << "Такого действия нет, попробуйте еще" << endl;
            cin >> choice;
        }

    }
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
}