#include<cmath>
#include<iomanip>
#include <chrono>
#define M 100	
using namespace std;

int a[50];
void shaker(int, int, int);
//void shaker_sort(int low, int high)
//{
//    int mid;
//    if (low < high)
//    {
//        mid = low + (high - low) / 2; //This avoids overflow when low, high are too large
//        shaker_sort(low, mid);
//        shaker_sort(mid + 1, high);
//        shaker(low, mid, high);
//    }
//}
 void shaker(int array[], int size)
    {
     int low; int high;
        for (int left_idx = 0, right_idx = size - 1;
            left_idx < right_idx;)
        {
            for (int idx = left_idx; idx < right_idx; idx++)
            {
                if (array[idx + 1] < array[idx])
                {
                    swap(array[idx], array[idx + 1]);
                }
            }
            right_idx--;

            for (int idx = right_idx; idx > left_idx; idx--)
            {
                if (array[idx - 1] > array[idx])
                {
                    swap(array[idx - 1], array[idx]);
                }
            }
            left_idx++;
        }
        int mid;
        if (low < high)
        {
            mid = low + (high - low) / 2; //This avoids overflow when low, high are too large
            /*shaker(low, mid);
            shaker(mid + 1, high);
            shaker(low, mid, high);*/
        }
    }

int main()
{
	setlocale(LC_ALL, "Russian");
	int num, i;
	double aver_dur = 0;
	/*cout << "                             MERGE SORT PROGRAM                    		" << endl;*/

	/*cout << endl;*/
	cout << "Please Enter THE NUMBER OF ELEMENTS you want to sort [THEN PRESS ENTER]:" << endl;
	cin >> num;
	cout << endl;
	double dur_arr[5];
	for (i = 1; i <= num; i++)
	{
		a[i] = rand() % 100 + 1;
		cout << a[i] << " ";
	}
	cout << endl;

	//time

	/*auto start = std::chrono::high_resolution_clock::now();*/
    shaker/*_sort*/(1, num);
	/*auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double>duration = end - start;
	printf("Duration: %.10lf\n", duration.count());
	dur_arr[i] = duration.count();*/

	cout << endl;
	cout << "So, the sorted list (using MERGE SORT) will be :" << endl;
	cout << endl << endl;

	for (i = 1; i <= num; i++)
		cout << a[i] << "  ";

	cout << endl << endl << endl << endl;
	return 1;

}