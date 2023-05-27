#include<iostream> 
#include<ctime>
#include<cmath>
#include<iomanip>
#include <chrono>
#define M 100
#define K 50 
using namespace std;


void mergesort(int a[], long num)
{
	int b[K];//временное хранилище
	int rght, rend;
	int i, j, m;

	for (int k = 1; k < num; k *= 2) {
		for (int left = 0; left + k < num; left += k * 2) {
			rght = left + k;
			rend = rght + k;
			if (rend > num) rend = num;
			m = left; i = left; j = rght;
			while (i < rght && j < rend) {
				if (a[i] <= a[j]) {
					b[m] = a[i]; i++;
				}
				else {
					b[m] = a[j]; j++;
				}
				m++;
			}
			while (i < rght) {
				b[m] = a[i];
				i++; m++;
			}
			while (j < rend) {
				b[m] = a[j];
				j++; m++;
			}
			for (m = left; m < rend; m++) {
				a[m] = b[m];
			}
		}
	}
}
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
	
}
int main()
{
	while (true) {
		setlocale(LC_ALL, "Russian");
		int i;
		int N;
		int type;
		int sort;
		int ar[50];
		int arra[50];
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
					arr[i] = i + 1; //increase
				}
				else if (type == 2)
				{
					arr[i] = N - (i + 1);//waning
					ar[i] = arr[i];
				}
				else
				{
					arr[i] = rand() % 100 + 1; //random
					arra[i] = arr[i];
				}
				cout << arr[i] << " ";
			}
			cout << endl;
			//time
			double aver_dur = 0;
			for (int i = 0; i < M; i++)
			{
				for (int i = 0; i < N; i++) {
					arra[i] = arr[i];
				}
				auto start = std::chrono::high_resolution_clock::now();
			ShakerSort(arra, N);
			auto end = std::chrono::high_resolution_clock::now();
			chrono::duration<double>duration = end - start;
			printf("Duration: %.10lf\n", duration.count());
			dur_arr[i] = duration.count();
		}
		for (int i = 0; i < M; i++)
		{
			printf("Duration: %.10lf\n", dur_arr[i]);
			if (i > 0) aver_dur += dur_arr[i];
		}
		printf("Duration a = %.10lf\n", aver_dur / (M - 1));//sr time
			cout << endl;
			cout << "So, the sorted list (using SHAKER SORT) will be :" << endl;
			cout << endl << endl;
			for (i = 0; i < N; i++)
				cout << arr[i] << "  ";
			cout << endl << endl << endl << endl;
		}
		if (sort == 2) {
			cout << "                             MERGE SORT PROGRAM                    		" << endl;
			cout << endl << endl;
			cout << "Input array size: ";
			cin >> N;
			cout << "Input array type: ";
			cin >> type;
			for (i = 0; i < N; i++)
					{
				if (type == 1)
				{
					arr[i] = i + 1; //increase
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
			double ave_dur = 0;
			for (int i = 0; i < M; i++)
			{
				for (int i = 0; i < N; i++) {
					arra[i] = arr[i];
				}
				auto start = std::chrono::high_resolution_clock::now();
				mergesort(arra, N);
				auto end = std::chrono::high_resolution_clock::now();
				chrono::duration<double>duration = end - start;
				printf("Duration: %.10lf\n", duration.count());
				dur_arr[i] = duration.count();
			}
			for (int i = 0; i < M; i++)
			{
				printf("Duration: %.10lf\n", dur_arr[i]);
				if (i > 0) ave_dur += dur_arr[i];
			}
			printf("Duration a = %.10lf\n", ave_dur / (M - 1));//sr time
			cout << endl;
			cout << "So, the sorted list (using MERGE SORT) will be :" << endl;
			cout << endl << endl;
			for (i = 0; i < N; i++)
				cout << arr[i] << "  ";
			cout << endl << endl << endl << endl;
		}
	}
	return 0;

}