#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{	
	// Variables
	int array_length;
	int tmp;
	vector<int> to_sort;
	vector<int> count_ting;
	int k;
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
	k = *max_element(to_sort.begin(), to_sort.end());

	for (int i = 0; i < k + 1; i++)
		count_ting.push_back(0);

	for (int i = 0; i < array_length; i++)
	{	
		count_ting[to_sort[i]]++;
	}
	
	for (int i = 0; i < (int)count_ting.size(); i++)
	{
		if (count_ting[i] != 0)
		{
			for (int j = 0; j < count_ting[i]; j++)
				result.push_back(i);
		}
	}

	// Output
	cout << "\n";
	cout << "sorted array   : ";
	for (int i = 0; i < array_length; i++)
	{	
		if (i != array_length - 1)
		{
			cout << result[i];
			cout << ", ";
		}
		
		else
			cout << result[i];
	}
	cout << "\n";
}
