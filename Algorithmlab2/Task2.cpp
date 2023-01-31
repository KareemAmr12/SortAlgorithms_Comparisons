#include <iostream>
#include <iomanip>
using namespace std;


void Swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


int bubble_sort_comparisons(int* arr, int n)
{
	int i, j;
	int countr = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			countr++;
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				
			}
		}
	}
	return countr;
}

int interstion_sort_comparisons(int* arr, int n)
{
	int i, key, j;
	int countr = 0;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		countr++;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
			if (j>-1)
			{
				countr++;
			}
			
		}
		arr[j + 1] = key;
	}
	return countr;
}

int* generate_k_inversion(int k, int n)
{
	int* arr;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	for (int j = 0; j < k; j++)
	{
		Swap(&arr[j], &arr[j + 1]);
	}
	return arr;
}

void test1()
{
	int n = 10;
	int a1[10];
	int a2[10];
	int a3[10];
	int a4[10];
	
	for (int i = 1; i <=n; i++)
	{
		int* arr1;
		arr1 = new int[i];
		int* arr2;
		arr2 = new int[i];
		int* arr3;
		arr3 = new int[i];
		int* arr4;
		arr4 = new int[i];
		for (int j = 0; j < i; j++)
		{
			arr1[j] = j;
			arr2[j] = j;
			arr3[j] = j;
			arr4[j] = j;
		}
		if (i > 2)
		{
			for (int k = 0; k < i; k++)
			{
				int temp1 = arr2[k];
				arr2[k] = arr2[i - 1 - k];
				arr2[i - 1 - k] = temp1;

				int temp2 = arr4[k];
				arr4[k] = arr4[i - 1 - k];
				arr4[i - 1 - k] = temp2;
			}
		}
		a1[i-1] = bubble_sort_comparisons(arr1, i);
		a2[i-1] = bubble_sort_comparisons(arr2, i);
		a3[i-1] = interstion_sort_comparisons(arr3, i);
		a4[i-1] = bubble_sort_comparisons(arr4, i);
	}
	cout << "n" << "       Bubble Sort - Best" << "  Bubble Sort - Worst" << "  Insertion Sort - Best" << "   Insertion Sort - Worst" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << setw(17) << a1[i - 1] << setw(21) << a2[i - 1] << setw(21) << a3[i - 1] << setw(25) << a4[i - 1] << endl;
	}
	
}

void test2()
{
	int a1[11];
	int a2[11];
	int** arr1 = new int* [11];
	int** arr2 = new int* [11];
	for (int i = 0; i < 11; ++i)
	{
		arr1[i] = new int[i+5];
		arr2[i] = new int[i+5];
	}

	for (int i = 1; i <= 11; i++)
	{
		int k = (i + 4) / 4;
		arr1[i - 1] = generate_k_inversion(k, i + 4);
		arr2[i - 1] = generate_k_inversion(k, i + 4);
	}
	for (int i = 0; i < 11; i++)
	{
		a1[i] = bubble_sort_comparisons(arr1[i], i + 5);
		a2[i] = interstion_sort_comparisons(arr2[i], i + 5);
	}
	cout << endl;
	cout << "n          " << setw(15) << "bubble sort comparisons    " << setw(20) << "insertion sort comparisons" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << i + 5 << setw(20) << a1[i] << setw(28) << a2[i] << endl;
	}

	
}


int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}