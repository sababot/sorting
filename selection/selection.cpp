void swap_2 (int *a, int *b) 
{
    	int tmp = *a;
    	*a = *b;
    	*b = tmp;
}

void selection_sort (int arr[], int length) 
{
	int i, j, min_idx;

	for (i = 0; i < length - 1; i++)
	{
        	min_idx = i;
        	for (j = i + 1; j < length; j++)
        		if (arr[j] < arr[min_idx])
            			min_idx = j;

        	swap_2(&arr[min_idx], &arr[i]);
    	}
}
