#include <iostream> 
#include <string.h> 
#include <stdio.h> 
#define _CRT_SECURE_NO_WARNINGS 
#define M 5
#pragma warning(disable : 4996) 
using namespace std;
struct mon {
    char name[10];
    char sc;
    char cnt[8];
    float sq;
    int mm[8];
};
void input(mon mm[]) {
    for (int n = 0; n < M; n++)
    {
        printf("%d. Введите: название, группу, место обитания, численность >",
            n + 1);
        scanf("%s", mm[n].name, sizeof(mm[n].name));
        if (!strcmp(mm[n].name, "***")) break;
        scanf("%s", &mm[n].sc, sizeof(mm[n].sc));
        scanf("%s", mm[n].cnt);
        scanf("%f", &mm[n].sq);
    }
}
void print(mon mm[]) {

    int n = M;
    int i, j;


    printf("-----------------------------------------------\n");
    printf("|         Некоторые виды антилоп              |\n");
    printf("|---------------------------------------------|\n");
    printf("| Название | Группа |   Место  | Численность  |\n");
    printf("|          |        | обитания |  популяции   |\n");
    printf("|----------|--------|----------|--------------|\n");
    for ( i = 0; i < n; i++)
    {
        printf("|%-10s|%-8c|%-10s|%-14.0lf|\n",
            mm[i].name, mm[i].sc, mm[i].cnt, mm[i].sq);
    }
    printf("|---------------------------------------------|\n");


}
void sort(mon mm[]) {
    int m;
    int n = M;
    struct mon x;
    for (int i = 0; i < n - 1; i++) {
        m = i;/* минимальный элемент - первый */
        for (int j = i + 1; j < n; j++)
            /* если текущий элемент > минимального, он становится минимальным */
            if (strcmp(mm[m].name, mm[j].name) > 0) m = j;
        if (m > i) {
            //перестановка 
            x = mm[i];
            mm[i] = mm[m];
            mm[m] = x;
        }
    }
}
void random(mon mm[]) {
    for (int n = 0; n < M; n++) {
        printf("%d. Введите название>", n + 1);
        scanf_s("%s", mm[n].name, sizeof(mm[n].name));
    }
    for (int n = 0; n < M; n++) {
        printf("%d. Введите ариал>", n + 1);
        scanf_s("%s", mm[n].cnt, sizeof(mm[n].cnt));
    }
    char letters[3] = { 'A', 'B' ,'H' };
    for (int i = 0; i < 3; i++)
    {
        mm[i].sc = letters[i % 3];
        mm[i].sq = rand() % 557501;
    }
    mm[10] = mm[2];
    mm[2] = mm[0];
    mm[0] = mm[10];

}
int main(void)
{
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    int n = 3;
    float sqx;
    struct mon mm[10];
    while (true) {
        cout << "Выберите операцию (Таблица рассчитана на 3 вида):" << endl;
        cout << "(1)Заполнение рандомно" << endl;
        cout << "(2)Ручной ввод" << endl;
        cout << "(3)Сортировка по алфавиту" << endl;
        cout << "(4)Печать" << endl;
        cin >> choice;
        if (choice == 1) {
            random(mm);//как швейцарские часы
        }
        else if (choice == 2) {
            input(mm);
        }
        else if (choice == 3) {
            sort(mm);//correct
        }
        else if (choice == 4) {
 
            print(mm);//исправно
        }
        else if (choice > 4) {
            cout << "Такого действия нет, попробуйте еще" << endl;
            cin >> choice;
        }

    }
    
}

