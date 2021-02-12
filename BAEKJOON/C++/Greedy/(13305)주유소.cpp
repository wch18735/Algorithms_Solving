#include<iostream>
#include<algorithm>

using namespace std;

void solution();

typedef long long ll;

ll oil[100000];
ll bridge[100000];
int N;

int main(void)
{
	solution();
	return 0;
}

void input()
{
	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		cin >> bridge[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> oil[i];
	}
}

void solution()
{
	input();

	ll res = 0;
	ll cost = 1234567890;
	for (int i = 0; i < N-1; i++)
	{
		cost = min(cost, oil[i]);
		res += cost * bridge[i];
	}

	cout << res;
}