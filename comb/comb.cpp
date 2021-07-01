#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void comb(int arr[], int n)
{
	int tmp;
	int gap;

	gap = (gap * 10) / 13;

	bool last;

	while (gap >= 1)
	{
		for (int i = 0; i < n; i++)
		{
			int diff = i + gap;
			
			if (diff < n)
			{
				if (arr[i] > arr[i + gap])
				{
					tmp = arr[i + gap];
					arr[i + gap] = arr[i];
					arr[i] = tmp;
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
}
