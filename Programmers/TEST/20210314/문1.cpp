#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

void solution();

int jido[11][11];
int jido_chk[11][11];
int M, N;
int key_chk, treasure_chk;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

struct point {
	int row; 
	int col;
};

point soma_p;


int main(void)
{
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		solution();
	}

	return 0;
}

void _input()
{
	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> jido[i][j];
			if (jido[i][j] == 3)
			{
				soma_p.row = i;
				soma_p.col = j;
			}
		}
	}
}

void bfs(int r, int c)
{
	deque<pair<int, int>> dq;

	// 가능한 Queue
	dq.push_back({ r,c });
	jido_chk[r][c] = -1;

	while (!dq.empty())
	{
		// 뽑기
		int row = dq.front().first;
		int col = dq.front().second;
		dq.pop_front();

		// 현재 위치가 보물 또는 열쇠인지 확인
		if (jido[row][col] == 2)
		{
			// 보물
			treasure_chk = 1;
		}
		else if (jido[row][col] == 4)
		{
			// 열쇠
			key_chk = 1;
		}

		// 위치로부터 가능한 점 4방위로 모두 찾기
		for (int i = 0; i < 4; i++)
		{
			if (jido[row + dx[i]][col + dy[i]] == 1) continue;
			else if (jido_chk[row + dx[i]][col + dy[i]] == -1) continue;
			else if (row + dx[i] < 1 || row + dx[i] > M) continue;
			else if (col + dy[i] < 1 || col + dy[i] > N) continue;

			// 큐에 삽입
			dq.push_back({ row + dx[i], col + dy[i] });

			// 방문 전환
			jido_chk[row + dx[i]][col + dy[i]] = -1;
		}
	}
}

void solution()
{
	// 입력
	_input();

	// 탐색 (bfs)
	int soma_row = soma_p.row;
	int soma_col = soma_p.col;
	bfs(soma_row, soma_col);


	// 보물과 열쇠 모두 찾을 수 있으면 1 아니면 0
	if (treasure_chk && key_chk) cout << 1 << '\n';
	else cout << 0 << '\n';

	// 전역변수 초기화 (jido, jido_chk, key_chk, treasure_chk)
	fill(&jido[0][0], &jido[M - 1][N], 0);
	fill(&jido_chk[0][0], &jido_chk[M - 1][N], 0);
	key_chk = 0;
	treasure_chk = 0;
}

