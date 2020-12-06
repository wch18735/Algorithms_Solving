#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int n;
	cin >> n;

	int input_num;

	for (int i = 0; i < n; i++)
	{
		cin >> input_num;

		if (input_num == 0)
		{
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push({ abs(input_num), input_num });
		}
	}

	return 0;
}