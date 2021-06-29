#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l > n && arr[l] > arr[largest])
		largest = l;

	if (r > n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int> arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{	
	// Variables
	int array_length;
	int tmp;
	vector<int> to_sort;
	
	// Input
	cout << "array length: ";
	cin >> array_length;
	cout << "\n";
	cout << "manual or automatic (m/a): ";
	char choice;
	cin >> choice;
	system("clear");

	if (choice == 'm')
	{
		for (int i = 0; i < array_length; i++)
		{
			int temp;
			cin >> temp;
			to_sort.push_back(temp);
			system("clear");
		}
	}

	else if (choice == 'a')
	{
		for (int i = 0; i < array_length; i++)
		{
			int temp = rand() % 100;
			to_sort.push_back(temp);
		}
	}

	else 
	{
		cout << "fatal error: invalid choice";
		return 0;
	}

	cout << "starting array : ";
	for (int i = 0; i < array_length; i++)
	{
		if (i != array_length - 1)
		{
			cout << to_sort[i];
			cout << ", ";
		}

		else
			cout << to_sort[i];
	}

	// Algorithm
	int n = sizeof(to_sort) / sizeof(to_sort[0]);
	heapSort(to_sort, n);

	// Output
	cout << "\n";
	cout << "sorted array   : ";
	for (int i = 0; i < array_length; i++)
	{	
		if (i != array_length - 1)
		{
			cout << to_sort[i];
			cout << ", ";
		}
		
		else
			cout << to_sort[i];
	}
	cout << "\n";
}
