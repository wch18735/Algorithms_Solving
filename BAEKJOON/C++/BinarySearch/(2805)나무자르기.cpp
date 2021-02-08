#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int ll;

ll N, M;

ll tree_arr[1000000];

void solution();

int main(void)
{
	solution();

	return 0;
}

void solution()
{
	cin >> N >> M;

	ll max_num = 0;

	// ют╥б
	for (int i = 0; i < N; i++)
	{
		cin >> tree_arr[i];
		max_num = max(tree_arr[i], max_num);
	}

	ll start = 1;
	ll end = max_num;
	ll mid = (start + end) / 2;

	while (end >= start)
	{
		ll sum = 0;
		
		for (int i = 0; i < N; i++)
		{
			if (tree_arr[i] - mid <= 0) continue;
			else sum += tree_arr[i] - mid;
		}

		if (sum < M) end = mid - 1;
		else start = mid + 1;

		mid = (start + end) / 2;
	}

	cout << end;
}