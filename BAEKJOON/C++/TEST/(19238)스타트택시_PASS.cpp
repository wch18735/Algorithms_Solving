#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/******** 맵과 자료형 *********/
// 맵
int MAP[21][21];

// 방문 체크용 맵
int CHMAP[21][21];

// 거리맵
int DMAP[21][21];

// (위치행, 위치열),(목표행, 목표열)
typedef pair<pair<int, int>, pair<int, int>> sonnim_info;
typedef pair<int, int> pos;


/******** 함수 *********/
// solution 선언
void solution();
void update_map(pos a);
void print_map(int TARGET[21][21], int n);
void init_map(int N_Size);
bool compare(pair<sonnim_info,int> a, pair<sonnim_info,int> b) // 비교 함수
{
	if (a.second == b.second) // 거리가 같을 때
	{
		// ( (손님 위치, 손님 목적지), 거리)
		if (a.first.first.first == b.first.first.first) return a.first.first.second < b.first.first.second;// 행이 같을 때
		else return a.first.first.first < b.first.first.first; // 행 번호가 작은 사람
	}
	else return a.second < b.second; // 거리가 짧은 쪽
}

int main(void)
{
	solution();

	return 0;
}

void update_map(pos a, int N)
{
	// 행과 열
	int row = a.first;
	int col = a.second;

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	// position 위치
	deque<pair<int, int>> pos_queue;

	// 처음 위치 초기화
	DMAP[row][col] = 0; // 거리 0
	CHMAP[row][col] = 1; // 방문함

	// 큐에 추가
	pos_queue.push_back({ row, col });

	// 맵 업데이트
	while (!pos_queue.empty())
	{
		// 큐
		pos now_point = pos_queue.front();
		pos_queue.pop_front();
		int x = now_point.first;
		int y = now_point.second;

		// 네 방향 검사
		for (int i = 0; i < 4; i++)
		{
			int tmp_x = x + dx[i];
			int tmp_y = y + dy[i];
			pos next_pos = { tmp_x, tmp_y };
			if (!(1 <= tmp_x && tmp_x <= N)) continue; // 맵 끝
			if (!(1 <= tmp_y && tmp_y <= N)) continue; // 맵 끝
			if (CHMAP[tmp_x][tmp_y] != 0) continue; // 방문했던 곳
			if (MAP[tmp_x][tmp_y] == 1) continue; // 벽

			pos_queue.push_back(next_pos); // 큐에 다음 추가
			DMAP[tmp_x][tmp_y] = DMAP[x][y] + 1; // 해당 위치는 거리 + 1
			CHMAP[tmp_x][tmp_y] = 1;
		}
	}
}

void init_map(int N_size)
{
	for (int i = 1; i <= N_size; i++)
	{
		for (int j = 1; j <= N_size; j++)
		{
			DMAP[i][j] = 0;
			CHMAP[i][j] = 0;
		}
	}
}

void print_map(int TARGET[21][21], int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << TARGET[i][j] << ' ';
		} cout << '\n';
	}
}

bool check_visit(pos a) // 해당 위치를 택시가 방문할 수 있는지
{
	return CHMAP[a.first][a.second] == 1;
}

void solution()
{
	int N, M, Fuel;
	cin >> N >> M >> Fuel;

	// 맵 입력
	for (int i = 1; i <= N; i++) // 행 좌표
	{
		for (int j = 1; j <= N; j++) // 열 좌표
		{
			cin >> MAP[i][j];
		}
	}

	// 택시 위치 입력
	pair<int, int> taxi_pos;
	cin >> taxi_pos.first >> taxi_pos.second;

	// 승객 입력
	deque <pair<sonnim_info, int>> sonnim_list; // 손님 정보 + 거리
	sonnim_info sonnim; 
	for (int i = 0; i < M; i++)
	{
		cin >> sonnim.first.first >> sonnim.first.second >> sonnim.second.first >> sonnim.second.second;
		sonnim_list.push_back({ sonnim, 0 });
	}

	bool fail = false;

	while (!sonnim_list.empty())
	{

		// 택시 위치로 업데이트
		update_map(taxi_pos, N);

		// sonnim_list 에 있는 위치들 모두 업데이트
		for (int i = 0; i < (int)sonnim_list.size(); i++)
		{
			// 손님 정보 얻기
			sonnim = sonnim_list[i].first;
			int x = sonnim.first.first; // 손님 위치 행
			int y = sonnim.first.second; // 손님 위치 열

			// 택시 ~ 손님 거리 업데이트
			sonnim_list[i].second = DMAP[x][y];
		}

		// 거리 -> 행 -> 열 순서로 sort
		sort(sonnim_list.begin(), sonnim_list.end(), compare);

		// 택시가 태울 손님 뽑기
		sonnim = sonnim_list.front().first;
		int d = sonnim_list.front().second;
		sonnim_list.pop_front(); // 뽑은 것 지우기

		// 택시가 손님을 태울 수 있는지 확인 (막혀있는지 여부)
		if (!check_visit(sonnim.first))
		{
			fail = true;
			break;
		}

		// 거리 맵을 다시 업데이트
		init_map(N);

		// 승객 정보로 거리 업데이트
		update_map(sonnim.first, N);

		// 택시가 손님을 목적지로 데려다 줄 수 있는지 확인
		if (!check_visit(sonnim.second))
		{
			fail = true;
			break;
		}

		// 목표 위치까지 거리
		int target_x = sonnim.second.first;
		int target_y = sonnim.second.second;
		int d_t = DMAP[target_x][target_y];

		// 연료 판단
		if (Fuel - d - d_t >= 0)
		{
			Fuel = Fuel - d + d_t; // 연료 업데이트
			taxi_pos = sonnim.second; // 택시 위치를 목적지로
		}
		else
		{
			fail = true;
			break;
		}

		// 맵 초기화
		init_map(N);
	}

	if (fail == true) cout << -1;
	else cout << Fuel;
	
	return;
}