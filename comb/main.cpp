#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main()
{	
	// Variables
	int array_length;
	int tmp;
	vector<int> to_sort;
	int gap;

	// Input
	
	cout << "array length: ";
	cin >> array_length;
	gap = array_length;
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
	
	gap = (gap * 10) / 13;

	cout << "starting array: ";
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
	bool last;
	while (gap >= 1)
	{	
		for (int i = 0; i < array_length; i++)
		{	int diff = i + gap;
			if (diff < array_length)
			{
				if (to_sort[i] > to_sort[i + gap])
				{
					tmp = to_sort[i + gap];
					to_sort[i + gap] = to_sort[i];
					to_sort[i] = tmp;
				}
			}
		}
		if (last == true)
			break;

		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
        		gap = 11;
    		if (gap < 1)
        		gap = 1;
		if (gap == 1)
			last = true;
	}

	cout << "\n";
	cout << "sorted array  : ";
	for (int j = 0; j < array_length; j++)
	{
		if (j != array_length - 1)
		{
			cout << to_sort[j];
			cout << ", ";
		}

		else
			cout << to_sort[j];
	}
	
	cout << "\n";

	return 0;
}
