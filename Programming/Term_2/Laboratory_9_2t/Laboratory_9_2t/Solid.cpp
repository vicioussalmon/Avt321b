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
List* search_end(List* head,List* tail) {
    List* current = head;
     cout << "Выберите позицию" << endl;
     int position;
     cin >> position;
     while (current->next != NULL) {
         current = current->next;
     }
     while (current != NULL) {
         
             printf("%c ", current->in.firstValue);
             printf("%c ", current->in.secondValue);
             printf("%c ", current->in.thirdValue);
             printf("%f \n", current->in.fourthValue);
             return current;
         
        
     }
     current = current->prew;
}
List* ad(int el) {
    List* ins = head;
    int schetchik = 0;
    if (head == NULL) {
        cout << "Список пуст" << endl;
        return head;
    }
    while (ins) {
        schetchik++;
        ins = ins->next;

    }
    List* temp = new List;
    char m_name[3] = { 'G', 'B', 'J' };
    char m_arial[3] = { 'A', 'A', 'F' };
    char letters[3] = { 'C', 'D' ,'H' };
    temp->in.firstValue = m_name[rand() % 3];

    temp->in.secondValue = letters[rand() % 3];

    temp->in.thirdValue = m_arial[rand() % 3];

    temp->in.fourthValue = rand() % 20 + 1;
    List* current = head;
    el--;
    if (el < 0 || el > schetchik) {
        //cout << "Âû âûøëè çà ïðåäåëû ñïèñêà" << endl;
        return head;
    }
    else {
        for (int i = 0; i < el - 1; i++) {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;
        if (temp->next != nullptr)	temp->next->prew = temp;
        temp->prew = current;
    }
    return head;

}
void del(List* head, int el) {
    List* del = head;
    if (head == NULL) {
        cout << " Ошибка" << endl;
        return;
    }
    int schetchik = 0;
    while (del) {
        schetchik++;
        del = del->next;
    }
    el--;
    if (el <0 || el > schetchik || head->next == NULL) {
        return;
    }
    del = head;

    for (int i = 0; i < el - 1; i++)
    {
        del = del->next;
    }
    List* temp = del->next;
    if (del->next == NULL) {
        return;
    }
    del->next = temp->next;
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
        cout << "(2)Печать списка с начала" << endl;//d
        cout << "(3)Печать списка с конца" << endl;//d
        cout << "(4)Поиск по критерию(с начала списка)" << endl;//d
        cout << "(5)Поиск по критерию(с конца списка)" << endl;//d
        cout << "(6)Добавление элемента(в любое заданное место)" << endl;//d
        cout << "(7)Удаление любого элемента" << endl;//d
        cout << "(8)Сортировка" << endl;//d
        cout << "(9)Запись нового списка в файл" << endl;//d
        cout << "(10)Создание нового списка из файла" << endl;//d
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
                ad(el);
        }
        else if (choice == 7) {
            int el;
            cout << "Выберете позицию:" << endl;
            cin >> el;
                del(head, el);
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