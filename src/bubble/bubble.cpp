#include "bubble.h"
#include <unistd.h>

void bubble(int arr[], int n)
{
	int tmp;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

void bubble_step(int arr[], int n)
{
	int tmp;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				return;
			}
		}
	}
}
