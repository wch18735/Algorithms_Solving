#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/* 자료형 */
typedef pair<int, int> Point;
int MAP[16][13];

/* 함수 */
void solution(int test_case);
int boom(int MAP[16][13], int W, int H, int left_biz);
void Mcopy(int original_MAP[16][13], int copy_MAP[16][13]);

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

/* 솔루션 */
void solution(int test_case)
{
	int N, W, H;
	cin >> N >> W >> H;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> MAP[i][j];
		}
	}

	cout << '#' << test_case << ' ' << boom(MAP, W, H, N) << '\n';

	return;
}

/* 함수 정의 */
// 맵 복사
void Mcopy(int original_MAP[16][13], int copy_MAP[16][13])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			copy_MAP[i][j] = original_MAP[i][j];
		}
	}

	return;
}

// 맵 출력
void PrintMap(int target_MAP[16][13], int W, int H)
{
	cout << '\n';
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cout << target_MAP[i][j] << ' ';
		} cout << '\n';
	}
}

// 폭탄 터짐
int boom(int target_MAP[16][13], int W, int H, int left_biz)
{
	// Baseline
	if (left_biz == 0)
	{
		// 벽돌 개수 세기 (MAP에서 값이 0이 아닌 것)
		int cnt = 0;
		for (int i = 1; i <= H; i++)
		{
			for (int j = 0; j <= W; j++)
			{
				if (target_MAP[i][j] != 0) cnt += 1;
			}
		}

		return cnt;
	}

	// 최초 비교
	int Answer = 1000;

	// 원본 MAP 복사할 맵
	int copy_MAP[16][13];

	// 비어있는 열의 개수
	int zero_count = 0;

	for (int w = 1; w <= W; w++) // 주어진 열 중에서 선택
	{
		// 원본 맵 카피
		Mcopy(target_MAP, copy_MAP);

		// 해당 열에서 처음으로 0이 아닌 곳 찾음
		int top_x = 0;
		for (int row = 1; row <= H; row++)
		{
			if (copy_MAP[row][w] == 0) continue;
			else
			{
				top_x = row;
				break;
			}
		}

		if (top_x == 0)
		{
			zero_count += 1;
			continue;
		}

		// Point p = (x,y) : 터트릴 위치
		Point p = Point(top_x, w);

		// 덱에 추가
		deque<pair<Point, int>> boomque;
		boomque.push_back({ p, copy_MAP[p.first][p.second] });

		// 덱이 빌 때까지: 연쇄 반응
		while (!boomque.empty())
		{
			// 폭발 위치 시작
			Point target_point = boomque.front().first;
			int explode = boomque.front().second - 1;
			boomque.pop_front();

			// 시작 위치 0으로 만듬
			copy_MAP[target_point.first][target_point.second] = 0;

			// 행 탐색: 세로 탐색
			int row_start = max(1, target_point.first - explode);
			int row_end = min(H, target_point.first + explode);
			for (int i = row_start; i <= row_end; i++)
			{
				if (copy_MAP[i][target_point.second] <= 1) copy_MAP[i][target_point.second] = 0;
				else if (copy_MAP[i][target_point.second] > 1)
				{
					// 저장하고
					boomque.push_back({ Point(i,target_point.second), copy_MAP[i][target_point.second]});

					// 맵에 집어넣기
					copy_MAP[i][target_point.second] = 0;
				}
			}

			// 열 탐색: 가로 탐색
			int col_start = max(1, target_point.second - explode);
			int col_end = min(W, target_point.second + explode);
			for (int i = col_start; i <= col_end; i++)
			{
				int tmp_explode = copy_MAP[target_point.first][i];

				if (tmp_explode <= 1) copy_MAP[target_point.first][i] = 0;
				else if (tmp_explode > 1)
				{
					// 폭발 범위 저장하고
					boomque.push_back({ Point(target_point.first, i), tmp_explode });

					// 터트리기
					copy_MAP[target_point.first][i] = 0;
				}
			}
		} // 다 터진 상태

		// 1열을 columns 에 받음
		for (int col = 1; col <= W; col++) {
			// columns
			vector<int> columns;
			// 해당 column 에서 0이 아닌 부분을 모두 받음
			for (int i = 1; i <= H; i++)
			{
				if (copy_MAP[i][col] > 0)
				{
					columns.push_back(copy_MAP[i][col]);
					copy_MAP[i][col] = 0;
				}
			}

			// 해당 열 0인 부분을 없애고 다시 정렬
			int row_idx = 0;
			while (!columns.empty())
			{
				copy_MAP[H - row_idx][col] = columns.back();
				columns.pop_back();
				row_idx += 1;
			}
		}

		// 최종 w 열을 부쉈을 때, map 형태
		Answer = min(Answer, boom(copy_MAP, W, H, left_biz - 1));
	}

	if (zero_count == W) return 0;
	else return Answer;
}

