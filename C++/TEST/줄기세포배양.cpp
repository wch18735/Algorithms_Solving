#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

// 솔루션
void solution(int test_case);

// 맵
int info_map[370][370];	// information
int na_map[370][370];	// non-activate
int a_map[370][370];	// activate

// 맵 출력
void printMap(int map[370][370]);

// 맵 클리어
void clear_map(int map[370][370]);

// 디폴트
#define base 160

// 위치 자료형 지정
typedef pair<int, int> Point;

// 큐
deque<pair<Point, int>> bunsikQ; // 번식큐
deque<pair<Point, int>> next_bunsikQ; // 넥스트 번식큐
deque<pair<Point, int>> non_activeQ; // 비활성큐
deque<pair<Point, int>> activeQ; // 활성큐

// count
int count_non(int map[370][370]);
int count_active(int map[370][370]);

// 방향
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = {0, 1, 0, -1};

// 비교 함수
bool compare(pair<Point, int> a, pair<Point, int> b)
{
	// 생명력 내림 차순
	return a.second > b.second;
}

/* ------------------------------------------------- */
/* ------------------------------------------------- */

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// 솔루션
		solution(test_case);

		// 전역 맵 클리어
		for (int i = 0; i < 370; i++)
		{
			for (int j = 0; j < 370; j++)
			{
				info_map[i][j] = 0;
				na_map[i][j] = 0;
				a_map[i][j] = 0;
			}
		}

		// 전역 큐 클리어
		bunsikQ.clear();
		non_activeQ.clear();
		activeQ.clear();
	}

	return 0;
}

/* ------------------------------------------------- */
/* ------------------------------------------------- */

// 솔루션
void solution(int test_case)
{
	// 입력
	int N, M, K; // 세로, 가로, 시간
	cin >> N >> M >> K;

	// 초기 맵 입력 (초기: 비활성 큐에 넣음)
	for (int i = 0; i < N; i++) // 세로
	{
		for (int j = 0; j < M; j++) // 가로
		{
			// base 기준으로 입력
			cin >> info_map[base + i][base + j];

			// 생명력이 있는 칸이라면 비활성 큐로 넣음
			if (info_map[base + i][base + j] != 0) non_activeQ.push_back({ Point(base + i,base + j),info_map[base + i][base + j] });
		}
	}

	// K 시간 후
	// K = 1 이면 1시간동안 진행한 것
	for (int time = 0; time <= K; time++)
	{
		// ************ 정보 맵 업데이트 ***************
		while(!bunsikQ.empty())
		{
			// 번식된 위치 받아옴
			Point point = bunsikQ.front().first; // 생명력 내림차순으로 정렬: 점점 작아짐
			int life = bunsikQ.front().second;

			// 해당 노드 없앰
			bunsikQ.pop_front();

			// 해당 위치 0인지 확인
			if (info_map[point.first][point.second] == 0)
			{
				// 해당 위치에 번식 가능하면 집어 넣음
				info_map[point.first][point.second] = life;

				// 이를 비활성 큐에 넣음
				non_activeQ.push_back({ point, life });
			}
		
		}



		// ************* 비활성 맵 업데이트 ***********
		// 0보다 큰 곳 -1 하는 데, 이때 뺀 값이 0이 되면 (활성이면) 활성 큐에 넣음
		for (int i = 0; i < 370; i++)
		{
			for (int j = 0; j < 370; j++)
			{
				if (na_map[i][j] > 0)
				{
					na_map[i][j] -= 1;
					if (na_map[i][j] == 0) activeQ.push_back({ Point(i,j), info_map[i][j] });
				}
			}
		}
		
		while (!non_activeQ.empty()) 
		{
			// 큐에서 빼냄
			Point point = non_activeQ.front().first;
			int life = non_activeQ.front().second;
			non_activeQ.pop_front(); // 제거


			// 위치에 모두 넣음
			na_map[point.first][point.second] = life;
		}

		// *********** 활성 맵 업데이트 *************
		for (int i = 0; i < 370; i++) // 이전에 들어온 0보다 큰 것들 -1
		{
			for (int j = 0; j < 370; j++)
			{
				if (a_map[i][j] > 0)
				{
					a_map[i][j] -= 1;
				}
			}
		}
		
		//// 넥스트 번식 큐에서 번식 큐로 이동
		//while (!next_bunsikQ.empty())
		//{
		//	bunsikQ.push_back(next_bunsikQ.front());
		//	next_bunsikQ.pop_front();
		//}

		// 들어온 만큼 뽑아서 활성 맵에 생명력 넣음
		while (!activeQ.empty()) 
		{
			// 좌표
			Point point = activeQ.front().first;
			int life = activeQ.front().second;
			activeQ.pop_front();

			// 맵 위치에 생명력 넣음
			a_map[point.first][point.second] = life;

			// 번식 큐에 네 방향 넣음
			for (int i = 0; i < 4; i++)
			{
				// 이미 자리가 있다면
				if (info_map[point.first + dx[i]][point.second + dy[i]] != 0) continue;

				// 넥스트 번식 큐에 네 방향 집어 넣음
				bunsikQ.push_back({ Point(point.first + dx[i], point.second + dy[i]), life });
			}
		}

		// 생명력 순으로 sort
		sort(bunsikQ.begin(), bunsikQ.end(), compare);

		//printMap(info_map);
		/*cout << "non active: " << count_non(na_map) << '\n';
		cout << "active: " << count_active(a_map) << '\n';
		cout << '\n';*/
	}

	// 비활성 맵과 활성 맵에서 0보다 큰 것
	int Answer = 0;
	for (int i = 0; i < 370; i++)
	{
		for (int j = 0; j < 370; j++)
		{
			if (na_map[i][j] > 0)
			{
				Answer += 1;
			}
			if (a_map[i][j] > 0)
			{
				Answer += 1;
			}
		}
	}

	cout << '#' << test_case << ' ' << Answer << '\n';
}

// 맵 출력 (140 ~ 210)
void printMap(int map[370][370])
{
	cout << '\n';
	for (int i = 140; i < 210; i++)
	{
		for (int j = 140; j < 210; j++)
		{
			cout << map[i][j] << ' ';
		} cout << '\n';
	}
	cout << '\n';
}

// 개수 세기
int count_non(int map[370][370])
{
	int non = 0;
	for (int i = 0; i < 370; i++)
	{
		for (int j = 0; j < 370; j++)
		{
			if (map[i][j] > 0)
			{
				non += 1;
			}
		}
	}
	return non;
}

int count_active(int map[370][370])
{
	int active = 0;
	for (int i = 0; i < 370; i++)
	{
		for (int j = 0; j < 370; j++)
		{
			if (map[i][j] > 0)
			{
				active += 1;
			}
		}
	}
	return active;
}

// 배운 점
// 1) test_case 가 많기 때문에 전역 변수는 항상 클리어하는 습관!!
// 2) 글로벌 함수를 다시 초기화하는 방법
// 3) 진짜 전역변수 클리어가 제일 중요...