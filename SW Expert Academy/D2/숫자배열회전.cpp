#include <iostream>

using namespace std;

void solution(int test_case);

int arr[7][7];
int N;

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

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void solution(int test_case)
{
	input();

	cout << '#' << test_case << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[N - 1 - j][i];
		}

		cout << ' ';

		for (int j = 0; j < N; j++)
		{
			cout << arr[N-1-i][N - 1 - j];
		}

		cout << ' ';

		for (int j = 0; j < N; j++)
		{
			cout << arr[j][N - 1 - i];
		}
		cout << '\n';
	}

	return;
}