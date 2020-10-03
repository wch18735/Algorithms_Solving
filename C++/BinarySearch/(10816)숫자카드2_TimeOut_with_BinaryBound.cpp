#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lower_bound_binary(vector<int> numArr, int num)
{
	int start = 0;
	int end = (int)numArr.size() - 1;
	int mid = (start + end) / 2;
	int idx = -1;

	while (!(start > end))
	{
		if (numArr[mid] >= num)
		{
			idx = mid;
			end = mid-1;
			mid = (start + end) / 2;
		}
		else
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
	}

	if (idx == -1) return (int)numArr.size();
	else return idx;
}

int upper_bound_binary(vector<int> numArr, int num) 
{
	int start = 0;
	int end = (int)numArr.size() - 1;
	int mid = (start + end) / 2;
	int idx = -1;

	while (!(start > end))
	{
		if (numArr[mid] > num)
		{
			idx = mid;
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
	}

	if (idx == -1) return (int)numArr.size();
	else return idx;
}

bool compare(int a, int b)
{
	return a < b;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;

	vector<int> numArr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> numArr[i];
		pq.push(numArr[i]);
	}

	sort(numArr.begin(), numArr.end());

	int m;
	cin >> m;

	int num;
	int lower_bound_idx;
	int upper_bound_idx;

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		lower_bound_idx = lower_bound_binary(numArr, num);
		upper_bound_idx = upper_bound_binary(numArr, num);
		
		cout << upper_bound_idx - lower_bound_idx << ' ';
		
	}

	return 0;
}