#include <iostream>
#include <vector>

using namespace std;

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
	/*int i, key, j;
    	for (i = 1; i < array_length; i++)
    	{
        	key = to_sort[i];
        	j = i - 1;
 
        	while (j >= 0 && to_sort[j] > key)
        	{
            		to_sort[j + 1] = to_sort[j];
            		j = j - 1;
        	}
        	to_sort[j + 1] = key;
    	}*/
	int inx, j;

	for (int i = 1; i < array_length; i++)
	{
		j = i - 1;
		inx = to_sort[i];
		
		while (j >= 0 && to_sort[j] > inx)
		{
			int tempting = to_sort[i];
			to_sort[i] = to_sort[j];
			to_sort[j] = tempting;
			j--;
		}
	}

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
