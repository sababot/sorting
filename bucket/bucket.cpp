#include <vector>
#include <math.h>
#include <algorithm>
#include <iterator>

#include "bucket.h"

using namespace std;

void bucket(int arr[], int n)
{
	vector<int> to_sort;
	vector<vector<int> > dummy;
	vector<int> result;
	vector<int> null_vec;

	for (int i = 0; i < n; i++)
		to_sort.push_back(arr[i]);

	for (int i = 0; i < n + 1; i++)
		dummy.push_back(null_vec);

	for (int i = 0; i < n; i++)
	{
		int bucket = floor(((n + 1) * to_sort[i]) / *max_element(to_sort.begin(), to_sort.end()));
		dummy[bucket].push_back(to_sort[i]);
	}

	for (int i = 0; i < (int)dummy.size(); i++)
	{
		if ((int)dummy[i].size() > 1)
		{
			for (int j = 0; j < (int)dummy[i].size(); j++)
			{
				int f = 0;
				while (f > 0 && dummy[i][f - 1] > dummy[i][f])
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
			for (int j = 0; j < (int)dummy[i].size(); j++)
				result.push_back(dummy[i][j]);
		else if ((int)dummy[i].size() == 1)
			result.push_back(dummy[i][0]);
	}

	for (int i = 0; i < n; i++)
		arr[i] = result[i];

	arr[n - 1] = *max_element(to_sort.begin(), to_sort.end());
}
