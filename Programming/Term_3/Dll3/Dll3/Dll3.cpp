#include "pch.h"
#include "Dll3.h"

void Osn::main()
{
    while (true) {
        int a;

        int size = 1000;
        Uchen** List = new  Uchen * [size];
        cout << "Enter the length of list:" << endl;
        cin >> size;

        creating(List, size);

        while (true) {
            cout << "\tChoose operation that you need:" << endl;
            cout << "\tShow the list of students - 1" << endl;
            cout << "\tShow the list of students, that was born in choosen year - 2" << endl;
            cout << "\tShow the list of students, that studying in choosen place - 3" << endl;
            cout << "\tChange person to another(random) person - 4" << endl;
            cout << "\tDelete choosen person - 5" << endl;
            cout << "\tAdd new person - 6" << endl;
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
                printplace(List, size);
                system("pause");
                break;
            }
            case 4: {


                edit(List, size);

                system("pause");
                break;
            }
            case 5: {

                del(List, size);
                system("pause");

                break;
            }
            case 6: {

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

void Osn::creating(Uchen** List, int size)
{
    for (size_t i = 0; i < size; i++) {
        int Nrand = rand() % 4 + 1;
        if (Nrand == 1)
            List[i] = new Student;
        else if (Nrand == 2)
            List[i] = new MSchool;
        else if (Nrand == 3)
            List[i] = new HSchool;
        else if (Nrand == 4)
            List[i] = new Collage;


    }
    for (size_t i = 0; i < size; i++) List[i]->SetAll();
}

void Osn::print(Uchen** List, int size) {
    cout << "\n -----------------------------------------------------------------------------\n";
    cout << "| N " << "|" << setw(15) << "Name" << setw(1) << "| " << setw(9) << "Birthdate" << setw(1) << "|" << setw(3) << "F/C" << setw(1) << "|" << setw(2) << "NC" << setw(1) << "|" << setw(11) << "Tel-number" << setw(1) << "|" << setw(16) << "E-mail" << setw(1) << "|" << setw(10) << "Stud.place" << setw(1) << "|";
    cout << "\n -----------------------------------------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << "|" << setw(3) << i + 1 << setw(1);
        List[i]->ShowAll();
    }
}

void Osn::edit(Uchen** List, int& size)
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
    Uchen** NewList = new Uchen * [1000];
    int Nrand = rand() % 4 + 1;

    for (size_t i = 0; i < size; i++) {
        if (criteriaIndex != i) {
            NewList[i] = List[i];
        }
        else
        {
            if (Nrand == 1)
                NewList[i] = new Student;
            else if (Nrand == 2)
                NewList[i] = new HSchool;
            else if (Nrand == 3)
                NewList[i] = new MSchool;
            else if (Nrand == 4)
                NewList[i] = new Collage;

            NewList[i]->SetAll();
        }
    }

    for (size_t i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;
}

void Osn::printplace(Uchen** List, int size) {
    string get;
    print(List, size);
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "People of what place of study do you need?" << endl;
    cout << "Choose the place: " << endl;
    cin >> get;
    int count = 0;

    for (int i = 0; i < size; i++) {

    }
    for (int i = 0; i < size; ++i) {

        if (!List[i]->getPlace().compare(get)) {
            cout << "|" << setw(3) << i + 1 << setw(1);
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
        if (!List[i]->getBirthyear().compare(get)) {
            cout << "|" << setw(3) << i + 1 << setw(1);
            List[i]->ShowAll();
            z++;
        }

    }
    if (z == 0)
    {
        cout << endl << "There are no students/pupils, that was born after choosen year" << endl;

    }
}

void Osn::del(Uchen** List, int& size) {
    int criteriaIndex;
    cout << "Input number of student that you want to delete" << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    Uchen** NewList = new Uchen * [1000];

    for (size_t i = 0, j = 0; i < size; i++)
        if (criteriaIndex != i) {
            NewList[j] = List[i]; j++;
        }

    size--;
    for (size_t i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;

}

void Osn::add(Uchen** List, int& size) {
    int criteriaIndex;
    cout << "Input number of place, where you want to add new student " << endl;
    cin >> criteriaIndex;
    criteriaIndex--;
    Uchen** NewList = new Uchen * [1000];
    int Nrand = rand() % 4 + 1;

    for (size_t i = 0, j = 0; i < size;) {
        if (criteriaIndex != j) {
            NewList[j] = List[i]; j++;
            i++;
        }
        else
        {
            if (Nrand == 1)
                NewList[j] = new Student;
            else if (Nrand == 2)
                NewList[j] = new HSchool;
            else if (Nrand == 3)
                NewList[j] = new MSchool;
            else if (Nrand == 4)
                NewList[j] = new Collage;


            NewList[j]->SetAll();
            j++;
        }
    }

    size++;
    for (size_t i = 0; i < size; i++) List[i] = NewList[i];

    delete[] NewList; NewList = NULL;
}
CUMTROL_API void cun() {
    srand(time(NULL));
    Osn main;
    main.main();
}