#include <iostream>
#include <string.h> 
#include <stdio.h> 
#include "Contents.h"
#define _CRT_SECURE_NO_WARNINGS 
#define CH
using namespace std;
void odn(int* A, int R, int C){
    cout << "����� ����������� �������:" << endl;
    for (int j = 0; j < C; j++) {
        for (int i = R - 1; i >= 0; i--)
            cout << *(A + i * C + j) << "\t";
        cout << endl;
    }
}
void dvu(int** A, int R, int C) {
    cout << "����� ����������� �������:" << endl;
    for (int j = 0; j < C; j++) {
        for (int i = R - 1; i >= 0; i--)
            cout << *(*(A + i) + j) << "\t";
        cout << endl;
    }
}
void osn(){
    while (true) {
        setlocale(LC_ALL, "Russian");
        cout << "������� ����������� �������:" << endl;
        int R;
        int C;
        cout << "������� ���������� �����:" << endl;
        cin >> R;
        cout << "������� ���������� ��������:" << endl;
        cin >> C;
#ifdef CH
        cout << "P����� � ���������� ��������, ��� � ���������" << endl;
        int* A = new int[R * C];
        int c = 0;
        cout << "����� ��������� �������:" << endl;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                *(A + i * C + j) = c++;
                cout << *(A + i * C + j) << "\t";
            }
            cout << endl;
        }
        odn(A, R, C);
        delete[]A;
        A = nullptr;
#else CH
        cout << "P����� � ��������� ��������, ��� � ���������" << endl;
        int** A = new int* [R];
        for (int i = 0; i < R; i++) {
            A[i] = new int[C];
        }
        cout << "����� ��������� �������:" << endl;//���������� � ������
        for (int i = 0; i < R; i++) {//���������� � ������
            for (int j = 0; j < C; j++) {
                *(*(A + i) + j) = rand() % 21;
                cout << *(*(A + i) + j) << "\t";
            }
            cout << endl;
        }
        dvu(A, R, C);
        for (int i = 0; i < N; i++) {
            delete[] * (A + i);//�������
    }
        delete[] A;//������
     A = nullptr;
#endif // CH
     }
}