#include <iostream>
#include <vector>

using namespace std;

void swap (int *a, int *b) 
{
    	int tmp = *a;
    	*a = *b;
    	*b = tmp;
}

void selection_sort (int arr[], int length) 
{
	int i, j, min_idx;

	for (i = 0; i < length - 1; i++)
	{
        	min_idx = i;
        	for (j = i + 1; j < length; j++)
        		if (arr[j] < arr[min_idx])
            			min_idx = j;

        	swap(&arr[min_idx], &arr[i]);
    	}
}

int main()
{	
	// Variables
	int array_length;
	int tmp;
	vector<int> to_sort;
	vector<int> result;
	
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
	int arr[array_length];
	for (int i = 0; i < array_length; i++)
		arr[i] = to_sort[i];
	
	selection_sort(arr, array_length);

	// Output
	cout << "\n";
	cout << "sorted array   : ";
	for (int i = 0; i < array_length; i++)
	{	
		if (i != array_length - 1)
		{
			cout << arr[i];
			cout << ", ";
		}
		
		else
			cout << arr[i];
	}
	cout << "\n";
}
