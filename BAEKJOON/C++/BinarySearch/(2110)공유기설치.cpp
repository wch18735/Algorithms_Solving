#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

ll arr[200000];

bool compare(ll a, ll b)
{
	return a < b;
}

int main(void)
{
	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N, compare);

	ll min_d = 1;
	ll max_d = arr[N - 1] - arr[0];
	ll middle_d = max_d;

	ll Answer = 0;
	while (min_d <= max_d)
	{
		int cnt = 1;
		ll prev = arr[0];
		for (int i = 1; i < N; i++)
		{
			if (arr[i] - prev >= middle_d)
			{
				prev = arr[i];
				cnt++;
			}
		}

		if (cnt >= C)
		{
			min_d = middle_d + 1;
			Answer = max(middle_d, Answer);
		}
		else
		{
			max_d = middle_d - 1;
		}

		middle_d = (min_d + max_d) / 2;
	}
	
	cout << Answer;
	
	return 0;
}