using namespace std;

#include "merge.h"

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
