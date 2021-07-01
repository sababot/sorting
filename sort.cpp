#include <iostream>
#include <vector>
#include <string>

#include "bubble/bubble.h"
#include "bucket/bucket.h"
#include "comb/comb.h"
/*
#include "counting/counting.h"
#include "heap/heap.h"
#include "insertion/insertion.h"
#include "merge/merge.h"
#include "quick/quick.h"
#include "radix/radix.h"
#include "selection/selection.h"
*/

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

	if (choice == 'm')
	{
		for (int i = 0; i < array_length; i++)
		{
			int temp;
			cin >> temp;
			to_sort.push_back(temp);
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

	int arr[array_length];
	for (int i = 0; i < array_length; i++)
		arr[i] = to_sort[i];
	
	// Algorithm
	string algos[11] = {	"bubble", "bucket", "comb", 
				"counting", "heap", "insertion", 
				"merge", "quick", "radix", 
				"selection", "shell"	};
	int algo;
	cout << "\n\nwhich algorithm would you like to use?";
	cout << "\nalgorithm: ";
	cin >> algo;
	cout << "\n";
	cout << "algorithm: ";
	cout << algos[algo - 1];
	cout << "\n";

	switch (algo)
	{
		case 1:
			bubble(arr, array_length);
			break;
		case 2:
			bucket(arr, array_length);
			break;
		case 3:
			comb(arr, array_length);
			break;
		/*
		case "counting":
			counting(arr, array_length);
			break;
		case "heap":
			heap(arr, array_length);
			break;
		case "insertion":
			insertion(arr, array_length);
			break;
		case "merge":
			merge(arr, array_length);
			break;
		case "quick":
			quick(arr, array_length);
			break;
		case "radix":
			radix(arr, array_length);
			break;
		case "selection":
			selection(arr, array_length);
			break;
		*/
		default:
			cout << "fatal error: out of range";
			break;
	}

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

	return 0;
}
