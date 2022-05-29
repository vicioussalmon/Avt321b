#include "Contents.h"
#include "Struct.h"
struct List* newsp()
{
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
    List* temp = new List;
    //List* tail = NULL;
    temp->next = NULL;
    char m_name[3] = { 'G', 'B', 'J' };
    char m_arial[3] = { 'A', 'A', 'F' };
    char letters[3] = { 'C', 'D' ,'H' };    
        temp->in.firstValue = m_name[rand() % 3];

        temp->in.secondValue = letters[rand() % 3];

        temp->in.thirdValue = m_arial[rand() % 3];

        temp->in.fourthValue = rand() % 20 + 1;

return temp;
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
}
void print(List* head) {
    List* print;
    cout << "---------------------------------------------" << endl;
    cout << "G = Gnu |J = Jaran|B = Baza" << endl;
    cout << "A = Asia|F = Africa" << endl;
    cout << "---------------------------------------------" << endl;
    print = head;
    while (print != NULL) {

        printf("%c ", print->in.firstValue);
        printf("%c ", print->in.secondValue);
        printf("%c ", print->in.thirdValue);
        printf("%f \n", print->in.fourthValue);
        print = print->next;

    }
}
void search(List* head) {
    List* poisk = head;
    cout << "Выберите позицию" << endl;
    int position;
    cin >> position;
    poisk = head;
    for (int i = 0; i < position - 1; i++)
    {
        poisk = poisk->next;
    }

    List* print = poisk;
    printf("%c ", print->in.firstValue);
    printf("%c ", print->in.secondValue);
    printf("%c ", print->in.thirdValue);
    printf("%f \n", print->in.fourthValue);
    print = print->next;
}
void ad(List*head, int el) {
        List* temp_pos = head;
        temp_pos = head;
        for (int i = 0; i < el - 1; i++)
        {
            temp_pos = temp_pos->next;
        }
        List* temp = new List;
        temp = newsp();
        temp->next = temp_pos->next; 
        temp_pos->next = temp; 
    
}
void del(List* head, int el) {
    List* temp_pos = head;
        temp_pos = head;
        for ( int i = 0; i < el - 1; i++)
        {
            temp_pos = temp_pos->next;
        }
        List* temp = temp_pos->next;
        if (temp->next == NULL)
            temp_pos->next = NULL;
        else
            temp_pos->next = temp->next;
        delete temp;
    
}
void sort(List* head) {
    List* sort = head;
    sort = head;
    List* left = head;
    List* right = head->next;
    List* temp = new List;
    while (left->next) {
        while (right) {
            if ((left->in.firstValue) > (right->in.firstValue)) {
                temp->in = left->in;
                left->in = right->in;
                right->in = temp->in;
            }
            right = right->next;
        }
        left = left->next;
        right = left->next;
    }
    sort = head;

}
void file(List* head) {
List* create = new List;
FILE* f;
fopen_s(&f, "fil.txt", "a");
if (f == NULL) {
    cout << "Ошибка откытия файла" << endl;
    exit(0);
}
else {
    char m_name[3] = { 'G', 'B', 'J' };
    char m_arial[3] = { 'A', 'A', 'F' };
    char letters[3] = { 'C', 'D' ,'H' };
    char pro[] = {' '};
    create->in.firstValue = m_name[rand() % 3];
    fprintf(f, "%c", create->in.firstValue);
    create->in.pro = pro[rand() % 1];
    fprintf(f, "%c", create->in.pro);

    create->in.secondValue = letters[rand() % 3];
    fprintf(f, "%c", create->in.secondValue);
    create->in.pro = pro[rand() % 1];
    fprintf(f, "%c", create->in.pro);

    create->in.thirdValue = m_arial[rand() % 3];
    fprintf(f, "%c", create->in.thirdValue);
    create->in.pro = pro[rand() % 1];
    fprintf(f, "%c", create->in.pro);

    create->in.fourthValue = rand() % 20 + 1;
    fprintf(f, "%f", create->in.fourthValue);
    create->in.pro = pro[rand() % 1];
    fprintf(f, "%c\n", create->in.pro);
    //fprintf(f, "\n");
    fclose(f);
}


create->next = NULL;
}
void newfile(List* head) {
List* sozdanie = new List;
FILE* f;
Data in;
fopen_s(&f, "fil.txt", "r");
if (f == NULL) {
    cout << "Ошибка откытия файла" << endl;
    exit(0);
}

fclose(f);

fopen_s(&f, "fil.txt", "r");
while (fscanf(f, "%c", &sozdanie->in.firstValue) != EOF) {

    printf("%c", sozdanie->in.firstValue);

    fscanf_s(f, "%c", &sozdanie->in.pro);
    printf("%c", sozdanie->in.pro);

    fscanf_s(f, "%c", &sozdanie->in.secondValue);
    printf("%c", sozdanie->in.secondValue);

    fscanf_s(f, "%c", &sozdanie->in.pro);
    printf("%c", sozdanie->in.pro);

    fscanf_s(f, "%c", &sozdanie->in.thirdValue);
    printf("%c", sozdanie->in.thirdValue);

    fscanf_s(f, "%c", &sozdanie->in.pro);
    printf("%c", sozdanie->in.pro);

    fscanf_s(f, "%f", &sozdanie->in.fourthValue);
    printf("%f", sozdanie->in.fourthValue);

    fscanf_s(f, "%c", &sozdanie->in.pro);
    printf("%c", sozdanie->in.pro);
    printf("\n");

     }
    fclose(f);
    sozdanie->next = NULL;

}
void osn()
{
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    List* head = NULL;
    int choice = 0;
    while (true) {
        cout << "---------------------------------------------" << endl;
        cout << "Выберите действие:" << endl;
        cout << "(1)Создание списка" << endl;//d
        cout << "(2)Печать списка" << endl;//d 
        cout << "(3)Поиск по критерию" << endl;//d
        cout << "(4)Добавление элемента" << endl;//d
        cout << "(5)Удаление элемента" << endl;//d
        cout << "(6)Сортировка" << endl;//d
        cout << "(7)Запись списка в файл" << endl;//d
        cout << "(8)Создание нового списка из файла" << endl;//
        cout << "(9)Выход" << endl;//d
        cout << "---------------------------------------------" << endl;
        cin >> choice;
        if (choice == 1) {
            head = newsp();
        }
        else if (choice == 2) {
                print(head);
        }
        else if (choice == 3) {
            search(head);
        }
        else if (choice == 4) {
            int el;
            cout << "Введите позицию на которую добавим" << endl;
            cin >> el;
            if (el == 1) {
                List* temp = new List;
                temp = newsp();
                temp->next = head;
                head = temp;
            }
            else {
                ad(head, el);
            }
        }
        else if (choice == 5) {
            int el;
            cout << "Введите позицию с которой удалим" << endl;
            cin >> el;
            if (el == 1) {
                List* temp = head;
                head = head->next;
                delete temp;
            }
            else { 
                del(head, el);
            }
            
        }
        else if (choice == 6) {
                sort(head);
        }
        else if (choice == 7) {

            file(head);
        }
        else if (choice == 8) {

            newfile(head);
        }
        else if (choice == 9) {
            exit(0);
        }
        else if (choice > 9) {
            cout << "Такого действия нет, попробуйте еще" << endl;
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