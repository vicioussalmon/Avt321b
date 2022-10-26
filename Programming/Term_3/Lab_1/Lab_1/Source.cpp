#include "Header.h"
 
Student::Student() {
    Name = "Ivanov";
    initial = "N";
    initial2 = "M";
    birthdate = rand() % (31 - 1 + 1) + 1;
    birthmonth = rand() % (12 - 1 + 1) + 1;
    birthyear = rand() % (2005 - 1998 + 1) + 1998;
    address = "team.work@gmail.com";
    course = rand() % (5 - 1 + 1) + 1;
    fakultat = "CS";
    tel_num = rand() % 1000 + 1000000;
}
void random(Student* &students, int n) {

   const char* Names[3] = { "Ivanov", "Sidorov", "Matchenko" };
   const char* initials[6] = {"I", "M", "S", "N", "R", "K"};
    const char* addresses[5] = { "team.work", "start", "my.post", "p.add", "work_post"};
    const char* fakultats[3] = { "CS","MI","NS"};
    for (int i = 0; i < n; i++) {
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
void PrintFakultet(Student* &students, int n) {
    char get[3];
    print_obj(students, n);
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Students of what faculty do you need?" << endl;
    cout << "We have three faculty, so please choose one of them: CS, MI, NS" << endl;
    cout << "Choose the faculty: " << endl;
    cin >> get;
    int count = 0;

    for (int i = 1; i < n; ++i) {
        char* c = const_cast<char*>(students[i].fakultat.c_str());
        
        if (strstr(get, c)) {
            cout << students[i].FullName << setw(6);

            cout << students[i].birthdate << "." << students[i].birthmonth << "." << students[i].birthyear << "  ";

            cout << students[i].address << "@gmail.com" << " ";
            cout << students[i].fakultat << " ";
            cout << students[i].course << " ";
            cout << "+380" << students[i].tel_num << " ";
            cout << endl;
            count++;
        }
        
    }
    if (count == 0) {
        cout << endl << "There are no students from choosen faculty..." << endl;
    }
    cout << "-----------------------------------------------------------------------------" << endl;
}
void individum(Student* &students, int n){
    print_obj(students, n);
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "List of students, that was born after 2004" << endl;
    int  z = 0;
    for (int i = 1; i < n; i++)
    {
        if (students[i].birthyear > 2004) {
            cout << students[i].FullName << setw(6);

            cout << students[i].birthdate << "." << students[i].birthmonth << "." << students[i].birthyear << "  ";

            cout << students[i].address << "@gmail.com" << " ";
            cout << students[i].fakultat << " ";
            cout << students[i].course << " ";
            cout << "+380" << students[i].tel_num << " ";
            cout << endl;
            z++;
        }
    }
    if (z == 0)
    {
        cout << endl << "There are no students, that was born after 2004" << endl;
    }
}
void print_obj(Student* &students, int &n) {
    for (int i = 0; i < n; i++) {
        cout << i+1<<". ";
        cout << students[i].FullName << setw(6);

        cout  << students[i].birthdate << "." << students[i].birthmonth << "." << students[i].birthyear << "  ";

        cout << students[i].address << "@gmail.com" << " ";
        cout << students[i].fakultat << " ";
        cout << students[i].course << " ";
        cout << "+380" << students[i].tel_num << " ";
        cout << endl;
    }
}

void del(Student*& students, int& n){
int criteriaIndex;
cout << "Input number of student that you want to delete" << endl;
cin >> criteriaIndex;
criteriaIndex--;
for (int i = 0; i < n; i++) {
    if (criteriaIndex == i) {
        criteriaIndex = i;
        break;
    }
}
Student* result = new Student[n-1];
for (int i = 0; i <= criteriaIndex; i++) {
    result[i] = students[i];
}
//копируем элементы со сдвигом на 1
for (int i = criteriaIndex; i <= n - 2; i++) {
    result[i] = students[i + 1];
}

for (int i = 0; i < n-1; i++) {
    cout << i+1 << ". ";
    cout << result[i].FullName << setw(6);
    cout << result[i].birthdate << "." << result[i].birthmonth << "." << result[i].birthyear << "  ";
    cout << result[i].address << "@gmail.com" << " ";
    cout << result[i].fakultat << " ";
    cout << result[i].course << " ";
    cout << "+380" << result[i].tel_num << " ";
    cout << endl;
    
}
delete[]students;
students = result;
n--;
}

void add(Student*& students, int& n) {
    int criteriaIndex;
    cout << "Input number of place, where you want to add new student " << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    //int newN = n + 1;
    for (int i = 0; i < n; i++) {
         if (criteriaIndex == i) {
            criteriaIndex = i;
            break;
        }
    }
    Student* result = new Student[n+1];
    for (int i = 0; i < criteriaIndex; i++) {
        result[i] = students[i];
        result[criteriaIndex] = students[1];
       
    }
    //копируем элементы со сдвигом на 1
    for (int i = criteriaIndex; i <= n; i++) {
         result[i] = students[i - 1];
    }
    for (int i = 0; i < n + 1; i++) {
        cout << i+1 << ". ";
        cout << result[i].FullName << setw(6);
        cout << result[i].birthdate << "." << result[i].birthmonth << "." << result[i].birthyear << "  ";
        cout << result[i].address << "@gmail.com" << " ";
        cout << result[i].fakultat << " ";
        cout << result[i].course << " ";
        cout << "+380" << result[i].tel_num << " ";
        cout << endl;
    }
    delete[]students;
    students = result;
    n++;

}
