#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{	
	// Variables
	int array_length;
	vector<int> to_sort;
	vector<int> result;
	
	// Input
	cout << "array length: ";
	cin >> array_length;
	array_length++;
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
		cout << "fatal error: invalid choice";

	cout << "starting array: ";
	for (int i = 0; i < array_length - 1; i++)
	{
		if (i != array_length - 2)
		{			
			cout << to_sort[i];
			cout << ", ";
		}

		else 
			cout << to_sort[i];
	}

	cout << "\n";

	// Algorithm
	vector<vector<int> > dummy;
	for (int i = 0; i < array_length + 1; i++)
	{
		dummy.push_back({});
	}
	
	for (int i = 0; i < array_length; i++)
	{
		int bucket = floor(((array_length + 1) * to_sort[i]) / *max_element(to_sort.begin(), to_sort.end()));
		dummy[bucket].push_back(to_sort[i]);
	}
	
	for (int i = 0; i < (int)dummy.size(); i++)
	{
		if ((int)dummy[i].size() > 1)
		{
			for (int j = 0; j < (int)dummy[i].size(); j++)
			{	int f = 0;
				while (f > 0  && dummy[i][f-1] > dummy[i][f])
				{
					int tmp = dummy[i][f];
					dummy[i][f] = dummy[i][f - 1];
					dummy[i][f - 1] = tmp;
					f++;
				}
			}
		}
	}

	for (int i = 0; i < (int)dummy.size(); i++)
	{
		if ((int)dummy[i].size() > 1)
		{
			for (int j = 0; j < (int)dummy[i].size(); j++)
			{
				result.push_back(dummy[i][j]);
			}
		}

		else if ((int)dummy[i].size() == 1)
			result.push_back(dummy[i][0]);
	}
	
	// Output
	cout << "sorted array  : ";
	for (int i = 0; i < (int)result.size(); i++)
	{	
		if (i != (int)result.size() - 1)
		{
			cout << result[i];
			cout << ", ";
		}
		
		else
			cout << result[i];
	}
	cout << "\n";
	
	return 0;
}
