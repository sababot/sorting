#include "shell.h"

void shell_sort(int arr[], int n)
{
	for (int g = n/2; g > 0; g /= 2)
    	{
        	for (int i = g; i < n; i += 1)
        	{
            		int tmp = arr[i];
		       	int j;           
            		for (j = i; j >= g && arr[j - g] > tmp; j -= g)
                		arr[j] = arr[j - gap];
           		 arr[j] = tmp;
        	}
    	}
}
