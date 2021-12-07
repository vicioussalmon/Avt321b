#include <iostream>
#include <chrono>
#include <windows.h>
using namespace std;
#define M 100 // Количество циклов
#define N 45  // Количество элементов массива
int SHAKER = 1;
int MERGE = 2;
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
void pintArray(int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << mainArray[i] << ", ";
    };
    cout << "\n";
}

//метод шейкерной сортировки для массива длиной length
void shakerSort(int length, int type)
{
    //наполняем массив случайными элементами
    populateArray(length, type);
    //печатаем исходный массив
    pintArray(length);
    int control = length - 1;
    int left = 0;
    int right = length - 1;
    do
    {

        for (int i = left; i < right; i++)
        {

            if (mainArray[i] > mainArray[i + 1])
            {
                swap(mainArray[i], mainArray[i + 1]);
                control = i;
            }
        }

        right = control;
        for (int i = right; i > left; i--)
        {

            if (mainArray[i] < mainArray[i - 1])
            {
                swap(mainArray[i], mainArray[i - 1]);
                control = i;
            }
        }
        left = control;
    } while (left < right);
    pintArray(length);
};

void mergeSort(int length, int type)
{
    int temp[45], i, j, k, n, size, l1, h1, l2, h2;
    populateArray(length, type);
    pintArray(length);

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
    pintArray(length);
}
void calculate(int length, int methodName, int type)
{ 
    //время старта

    //запуск метода в зависимости от параметра
    if (methodName == SHAKER)
    {
        shakerSort(length, type);
    }
    else
    {
        mergeSort(length, type);
    }
    // время остановки
}
int main()
{
    //метод шейкерной сортировки
    cout << "Method Shaker sort s\n";
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            //вычисляем работу метода для массива с i*5 элементов
            std::cout << "************shaker for " << i * 5 << " elements**********\n";
            if (j == 1)
            {
                std::cout << "******increase********\n";
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
            calculate(i * 5, SHAKER, j);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            cout << "Array count = " << i*5 << " duration " << duration.count() << "s\n";
        }
    }
  
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
            calculate(i * 5, MERGE, j);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            cout << "Array count = " << i*5 << " duration " << duration.count() << "s\n";
        }
    };
}