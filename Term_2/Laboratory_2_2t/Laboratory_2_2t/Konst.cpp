#include <iostream> 
#include <string.h> 
#include <stdio.h> 
#include "Konst.h"
#define _CRT_SECURE_NO_WARNINGS 
#define M 5
#define DEBUG
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
#ifdef DEBUG
    cout<<__DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
    for (int n = 0; n < M; n++)
    {
        printf("%d. �������: ��������, ������, ����� ��������, ����������� >",
            n + 1);
        scanf("%s", mm[n].name, sizeof(mm[n].name));
        if (!strcmp(mm[n].name, "***")) break;
        scanf("%s", &mm[n].sc, sizeof(mm[n].sc));
        scanf("%s", &mm[n].cnt);
        scanf("%f", &mm[n].sq);
    }
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
}
void print(mon mm[]) {
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
    int n = M;
    int i, j;


    printf("-----------------------------------------------\n");
    printf("|         ��������� ���� �������              |\n");
    printf("|---------------------------------------------|\n");
    printf("| �������� | ������ |   �����  | �����������  |\n");
    printf("|          |        | �������� |  ���������   |\n");
    printf("|----------|--------|----------|--------------|\n");
    for (i = 0; i < n; i++)
    {
        printf("|%-10s|%-8c|%-10s|%-14.0lf|\n",
            mm[i].name, mm[i].sc, mm[i].cnt, mm[i].sq);
    }
    printf("|---------------------------------------------|\n");
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif

}
void sort(mon mm[]) {
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
    int m;
    int n = M;
    struct mon x;
    for (int i = 0; i < n - 1; i++) {
        m = i;/* ����������� ������� - ������ */
        for (int j = i + 1; j < n; j++)
            /* ���� ������� ������� > ������������, �� ���������� ����������� */
            if (strcmp(mm[m].name, mm[j].name) > 0) m = j;
        if (m > i) {
            //������������ 
            x = mm[i];
            mm[i] = mm[m];
            mm[m] = x;
        }
    }
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
}
void random(mon mm[]) {
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
    char m_name[3][10] = { "Gnu", "Baza", "Jaran" };
    char m_arial[3][10] = { "Asia", "Asia", "Africa" };
    char letters[3] = { 'A', 'B' ,'H' };
    for (int i = 0; i < M; i++)
    {
        strcpy_s(mm[i].name, m_name[i % 3]);
        strcpy_s(mm[i].cnt, m_arial[i % 3]);
        mm[i].sc = letters[i % 3];
        mm[i].sq = rand() % 557501;
    }
    mm[10] = mm[2];
    mm[2] = mm[0];
    mm[0] = mm[10];
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
}
void random_input()
{
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    int n = 3;
    float sqx;
    struct mon mm[10];
    while (true) {
        cout << "�������� �������� (������� ���������� �� 3 ����):" << endl;
        cout << "(1)��������� ������" << endl;
        cout << "(2)���������� �� ��������" << endl;
        cout << "(3)������" << endl;
        cin >> choice;
        if (choice == 1) {
            random(mm);//��� ����������� ����
        }

        else if (choice == 2) {
            sort(mm);//correct
        }
        else if (choice == 3) {

            print(mm);//��������
        }
        else if (choice > 3) {
            cout << "������ �������� ���, ���������� ���" << endl;
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
void user_input()
{
#ifdef DEBUG
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    int n = 3;
    float sqx;
    struct mon mm[10];
    while (true) {
        cout << "�������� �������� (������� ���������� �� 3 ����):" << endl;
        cout << "(1)��������� ������" << endl;
        cout << "(2)���������� �� ��������" << endl;
        cout << "(3)������" << endl;
        cin >> choice;
        if (choice == 1) {
            input(mm);//��� ����������� ����
        }

        else if (choice == 2) {
            sort(mm);//correct
        }
        else if (choice == 3) {

            print(mm);//��������
        }
        else if (choice > 3) {
            cout << "������ �������� ���, ���������� ���" << endl;
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