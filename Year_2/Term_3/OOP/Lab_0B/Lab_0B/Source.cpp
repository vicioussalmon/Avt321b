#include "Header.h"
void pfoo(int* arr, int SIZE) {
    int min = 0, max = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (*(arr+i) < arr[min])
            min = i;

        if (*(arr + i) > arr[max])
            max = i;
    }

    int tmp = arr[max];
    arr[max] = arr[min];
    arr[min] = tmp;


    for (int i = 0; i < SIZE; i++)
    {
        cout << *(arr + i) << " ";
    }

    cout << endl;
}
void lfoo(int(&ref)[3], int SIZE){
    int min = 0, max = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (ref[i] < ref[min])
            min = i;

        if (ref[i] > ref[max])
            max = i;
    }

    int tmp = ref[max];
    ref[max] = ref[min];
    ref[min] = tmp;


    for (int i = 0; i < SIZE; i++)
    {
        cout << ref[i] << " ";
    }

    cout << endl;
}
void osn()
{
    setlocale(LC_CTYPE, "ukr");
    while (true) {
    const int SIZE = 3;
    int answer;
    cout << "---------------------------------------------------" << endl;
    cout << "Оберіть спосіб передачі параметрів:" << endl;
    cout << "За допомогою покажчиків(1)/За допомогою посилань(2)" << endl;
    cin >> answer;
    if (answer == 1)
    {
        int* arr = new int[SIZE];
        cout << "Масив : \n";
        for (int i = 0; i < SIZE; i++)
        {
            *(arr + i) = rand() % 21 - 10;
            cout << *(arr + i) << " ";
        }
        cout << endl;
        pfoo(arr, SIZE);
        delete[]arr;
    }
    if (answer == 2){
        int arr[SIZE];
        int& ref = arr[SIZE];
        cout << "Масив : \n";
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = rand() % 21 - 10;
            cout << arr[i] << " ";
        }
        cout << endl;
        lfoo(arr, SIZE);
        
    }
    if (answer < 1 || answer > 2) {
        cout << "Упс! Такої функції не існує, спробуйте ще раз..." << endl;
    }
    }

}