#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// priority_queue (max heap)
	priority_queue<int, vector<int>, less<int>> pq;

	int num;
	cin >> num;

	int input_num;
	for (int i = 0; i < num; i++)
	{
		cin >> input_num;
		if (input_num == 0)
		{
			if (pq.empty()) cout << 0;
			else
			{
				cout << pq.top();
				pq.pop();
			}
			cout << '\n';
		}
		else pq.push(input_num);
	}

	return 0;
}