#include<iostream>

using namespace std;

int jido[501][501];
int chk[501][501];

int M, N;
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
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> jido[i][j];
		}
	}
}

void print_map()
{
	cout << '\n';
	// 길 출력
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << chk[i][j] << ' ';
		}
		cout << '\n';
	}
}

int findload(int x, int y)
{
	// 목적지일 때
	if (x == M && y == N)
	{
		chk[x][y] = 1;
		return 1;
	}

	// 네 방향으로 탐색 시도
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || nx > M) continue;
		if (ny < 1 || ny > N) continue;
		if (jido[x][y] <= jido[nx][ny]) continue;
		if (chk[nx][ny] == -1) continue;
		if (chk[nx][ny] > 0)
		{
			chk[x][y] += chk[nx][ny];
			continue;
		}
		else chk[x][y] += findload(nx, ny);
	}

	if (chk[x][y] == 0) chk[x][y] = -1;

	// 값 반환
	if (chk[x][y] < 0) return 0;
	return chk[x][y];
}

void solution()
{
	// 입력
	input();

	// 길 찾기
	findload(1, 1);

	// 최종 답 출력
	if (chk[1][1] == -1) cout << 0;
	else cout << chk[1][1];
}

// 마지막 반례
// 1 2
// 1 2
// Correct: 0
// Wrong: -1