#include<iostream>
#include<algorithm>

using namespace std;

// 솔루션
void solution(int test_case);

// 핀 맵
int pin_map[102][102];

// 위치
typedef pair<int, int> Point;
typedef pair<int, int> Direction;

// 함수
int bounce(Point p, Direction d, int N);
Direction block(int n, Direction d);
bool check_start(Point start, Point point);


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		solution(test_case);

		// pin_map 초기화
		for (int i = 0; i <= 101; i++)
		{
			for (int j = 0; j <= 101; j++)
			{
				pin_map[i][j] = 0;
			}
		}
	}
	return 0;
}

void solution(int test_case)
{
	// 가로 길이 N 입력
	int N;
	cin >> N;

	// 맵 초기화
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> pin_map[i][j];
		}
	}

	// 맵 가장자리 5
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			if (i == 0 || i == N + 1) pin_map[i][j] = 5;
			else {
				if (j == 0 || j == N + 1) pin_map[i][j] = 5;
			}
		}
	}
	
	// 답
	int Answer = 0;

	// 방향
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (pin_map[i][j] == 0)
			{
				for (int k = 0; k < 4; k++)
				{
					Answer = max(Answer, bounce(Point(i, j), Direction(dx[k], dy[k]), N));
				}
			}
		}
	}

	cout << '#' << test_case << ' ' <<  Answer << '\n';
}

void print_map(int N)
{
	// 맵 가장자리 5
	cout << '\n';
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			cout << pin_map[i][j] << ' ';
		} cout << '\n';
	}
	cout << '\n';
}

int bounce(Point p, Direction d, int N)
{
	// 튕기는 횟수
	int CNT = 0;
	
	// 시작 지점
	Point start_p = p;

	// 시작 지점을 지나가는 플래그
	bool start_flag = false;

	// 현재 위치에따른 탐색 방향
	while (true)
	{
		// 좌표 프린트
		/*cout << "position: (" << p.first << ' ' << p.second << ")\n";
		cout << "direction: (" << d.first << ' ' << d.second << ")\n";*/

		// 방향에 따른 탐색
		int value = 0; // 해당 위치 값 (0 ~ 10)
		Point next_point; // 다음 위치

		// 오른쪽 (가장 처음 0이 아닌 값 찾기)
		if (d.first == 0 && d.second == 1)
		{
			for (int i = p.second + 1; i <= N + 1; i++)
			{
				// 지나가는 경로에 시작점 있는지 확인
				start_flag = check_start(start_p, Point(p.first, i));

				if (pin_map[p.first][i] != value)
				{
					value = pin_map[p.first][i];
					next_point = Point(p.first, i);
					break;
				}
			}
		}
		
		// 왼쪽 (가장 처음 0이 아닌 값 찾기)
		if (d.first == 0 && d.second == -1)
		{
			for (int i = p.second - 1; i >= 0; i--)
			{
				// 지나가는 경로에 시작점 있는지 확인
				start_flag = check_start(start_p, Point(p.first, i));

				if (pin_map[p.first][i] != value)
				{
					value = pin_map[p.first][i];
					next_point = Point(p.first, i);
					break;
				}
			}
		}

		// 위 (가장 처음 0이 아닌 값 찾기)
		if (d.first == -1 && d.second == 0)
		{
			for (int i = p.first - 1; i >= 0; i--)
			{
				// 지나가는 경로에 시작점 있는지 확인
				start_flag = check_start(start_p, Point(i,p.second));

				if (pin_map[i][p.second] != value)
				{
					value = pin_map[i][p.second];
					next_point = Point(i, p.second);
					break;
				}
			}
		}

		// 아래 (가장 처음 0이 아닌 값 찾기)
		if (d.first == 1 && d.second == 0)
		{
			for (int i = p.first + 1; i <= N+1; i++)
			{
				// 지나가는 경로에 시작점 있는지 확인
				start_flag = check_start(start_p, Point(i, p.second));

				if (pin_map[i][p.second] != value)
				{
					value = pin_map[i][p.second];
					next_point = Point(i, p.second);
					break;
				}
			}
		}

		// 지나가는 경로에 시작점이 있는 경우
		if (start_flag) break;

		// 블랙홀인 경우
		if (value == -1) break;

		// 현재 방향 + 다음 방향 == 0인 경우
		if (value == 5)
		{
			CNT = CNT * 2 + 1;
			break;
		}

		// 블록이면
		if (1 <= value && value <= 4)
		{
			// 블록에 부딪히는 방향에 따른 새로운 방향
			Direction new_d = block(value, d);

			if (d.first + new_d.first == 0 && d.second + new_d.second == 0)
			{
				CNT = CNT * 2 + 1;
				break;
			}
			else {
				CNT += 1;
				p = next_point;
				d = new_d;
				continue;
			}
		}

		// 웜홀이면
		if (6 <= value && value <= 10)
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					if (pin_map[i][j] == value && !(i == next_point.first && j == next_point.second))
					{
						// 웜홀 위치로 초기화
						p = Point(i, j);
						break;
					}
				}
			}
			continue;
		}
	}
	//cout << '\n';
	return CNT;
}

// 해당 좌표가 시작점과 같은 위치인지
bool check_start(Point start, Point point)
{
	return ((start.first == point.first) && (start.second == point.second));
}

// 블록 찾기
Direction block(int n, Direction d)
{
	if (n == 1)
	{
		if (d.first == 0 && d.second == 1) return Direction(0, -1);
		if (d.first == 1 && d.second == 0) return Direction(0, 1);
		if (d.first == 0 && d.second == -1) return Direction(-1, 0);
		if (d.first == -1 && d.second == 0) return Direction(1, 0);
	}
	else if (n == 2)
	{
		if (d.first == 0 && d.second == 1) return Direction(0, -1);
		if (d.first == 1 && d.second == 0) return Direction(-1, 0);
		if (d.first == 0 && d.second == -1) return Direction(1, 0);
		if (d.first == -1 && d.second == 0) return Direction(0, 1);
	}
	else if (n == 3)
	{
		if (d.first == 0 && d.second == 1) return Direction(1, 0);
		if (d.first == 1 && d.second == 0) return Direction(-1, 0);
		if (d.first == 0 && d.second == -1) return Direction(0, 1);
		if (d.first == -1 && d.second == 0) return Direction(0, -1);
	}
	else if (n == 4)
	{
		if (d.first == 0 && d.second == 1) return Direction(-1, 0);
		if (d.first == 1 && d.second == 0) return Direction(0, -1);
		if (d.first == 0 && d.second == -1) return Direction(0, 1);
		if (d.first == -1 && d.second == 0) return Direction(1, 0);
	}
	else if (n == 5)
	{
		if (d.first == 0 && d.second == 1) return Direction(0, -1);
		if (d.first == 1 && d.second == 0) return Direction(-1, 0);
		if (d.first == 0 && d.second == -1) return Direction(0, 1);
		if (d.first == -1 && d.second == 0) return Direction(1, 0);
	}
}