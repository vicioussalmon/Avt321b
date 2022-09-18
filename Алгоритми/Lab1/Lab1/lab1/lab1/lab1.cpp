#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

string recoding(char* input_cod, char* output_cod, string txt) { //������� �������������
    for (int i = 0; i < txt.length(); i++) { //������ � ����������� ��������� �������� �� ������ � ����� �� ���������� ������� � ������ ���������
        for (int j = 0; input_cod[j] != '\0'; j++) {
            if (txt[i] == input_cod[j]) {
                txt[i] = output_cod[j];
            }
        }

    }
    return txt;
}

void error() { //��������� �� ������
    cout << endl;
    cout << "������ ������� �����������. ���������� ��� ���!\n\n";
    cin.clear(); // ������ ������
}

int main()
{
    setlocale(LC_ALL, "RU");

    int num_of_cod; //����� �������� ���������
    int num_of_cod2;//����� �������� ���������

    char* pointer_cod_1 = NULL; //��������� �� �������� ��������� (���������� � ����������� �� ��������� ���������)
    char* pointer_cod_2 = NULL; //��������� �� �������� ��������� (���������� � ����������� �� ��������� ���������)

    //������� � ��������� ������ ���������
    char win1251[] = "�������������������������������������Ũ��������������������������";
    char koi8r[] = "�����Ÿ����������������������������������������������������������";
    char macintosh[] = "��������������������������������߀�����݆������������������������";


    while (true) { //���� ������ ����� ������� �� ���������, ���� ����� ��������� �������
        cout << "�������� �������� ��������� ������ ������:" << endl;
        cout << "1. win1251" << endl;
        cout << "2. koi8r" << endl;
        cout << "3. macintosh" << endl;
        cout << "������� ����� ����� (1,2,3): ";

        cin >> num_of_cod; //����� �������� ���������

        if (num_of_cod != 1 && num_of_cod != 2 && num_of_cod != 3) {
            error(); //���� ���� ������ ������������ - �������� ������ � ����������� ������
        }
        else break;
    }

    while (true) { //���� ������ ����� ������� �� ���������, ���� ����� ��������� �������
        cout << "�������� ��������� ��������� ������: ";

        cin >> num_of_cod2; //����� �������� ���������

        if (num_of_cod2 != 1 && num_of_cod2 != 2 && num_of_cod2 != 3) { //�������� �� ������������ ������ ��������� �� ����
            error();
        }
        else break;
        if (num_of_cod == num_of_cod2) //�������� �� ���������� �������� � �������� ���������
        {
            cout << "��������� ��������� � ��������� ������ ���������. ����������, �������� ������.";
            error();
        }
        else break;
    }

    switch (num_of_cod) { //�������� �������� ��������� �� ��������� �������� ���������
    case 1:
        pointer_cod_1 = win1251; break;
    case 2:
        pointer_cod_1 = koi8r; break;
    case 3:
        pointer_cod_1 = macintosh; break;
    }

    switch (num_of_cod2) { //�������� �������� ��������� �� ��������� �������� ���������
    case 1:
        pointer_cod_2 = win1251; break;
    case 2:
        pointer_cod_2 = koi8r; break;
    case 3:
        pointer_cod_2 = macintosh; break;
    }

    string result, buffer;
    ifstream orig_file("Original.txt"); //������� �������� ����� (�������� ����� �� ������)
    ofstream res_file("Result.txt"); //�������� �������� ����� (�������� ����� �� ������)

    //���� while ����� ������� ���� �� ��������� �� ���� ��������
    while (getline(orig_file, buffer)) {  //��������� ���� ������
        result = recoding(pointer_cod_1, pointer_cod_2, buffer); //������������ ���� ������
        res_file << result + "\n"; //���������� � ���� ���� ������
    }

    orig_file.close();
    res_file.close();
}