#include <iostream>
#include <chrono>
#include <windows.h>
using namespace std;
#define M 100 // Количество циклов
#define N 45  // Количество элементов массива

int mainArray[45];
//тип 1-возростание 2-спадание 3-рандом
void populateArray(int length, int type)
{
    for (int i = 0; i < length; i++)
    {
        if (type == 1)
        {
            mainArray[i] = i;
        }
        else if (type == 2)
        {
            mainArray[i] = length - i;
        }
        else
        {
            mainArray[i] = rand() % 100;
        }
    }
}


void mergeSort(int length, int type)
{
    int temp[45], i, j, k, size, l1, h1, l2, h2;
    /*populateArray(length, type);
    for (int i = 0; i < length; i++)
    {
        cout << mainArray[i] << ", ";
    }
    cout << "\n";*/

    /* l1 граница 1 пары */
    for (size = 1; size < length; size = size * 2)
    {
        l1 = 0;
        k = 0; /* Индекс для temp array */
        while (l1 + size < length)
        {
            h1 = l1 + size - 1;
            l2 = h1 + 1;
            h2 = l2 + size - 1;
            /* h2 превышает предел массива */
            if (h2 >= length)
                h2 = length - 1;
            /* Слияние 2 пар */
            i = l1;
            j = l2;
            while (i <= h1 && j <= h2)
            {
                if (mainArray[i] <= mainArray[j])
                    temp[k++] = mainArray[i++];
                else
                    temp[k++] = mainArray[j++];
            }
            while (i <= h1)
                temp[k++] = mainArray[i++];
            while (j <= h2)
                temp[k++] = mainArray[j++];
            /** Слияние выполнено **/
            /*Следущие 2 пары для слияния */
            l1 = h2 + 1;
        } /*конэц while*/
        /*остатки роскоши */
        for (i = l1; k < length; i++)
            temp[k++] = mainArray[i];
        for (i = 0; i < length; i++)
            mainArray[i] = temp[i];
    }
   /* for (int i = 0; i < length; i++)
    {
        cout << mainArray[i] << ", ";
    }
    cout << "\n";*/
}
//void calculate(int length, int methodName, int type)
//{
//
//
//    //запуск метода в зависимости от параметра
//    if (methodName == MERGE)
//    
//        mergeSort(length, type);
//    
//
//}
int main()
{

    cout << "Method Merge sort s\n";
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            std::cout << "***********Merge for " << i * 5 << " elements**********\n";
            if (j == 1)
            {
                std::cout << "***increase***\n";
            }
            else if (j == 2)
            {
                std::cout << "******waning********\n";
            }
            else
            {
                std::cout << "******random********\n";
            }
            auto start = chrono::high_resolution_clock::now();
            mergeSort(i*5, j);

            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
             printf (" duration %.8lf", duration.count());
        }
    };
}