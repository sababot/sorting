#include <iostream>
#include <vector>

using namespace std;

int max_element(int arr[], int n)
{
	int max = arr[0];
	
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void count_sort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
   for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n)
{
    int m = max_element(arr, n);
    
    for (int exp = 1; m / exp > 0; exp *= 10)
        count_sort(arr, n, exp);
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
	
	int n = array_length;
	int max = max_element(arr, n);

	radix_sort(arr, n);

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
