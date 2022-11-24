#include "Header.h"
#pragma warning(disable  : 4996)

void Osn::main()
{
    while (true) {
        int a;

        int size = 1000;
        Student** List = new  Student *[size];
        cout << "Enter the length of list:" << endl;
        cin >> size;

        creating(List, size);

        while (true) {
            cout << "\tChoose operation that you need:" << endl;
            cout << "\tShow the list of students - 1" << endl;
            cout << "\tShow the list of students, that was born in choosen year - 2" << endl;
            cout << "\tChange person to another(random) person - 3" << endl;
            cout << "\tDelete choosen person - 4" << endl;
            cout << "\tAdd new person - 5" << endl;
            cout << "\tExit - 0" << endl;
            cin >> a;

            switch (a)
            {

            case 1:
            {
                print(List, size);
                system("pause");

                break;
            }
            case 2:
            {
                individum(List, size);


                system("pause");
                break;
            }
            case 3: {


                edit(List, size);

                system("pause");
                break;
            }
            case 4: {

                del(List, size);
                system("pause");

                break;
            }
            case 5: {

                add(List, size);
                system("pause");

                break;
            }
            case 0: {
                system("cls");
                exit(0);
                break;
            }

            default:
                system("cls");
                cout << " \t\t\tERROR " << endl;
                break;
            }
        }
        delete[] List;
    }
}
//сеттеры
void Student::SetAll(string FullName, string birthdate, string address, string course, string FacultyName,string phonenumber, string place) {
    this->Name = dataNames[rand() % 27];
    this->SecondName = dataSecondNames[rand() % 39];
    this->FullName += Name + " " + SecondName;
    this->birthdate.setterBirthdate(birthdate);
    this->address = Name + "@gmail.com";
    this->course = to_string(rand() % (5 - 1 + 1) + 1);
    this->faculty.setterFacultyName(FacultyName);
    this->phonenumber = "+380" + (to_string(rand() % 1000 + 1000000));
    this->place = "Univercity";
}
//геттеры
string Student::getPlace() { return place; }
string Student::getFullName() { return FullName; }
string Student::getPhonenumber() { return phonenumber; }
string Student::getterCourse() { return course; }
string Student::getAddress() { return address; }
string Student::getterBirthdate() { return birthdate.getterBirthdate(); }
string Student::getterBirthyear() { return birthdate.getterBirthyear(); }
string Student::getterFucName() { return faculty.getterFucName(); }
//show
void Student::ShowAll() {

    cout << "|" << setw(15) << this->getFullName() << setw(1) << "|" << setw(10) << this->getterBirthdate() << setw(1);
    cout << "|" << setw(3) << this->faculty.getterFucName() << setw(1);
    cout << "|" << setw(2) << this->getterCourse() << setw(1);
    cout << "|" << setw(11) << this->getPhonenumber() << setw(1);
    cout << "|" << setw(16) << this->getAddress() << setw(1);
    cout << "|" << setw(10) << this->getPlace() << setw(1) << "|";
    cout << endl;


}


// List[i]->getterBirthdate(),

void Osn::creating(Student** List, int size)
{
    for (size_t i = 0; i < size; i++) {
        int Nrand = rand() % 1 + 1;
        if (Nrand == 1)
            List[i] = new Student;
    }
    for (size_t i = 0; i < size; i++) {
        List[i]->SetAll(List[i]->getFullName(), List[i]->getterBirthdate(), List[i]->getterFucName(), List[i]->getAddress(), List[i]->getterCourse(), List[i]->getPlace(), List[i]->getPhonenumber());
    }
}

void Osn::print(Student** List, int size) {
    cout << "\n -----------------------------------------------------------------------------\n";
    cout << "| N " << "|" << setw(15) << "Name" << setw(1) << "| " << setw(9) << "Birthdate" << setw(1) << "|" << setw(3) << "F/C" << setw(1) << "|" << setw(2) << "NC" << setw(1) << "|" << setw(11) << "Tel-number" << setw(1) << "|" << setw(16) << "E-mail" << setw(1) << "|" << setw(10) << "Stud.place" << setw(1) << "|";
    cout << "\n -----------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << "|" << setw(3) << i + 1 << setw(1);
        List[i]->ShowAll();
    }
}

void Osn::edit(Student** List, int& size)
{
    int criteriaIndex;
    cout << "Input number of student/pupil which you want to change " << endl;
    cout << "\t\t\t~REMINDER~" << endl;
    cout << "Replacement is random, so you can`t influenced anything, exept number in list" << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    if (criteriaIndex < 0 or criteriaIndex > size) {
        cout << "\t\t\tError!\n"; return;
    }
    Student** NewList = new Student * [1000];
    int Nrand = rand() % 1 + 1;

    for (size_t i = 0; i < size; i++) {
        if (criteriaIndex != i) {
            NewList[i] = List[i];
        }
        else
        {
            if (Nrand == 1)
                NewList[i] = new Student;

            NewList[i]->SetAll(List[i]->getFullName(), List[i]->getPhonenumber(), List[i]->getterBirthdate(), List[i]->getPlace(), List[i]->getterCourse(), List[i]->getterFucName(), List[i]->getAddress());
            
        }
    }

    for (size_t i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;
}



void Osn::individum(Student** List, int size) {
    print(List, size);
    char get[5];
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Choose the year: " << endl;
    cin >> get;
    cout << "List of students, that was born in choosen year" << endl;
    int  z = 0;
    for (int i = 0; i < size; ++i)
    {
        if (!List[i]->getterBirthdate().compare(get)) {
            cout << "|" << setw(3) << i + 1 << setw(1);
            List[i]->ShowAll();
            z++;
        }

    }
    if (z == 0)
    {
        cout << endl << "There are no students/pupils, that was born in choosen year" << endl;

    }
}

void Osn::del(Student** List, int& size) {
    int criteriaIndex;
    cout << "Input number of student that you want to delete" << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    Student** NewList = new Student * [1000];

    for (size_t i = 0, j = 0; i < size; i++)
        if (criteriaIndex != i) {
            NewList[j] = List[i]; j++;
        }

    size--;
    for (size_t i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;

}
//List[i]->getFullName(), List[i]->getPhonenumber(), List[i]->getPlace(), List[i]->getPlace(), List[i]->getterCourse(), List[i]->getAddress()
void Osn::add(Student** List, int& size) {
    int criteriaIndex;
    cout << "Input number of place, where you want to add new student " << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    Student** NewList = new Student * [1000];
    int Nrand = rand() % 1 + 1;

    for (size_t i = 0, j = 0; i < size;) {
        if (criteriaIndex != j) {
            NewList[j] = List[i]; j++;
            i++;
        }
        else
        {
            if (Nrand == 1)
                NewList[j] = new Student;


            NewList[j]->SetAll(List[i]->getFullName(), List[i]->getPhonenumber(), List[i]->getterBirthdate(), List[i]->getPlace(), List[i]->getterCourse(), List[i]->getterFucName(), List[i]->getAddress());
            j++;
        }
    }

    size++;
    for (size_t i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;
}