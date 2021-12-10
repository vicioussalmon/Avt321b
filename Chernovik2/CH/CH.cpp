#include<iostream> 
#include<ctime>
#include<cmath>
#include<iomanip>
#include <chrono>
#define M 100
//#define N 5
using namespace std;

//int a[50];
//void merge(int, int, int);
//void merge_sort( int low, int high)
//{
//	int mid;
//	if (low < high)
//	{
//		mid = low + (high - low) / 2; //This avoids overflow when low, high are too large
//		merge_sort( low, mid);
//		merge_sort( mid + 1, high);
//		merge( low, mid, high);
//	}
//}
//void merge( int low, int mid, int high )
//{
//	
//	int h, i, j, b[50], k;
//	h = low;
//	i = low;
//	j = mid + 1;
//	while ((h <= mid) && (j <= high))
//	{
//		if (a[h] <= a[j])
//		{
//			b[i] = a[h];
//			h++;
//		}
//		else
//		{
//			b[i] = a[j];
//			j++;
//		}
//		i++;
//	}
//	if (h > mid)
//	{
//		for (k = j; k <= high; k++)
//		{
//			b[i] = a[k];
//			i++;
//		}
//	}
//	else
//	{
//		for (k = h; k <= mid; k++)
//		{
//			b[i] = a[k];
//			i++;
//		}
//	}
//	for (k = low; k <= high; k++) 
//		a[k] = b[k];
//	
//}
void ShakerSort(int a[], int n) {
	int left, right, i, tmp;
	left = 0;
	right = n - 1;
	while (left <= right) {
		for (i = right; i >= left; i--) {
			if (a[i - 1] > a[i]) {
				tmp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = tmp;
			}
		}
		left++;
		for (i = left; i <= right; i++) {
			if (a[i - 1] > a[i]) {
				tmp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = tmp;
				
			}
		}
		right--;
	}
	/*return a[n];*/
}
int main()
{
	while (true) {
		setlocale(LC_ALL, "Russian");
		int i;
		int N;
		int type;
		int sort;
		int arr[50];
		double dur_arr[M];
		cout << "Choose type of sort (SHAKER SORT - 1/MERGE SORT - 2): ";
		cin >> sort;
		if (sort == 1) {
			cout << "                             SHAKER SORT PROGRAM                    		" << endl;

			cout << endl << endl;
			cout << "Input array size: ";
			cin >> N;
			cout << "Input array type: ";
			cin >> type;
			for (i = 0; i < N; i++)
			{
				if (type == 1)
				{
					arr[i] = i + 1 ; //increase
				}
				else if (type == 2)
				{
					arr[i] = N - (i + 1); //waning
				}
				else
				{
					arr[i] = rand() % 100 + 1; //random
				}


				cout << arr[i] << " ";
			}
			cout << endl;

			//time
			double aver_dur = 0;

			/*for (int i = 0; i < M; i++)
			{
				auto start = std::chrono::high_resolution_clock::now();*/
				ShakerSort(arr, N);
				/*auto end = std::chrono::high_resolution_clock::now();
				chrono::duration<double>duration = end - start;
				printf("Duration: %.10lf\n", duration.count());
				dur_arr[i] = duration.count();
			}
			for (int i = 0; i < M; i++)
			{
				printf("Duration: %.10lf\n", dur_arr[i]);
				if (i > 0) aver_dur += dur_arr[i];
			}
			printf("Duration a = %.10lf\n", aver_dur / (M - 1));*///sr time

			cout << endl;
			cout << "So, the sorted list (using SHAKER SORT) will be :" << endl;
			cout << endl << endl;

			for (i = 0; i < N; i++)
				cout << arr[i] << "  ";

			cout << endl << endl << endl << endl;
		}
		//if (sort == 2) {
		//	cout << "                             MERGE SORT PROGRAM                    		" << endl;
		//	cout << endl << endl;
		//	cout << "Input array size: ";
		//	cin >> N;
		//	cout << "Input array type: ";
		//	cin >> type;
		//	for (i = 1; i <= N; i++)
		//	{
		//		if (type == 1)
		//		{
		//			arr[i] = i; //increase
		//		}
		//		else if (type == 2)
		//		{
		//			arr[i] = N - i; //waning
		//		}
		//		else
		//		{
		//			arr[i] = rand() % 100 + 1; //random
		//		}
		//		cout << arr[i] << " ";
		//	}
		//	cout << endl;
		//	time
		//	double aver_dur = 0;
		//	for (int i = 0; i < M; i++)
		//	{
		//		auto start = std::chrono::high_resolution_clock::now();
		//		MergeSort(arr, N);
		//		auto end = std::chrono::high_resolution_clock::now();
		//		chrono::duration<double>duration = end - start;
		//		printf("Duration: %.10lf\n", duration.count());
		//		dur_arr[i] = duration.count();
		//	}
		//	for (int i = 0; i < M; i++)
		//	{
		//		printf("Duration: %.10lf\n", dur_arr[i]);
		//		if (i > 0) aver_dur += dur_arr[i];
		//	}
		//	printf("Duration a = %.10lf\n", aver_dur / (M - 1));//sr time
		//	cout << endl;
		//	cout << "So, the sorted list (using MERGE SORT) will be :" << endl;
		//	cout << endl << endl;
		//	for (i = 1; i <= N; i++)
		//		cout << arr[i] << "  ";
		//	cout << endl << endl << endl << endl;
		//}
	}
		return 0;
	
}