#include <iostream>
#include <vector>

using namespace std;

void merge(int array[], int lower, int middle, int upper) 
{ 
    	int i, j, k; 
    	int left[middle - lower + 1];
    	int right[upper - middle];

    	for (i = 0; i < middle - lower + 1; i++)
   		left[i] = array[lower + i];
    	for (j = 0; j < upper - middle; j++)
        	right[j] = array[middle + 1 + j];
   
    	i = 0;  
    	j = 0;
	k = lower;

    	for (k = lower; i < middle - lower + 1 && j < upper - middle; k++) 
    	{ 
        	if (left[i] <= right[j])
			array[k] = left[i++];
        	else 
			array[k] = right[j++];
    	}	

    	while (i < middle - lower + 1)
	    	array[k++] = left[i++];
    	while (j < upper - middle)
	    	array[k++] = right[j++];
}

void merge_sort(int array[], int lower, int upper)
{
	if(lower >= upper)
		return;
	
	merge_sort(array, lower, (lower + upper) / 2);
	merge_sort(array, ((lower + upper) / 2) + 1, upper);
	
	merge(array, lower, (lower + upper) / 2, upper);
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
	int arr[array_length];
	for (int i = 0; i < array_length; i++)
		arr[i] = to_sort[i];
	
	merge_sort(arr, 0, array_length);

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
