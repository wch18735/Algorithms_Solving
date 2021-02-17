#include<iostream>

using namespace std;

void solution(int test_case);

int MAP[15][15];
int N, K;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		solution(test_case);
	}
	return 0;
}

void input()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

void solution(int test_case)
{
	input();

	int res = 0;
	int v_len = 0;
	int h_len = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// check horizental
			if (MAP[i][j] == 1)
			{
				v_len += 1;
			}
			else
			{
				if (v_len == K) res += 1;
				v_len = 0;
			}
			// cehck vertical
			if (MAP[j][i] == 1)
			{
				h_len += 1;
			}
			else
			{
				if (h_len == K) res += 1;
				h_len = 0;
			}

			// final
			if (j == N - 1)
			{
				if (v_len == K) res += 1;
				v_len = 0;
				if (h_len == K) res += 1;
				h_len = 0;
			}
		}
	}

	cout << '#' << test_case << ' ' << res << '\n';
	return;
}