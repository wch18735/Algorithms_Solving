#include <iostream>

using namespace std;

void solution(int test_case);

int cost[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		solution(test_case);
	}

	return 0;
}

void solution(int test_case)
{
	int res = 0;
	int N;
	cin >> N;

	cout << '#' << test_case << '\n';

	for (int i = 0; i < 8; i++)
	{
		cout << N / cost[i] << ' ';
		N = N % cost[i];
	}

	cout << '\n';

	return;
}