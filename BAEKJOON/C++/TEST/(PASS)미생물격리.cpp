#include<iostream>

using namespace std;

// 맵
int Map[101][101];

// 군집
struct G
{
	int x, y, amount,dir;
	int tmp = 0;
};

// 미생물 개수
G g_arr[1001];

// 방향
const int dx[5] = {0,0,0,-1,1};
const int dy[5] = {0,-1,1,0,0};

// 솔루션
void solution(int test_case);

void map_print(int N);

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

void solution(int test_case)
{
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= K; i++)
	{
		int y, x, amount, dir;
		cin >> y >> x >> amount >> dir;

		g_arr[i].x = x;
		g_arr[i].y = y;
		g_arr[i].amount = amount;
		g_arr[i].dir = dir;
	}

	for (int i = 0; i < M; i++) // M 시간동안
	{
		// 이동하면서 위치에 Map에 위치시킴
		for (int g_idx = 1; g_idx <= K; g_idx++)
		{
			// 사라진 군집이면
			if (g_arr[g_idx].dir == -1) continue;

			// 새 좌표
			int nx = g_arr[g_idx].x + dx[g_arr[g_idx].dir];
			int ny = g_arr[g_idx].y + dy[g_arr[g_idx].dir];

			// 해당 좌표가 약품이면
			if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1)
			{
				g_arr[g_idx].amount /= 2;

				if (g_arr[g_idx].amount == 0)
				{
					g_arr[g_idx].dir = -1;
					continue;
				}

				if (g_arr[g_idx].dir % 2 == 1) g_arr[g_idx].dir += 1;
				else g_arr[g_idx].dir -= 1;

				// 자기 위치 업데이트
				g_arr[g_idx].x = nx;
				g_arr[g_idx].y = ny;
			}

			// 군집이 겹치는 경우
			if (Map[ny][nx] != 0)
			{
				// 겹친 군집
				int g = Map[ny][nx];

				// 군집간 비교 (새로 들어온 군집이 더 우세)
				if (g_arr[g].amount < g_arr[g_idx].amount)
				{
					g_arr[g_idx].tmp += g_arr[g].amount;
					g_arr[g_idx].tmp += g_arr[g].tmp;
					
					// 기존 군집을 처리
					g_arr[g].dir = -1;
					
					// 해당 위치에 새로운 군집 배치
					Map[ny][nx] = g_idx;
					
					// 본인 좌표 업데이트
					g_arr[g_idx].x = nx;
					g_arr[g_idx].y = ny;
				}
				else
				{
					g_arr[g].tmp += g_arr[g_idx].amount;
					g_arr[g_idx].dir = -1;
				}
			}
			else // 이동 위치에 아무것도 없는 경우
			{
				// 이동 위치에 본인 idx 두고 넘어감
				Map[ny][nx] = g_idx;
				g_arr[g_idx].x = nx;
				g_arr[g_idx].y = ny;
			}
		}

		//map_print(N);

		// 이동이 모두 끝났으면 Map 클리어
		for (int g_idx = 1; g_idx <= K; g_idx++)
		{
			if (g_arr[g_idx].dir == -1 && Map[g_arr[g_idx].y][g_arr[g_idx].x] == 0) continue;
			else Map[g_arr[g_idx].y][g_arr[g_idx].x] = 0;

			if (g_arr[g_idx].tmp != 0) // 최종적으로 합쳐진 양
			{
				g_arr[g_idx].amount += g_arr[g_idx].tmp;
				g_arr[g_idx].tmp = 0;
			}

			// 클리어
			Map[g_arr[g_idx].y][g_arr[g_idx].x] = 0;
		}
	}

	int Answer = 0;

	for (int i = 1; i <= K; i++)
	{
		if (g_arr[i].dir == -1) continue;
		else {
			Answer += g_arr[i].amount;
		}
	}

	cout << '#' << test_case << ' ' << Answer << '\n';

	// 군집 tmp 초기화
	for (int i = 1; i <= K; i++) g_arr[i].tmp = 0;

	return;
}

void map_print(int N)
{
	// 맵 프린팅
	cout << '\n';
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cout << Map[row][col] << ' ';
		} cout << '\n';
	} cout << '\n';
}