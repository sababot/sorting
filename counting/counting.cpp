#include <vector>
#include <algorithm>

using namespace std;

void counting(int arr[], int n)
{
	int tmp;
	vector<int> count_ting;
	int k;
	vector<int> result;
	vector<int> to_sort;
	
	for (int i = 0; i < n; i++)
		to_sort.push_back(arr[i]);

	k = *max_element(to_sort.begin(), to_sort.end());

	for (int i = 0; i < k + 1; i++)
		count_ting.push_back(0);
	
	for (int i = 0; i < n; i++)
		count_ting[to_sort[i]]++;

	for (int i = 0; i < (int)count_ting.size(); i++)
		if (count_ting[i] != 0)
			for (int j = 0; j < count_ting[i]; j++)
				result.push_back(i);

	for (int i = 0; i < n; i++)
		arr[i] = result[i];
}
