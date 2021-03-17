#include<iostream>
#include<deque>

using namespace std;

int jido[501][501];
int N, M;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

void solution();

int main(void)
{
	solution();
	return 0;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> jido[i][j];
		}
	}
}

void solution()
{
	input();

	deque<pair<int, int>> dq;
	dq.push_back({ 1, 1 });

	int cnt = 0;

	while (!dq.empty())
	{
		pair<int, int> cur_p = dq.front();
		dq.pop_front();

		int cur_x = cur_p.first;
		int cur_y = cur_p.second;
		int cur_val = jido[cur_x][cur_y];

		if (cur_x == M && cur_y == N)
		{
			cnt += 1;
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 1 || nx > M) continue;
			if (ny < 1 || ny > N) continue;
			if (cur_val <= jido[nx][ny]) continue;
			
			// next position
			dq.push_back({ nx, ny });
		}
	}

	cout << cnt;
}