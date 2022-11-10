#include "Header.h"

void Osn::creating(Uchen** List, int size)
{
    for (size_t i = 0; i < size; i++) {
        int Nrand = rand() % 2 + 1;
        if (Nrand == 1)
            List[i] = new Student;
        else if (Nrand == 2)
            List[i] = new School;

    }
    for (size_t i = 0; i < size; i++) List[i]->SetAll();
}

void Osn::print(Uchen** List, int size) {
    cout << "\n --------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "| N " << "|" << setw(15) << "Name" << setw(6) << "|" << setw(13) << "Birthdate" << setw(4) << "  |  " << setw(20) << "Faculty/Class" << setw(14) << "|" << setw(20) << "Course/Class" << setw(14) << "|" << setw(15) << "Telefon number" << setw(3) << "  |  " << setw(11) << "E-mail" << setw(5) << "  |" << setw(11) << "Place of study" << setw(5) << "  |";
    cout << "\n --------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << "|" << setw(3) << i + 1 << setw(1);
        List[i]->ShowAll();
    }
}

void Osn::edit(Uchen** List, int& size)
{
    int criteriaIndex;
    cout << "Input number of place, where you want to add new student " << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    if (criteriaIndex < 0 or criteriaIndex > size) {
        cout << "\t\t\tError!\n"; return;
    }
    Uchen** NewList = new Uchen * [1000];
    int Nrand = rand() % 2 + 1;

    for (int i = 0; i < size; i++) {
        if (criteriaIndex - 1 != i) {
            NewList[i] = List[i];
        }
        else
        {
            if (Nrand == 1)
                NewList[i] = new Student;
            else if (Nrand == 2)
                NewList[i] = new School;

            NewList[i]->SetAll();
        }
    }

    for (int i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;
}


void Osn::printplace(Uchen** List, int size) {
    char get[3];
    print(List, size);
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "People of what place of study do you need?" << endl;
    cout << "Choose the place: " << endl;
    cin >> get;
    int count = 0;

    for (int i = 0; i < size; ++i) {
        char* c = const_cast<char*>(List[i]->getplace().c_str());

        if (strstr(get, c)) {
            List[i]->ShowAll();
            count++;
        }

    }
    if (count == 0) {
        cout << endl << "There are no choosen person..." << endl;
    }
    cout << "-----------------------------------------------------------------------------" << endl;
}

void Osn::individum(Uchen** List, int size) {
    print(List, size);
    char get[5];
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "Choose the year: " << endl;
    cin >> get;
    cout << "List of students, that was born after choosen year" << endl;
    int  z = 0;
    for (int i = 0; i < size; ++i)
    {
 
            char* c = const_cast<char*>(List[i]->getBirthyear().c_str());

            if (strstr(get, c)) {
                List[i]->ShowAll();
                z++;
            }

    }
    if (z == 0)
    {
        cout << endl << "There are no students/pupils, that was born after choosen year" << endl;

    }
}

void Osn::del(Uchen** List, int &size) {
    int criteriaIndex;
    cout << "Input number of student that you want to delete" << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    if (criteriaIndex < 0 or criteriaIndex > size) {
        cout << "\t\t\tError!\n"; return;
    }
    Uchen** NewList = new Uchen * [1000];
    
    for (int i = 0; i < size; i++) {
        if (criteriaIndex == i) {
            criteriaIndex = i;
            break;
        }
    }

    for (int i = 0; i <= criteriaIndex; i++) {
        NewList[i] = List[i];
    }

    for (int i = criteriaIndex; i <= size - 2; i++) {
        NewList[i] = List[i + 1];
    }

    for (int i = 0; i < size - 1; i++) {
        cout << i + 1 << ". ";
        NewList[i]->ShowAll();

    }
    size--;
    for (int i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;
}

void Osn::add(Uchen** List, int &size) {
    int criteriaIndex;
    cout << "Input number of place, where you want to add new student " << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    
    if (criteriaIndex < 0 or criteriaIndex > size) {
        cout << "\t\t\tError!\n"; return;
    }
    Uchen** NewList = new Uchen * [1000];
    int Nrand = rand() % 2 + 1;

    for (int i = 0, j = 0; i < size;) {
        if (criteriaIndex - 1 != j) {
            NewList[j] = List[i]; j++;
            i++;
        }
        else
        {
            if (Nrand == 1)
                NewList[j] = new Student;
            else if (Nrand == 2)
                NewList[j] = new School;


            NewList[j]->SetAll();
            j++;
        }
    }

    size++;
    for (int i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;


}
