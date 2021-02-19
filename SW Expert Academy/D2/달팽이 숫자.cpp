#include <iostream>

using namespace std;

void solution(int test_case);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

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

void solution(int test_case)
{
	cin >> N;
	
	int snail[10][10] = { 0, };

	int x = 0;
	int y = 0;
	int dir = 0;
	int cnt = 0;
	for (int i = 1; i <= N * N; i++)
	{
		// fill number
		snail[y][x] = i;

		// check direction
		while (true)
		{
			// break
			if (cnt == 4)
			{
				break;
			}

			// y over range
			if (y + dy[dir] < 0 || y + dy[dir] >= N)
			{
				dir = (dir + 1) % 4;
				cnt += 1;
				break;
			}

			// x over range
			if (x + dx[dir] < 0 || x + dx[dir] >= N)
			{
				dir = (dir + 1) % 4;
				cnt += 1;
				break;
			}

			// filled block
			if (snail[y + dy[dir]][x + dx[dir]] != 0)
			{
				dir = (dir + 1) % 4;
				cnt += 1;
			}
			else
			{
				break;
			}
		}

		// finish
		if (cnt == 4) break;
		else cnt = 0;

		// change dir
		x += dx[dir];
		y += dy[dir];
	}

	cout << '#' << test_case << '\n';

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << snail[i][j] << ' ';
		}
		cout << '\n';
	}

	return;
}