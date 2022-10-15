#include "Header.h"
 
Student::Student() {
    FullName = "Ivanov Ivan Ivanovich";
    birthdate = rand() % 31;//
    address = "team.work@gmail.com";
    course = rand()%5;
    fakultat = 'CS';
    tel_num = rand() % 1000 + 1000000;
}
void random(Student students[]) {
    const char* FullNames[3] = { "Ivanov Ivan Ivanovich", "Sidorov Semen Sergiivich", "Matchenko Maryna Myhailovna" };

    const char* addresses[3] = { "team.work@gmail.com", "start@gmail.com", "my.post@gmail.com" };
    const char* fakultats[3] = { "CS","MI","NS"};
    for (int i = 0; i < M; i++) {
        students[i].FullName = FullNames[rand() % 3];
        students[i].address = addresses[rand() % 3];
        students[i].fakultat = fakultats[rand() % 3];
        students[i].course = rand() % 5;
        students[i].tel_num = rand() % 1000 + 1000000;
    }
}
void Student::print_tabl()const {
    cout << setw(4) << "-----------------------------------------------\n";
    cout << setw(4) << "|             Некоторые виды антилоп          |\n";
    cout << setw(4) << "|---------------------------------------------|\n";
    cout << setw(4) << "|  Название  | Группа |   Ареал   |Численность|\n";
    cout << setw(4) << "|---------------------------------------------|\n";
}
void print_obj(Student students[]) {

    for (int i = 0; i < M; i++) {
        cout << "|" << setw(10) << students[i].FullName << setw(4);
        cout << "|" << setw(4) << students[i].address << setw(4);
        cout << "|" << setw(6) << students[i].fakultat << setw(6);
        cout << "|" << setw(3) << students[i].course << setw(6);
        cout << "|" << setw(4) << "+380" << students[i].tel_num << setw(4);
        cout << "|\n";
        cout << "|---------------------------------------------|" << "\n";
    }
}