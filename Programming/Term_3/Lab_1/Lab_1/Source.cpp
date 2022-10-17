#include "Header.h"
 
Student::Student() {
    Name = "Ivanov";
    initial = "N";
    initial2 = "M";
    birthdate = rand() % 31;
    birthmonth = rand() % 12;
    birthyear = rand() % 2000;
    address = "team.work@gmail.com";
    course = rand()%5;
    fakultat = 'CS';
    tel_num = rand() % 1000 + 1000000;
}
void random(Student students[]) {

   const char* Names[3] = { "Ivanov", "Sidorov", "Matchenko" };
   const char* initials[6] = {"I", "M", "S", "N", "R", "K"};
    const char* addresses[5] = { "team.work", "start", "my.post", "p.add", "work_post"};
    const char* fakultats[3] = { "CS","MI","NS"};
    for (int i = 0; i < M; i++) {
        students[i].Name = Names[rand() % 3];
        students[i].initial = initials[rand() % 6];
        students[i].initial2 = initials[rand() % 6];
        students[i].birthdate = rand() % (31 - 1 + 1) + 1;
        students[i].birthmonth = rand() % (12 - 1 + 1) + 1;
        students[i].birthyear = rand() % (2005 - 1998 + 1) + 1998;
        students[i].address = addresses[rand() % 5];
        students[i].fakultat = fakultats[rand() % 3];
        students[i].course = rand() % (5 - 1 + 1) + 1;
        students[i].tel_num =  rand() % 1000 + 1000000;
        students[i].FullName.insert(students[i].FullName.size(), students[i].Name);
        students[i].FullName.insert(students[i].FullName.size(), " ");
        students[i].FullName.insert(students[i].FullName.size(), students[i].initial);
        students[i].FullName.insert(students[i].FullName.size(), ".");
        students[i].FullName.insert(students[i].FullName.size(), students[i].initial2);
        students[i].FullName.insert(students[i].FullName.size(), ".");
    }
    
    
}
//void PrintFakultet(Student students[]) {
//    cout << "Студенти с средним балом меньше 70: " << endl;
//    int count = 0;
//    for (int i = 0; i < M; ++i) {
//        strcpy(get, students[i].fakultat);
//    }
//    if (count == 0)
//        cout << "Студентов со средним балом меньше 70 нету." << endl;
//}
void individum(Student students[])
{
    int  z = 0;
    //int n;
    for (int i = 0; i < M; i++)
    {
        if (students[i].birthyear > 2004) {
            cout << students[i].FullName << setw(6);

            cout << students[i].birthdate << "." << students[i].birthmonth << "." << students[i].birthyear << "  ";

            cout << students[i].address << "@gmail.com" << " ";
            cout << students[i].fakultat << " ";
            cout << students[i].course << " ";
            cout << "+380" << students[i].tel_num << " ";
            cout << endl;
            /*for (int j = 0; j < 5; j++)
                cout << setw(4) << " " << gr[i].ses[j];*/
            z++;
        }
    }
    if (z == 0)
    {
        cout << endl << "По данному предмету нет студентов с баллом выше 4.5" << endl;
    }
    //return 0;
}
void print_obj(Student students[]) {

    for (int i = 0; i < M; i++) {
        cout << students[i].FullName << setw(6);

        cout  << students[i].birthdate << "." << students[i].birthmonth << "." << students[i].birthyear << "  ";

        cout << students[i].address << "@gmail.com" << " ";
        cout << students[i].fakultat << " ";
        cout << students[i].course << " ";
        cout << "+380" << students[i].tel_num << " ";
        cout << endl;
    }
}