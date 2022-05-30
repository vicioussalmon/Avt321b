#include "Contents.h"
#include "Struct.h"
extern List* head, * tail;
extern int N;
List* newsp(){
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
    List* temp, *previ;
    head = previ = temp = new List;
    char m_name[3] = { 'G', 'B', 'J' };
    char m_arial[3] = { 'A', 'A', 'F' };
    char letters[3] = { 'C', 'D' ,'H' };
    temp->in.firstValue = m_name[rand() % 3];

    temp->in.secondValue = letters[rand() % 3];

    temp->in.thirdValue = m_arial[rand() % 3];

    temp->in.fourthValue = rand() % 20 + 1;
    temp->prew = NULL;
    temp->next = NULL;
    tail = temp;
    previ->next = NULL;
    return temp;
#ifdef DEBUG 
    cout << __DATE__"\n";
    cout << __TIME__"\n";
    cout << __FILE__"\n";
    cout << __FUNCTION__"\n";
#endif 
}
void print_nach() {
    List* print = head;
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
void print_end() {
    cout << "---------------------------------------------" << endl;
    cout << "G = Gnu |J = Jaran|B = Baza" << endl;
    cout << "A = Asia|F = Africa" << endl;
    cout << "---------------------------------------------" << endl;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    List* print = tail;
    while (print != NULL) {

        printf("%c ", print->in.firstValue);
        printf("%c ", print->in.secondValue);
        printf("%c ", print->in.thirdValue);
        printf("%f \n", print->in.fourthValue);
        print = print->prew;

    }
}
void search_nach(List* head) {
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
}
void search_end(List* head,List* tail) {
    List* poisk = tail;
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
}
void ad(int el) {
    List* temp = new List;
    char m_name[3] = { 'G', 'B', 'J' };
    char m_arial[3] = { 'A', 'A', 'F' };
    char letters[3] = { 'C', 'D' ,'H' };
    temp->in.firstValue = m_name[rand() % 3];

    temp->in.secondValue = letters[rand() % 3];

    temp->in.thirdValue = m_arial[rand() % 3];

    temp->in.fourthValue = rand() % 20 + 1;
    List* current = head;
    
        for (int i = 0; i < el - 1; i++) {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;
        if (temp->next != nullptr)	temp->next->prew = temp;
        temp->prew = current;
        
}
void del(List* head, int el) {
    List* temp_pos = head;
    temp_pos = head;
    for (int i = 0; i < el - 1; i++)
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
    fopen_s(&f, "file.txt", "a");
    if (f == NULL) {
        cout << "Ошибка" << endl;
        exit(0);
}
    else {
        char m_name[3] = { 'G', 'B', 'J' };
        char m_arial[3] = { 'A', 'A', 'F' };
        char letters[3] = { 'C', 'D' ,'H' };
        char pro[] = { ' ' };
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
        fclose(f);
    }


    create->next = NULL;
}
void newfile(List* head) {
    List* sozdanie = new List;
    FILE* f;
    Data in;
    fopen_s(&f, "file.txt", "r");
    if (f == NULL) {
        cout << "Ошибка" << endl;
        exit(0);
    }

    fclose(f);

    fopen_s(&f, "file.txt", "r");
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
        fscanf_s(f, "\n");
        printf("\n");
        sozdanie->next = NULL;
    }
    fclose(f);
    

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
        cout << "(2)Печать списка с начала" << endl;//?
        cout << "(3)Печать списка с конца" << endl;//?
        cout << "(4)Поиск по критерию(с начала списка)" << endl;//d
        cout << "(5)Поиск по критерию(с конца списка)" << endl;//d
        cout << "(6)Добавление элемента(в любое заданное место)" << endl;//якась чухня
        cout << "(7)Удаление любого элемента" << endl;//подозрительно, выглядит как и в 8й
        cout << "(8)Сортировка" << endl;//подозрительно, выглядит как и в 8й
        cout << "(9)Запись нового списка в файл" << endl;//подозрительно, выглядит как и в 8й
        cout << "(10)Создание нового списка из файла" << endl;//подозрительно, выглядит как и в 8й
        cout << "(11)Выход из программы" << endl;//d
        cout << "---------------------------------------------" << endl;
        cin >> choice;
        if (choice == 1) {
            head = newsp();
        }
        else if (choice == 2) {
            print_nach();
        }
        else if (choice == 3) {
            print_end();
        }
        else if (choice == 4) {
            search_nach(head);
        }
        else if (choice == 5) {
            search_end(head, tail);

        }
        else if (choice == 6) {
            int el;
            cout << "Выберете позицию:" << endl;
            cin >> el;
            if (el == 1) {
                List* temp = new List;
                char m_name[3] = { 'G', 'B', 'J' };
                char m_arial[3] = { 'A', 'A', 'F' };
                char letters[3] = { 'C', 'D' ,'H' };
                temp->in.firstValue = m_name[rand() % 3];

                temp->in.secondValue = letters[rand() % 3];

                temp->in.thirdValue = m_arial[rand() % 3];

                temp->in.fourthValue = rand() % 20 + 1;
                temp->next = head;
                temp->prew = temp;
                temp->prew = NULL;
                head = temp;
                temp->prew = nullptr;
            }
            else {
                ad(el);
            }
        }
        else if (choice == 7) {
            int el;
            cout << "Выберете позицию:" << endl;
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
        else if (choice == 8) {
            sort(head);
            
        }
        else if (choice == 9) {

         file(head);
        }
        else if (choice == 10) {

          newfile(head);
        }
        else if (choice == 11) {
            exit(0);
        }
        else if (choice > 11 || choice < 1) {
            cout << "Такого действия не существует, попробуйте еще раз" << endl;
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