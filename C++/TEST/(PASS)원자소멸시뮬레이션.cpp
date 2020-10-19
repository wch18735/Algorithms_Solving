#include<iostream>
#include<map>
#include<vector>

using namespace std;

// 원소 구조체
struct atom {
	int x;
	int y;
	int direction;
	int energy;
};

// 솔루션
void solution(int test_case);

// 맵
int atom_map[4002][4002];

// 원소 배열 (최대 1000개)
atom atom_array[1001];

// 방향 (상하좌우)
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { 1,-1,0,0 };

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
	// 원소 개수
	int N;
	cin >> N;
	int atom_num = N;

	// 입력 
	for (int i = 1; i <= N; i++)
	{
		int x, y, d, e;
		cin >> x >> y >> d >> e;

		atom_array[i].x = (x + 1000) * 2;
		atom_array[i].y = (y + 1000) * 2;
		atom_array[i].direction = d;
		atom_array[i].energy = e;
	}
	
	// 에너지 방출량
	int energy = 0;

	// 원자 이동
	for (int t = 0; t < 4002; t++)
	{
		// 원자 개수 1개이면 충돌 발생X
		if (atom_num <= 1) break;

		// 이동, 겹침 감지
		for (int i = 1; i <= N; i++)
		{
			// 이미 충돌한 원소는 탐색 생략
			if (atom_array[i].direction == -1) continue;

			// 다음 위치
			int nx = atom_array[i].x + dx[atom_array[i].direction];
			int ny = atom_array[i].y + dy[atom_array[i].direction];

			// 다음 위치가 범위 바깥이면 제외
			if (nx < 0 || nx > 4001 || ny < 0 || ny > 4001)
			{
				atom_array[i].direction = -1;
				atom_num -= 1;
				continue;
			}

			if (atom_map[ny][nx] != 0) // 이동 위치에 원소 존재할 때
			{
				// 현재 원소 충돌했으므로 원소 개수 줄여줌
				atom_array[i].direction = -1;
				atom_num -= 1;

				// 에너지 방출
				energy += atom_array[i].energy;

				// 존재했던 원소 방향을 4로 표시
				int idx = atom_map[ny][nx];
				atom_array[idx].direction = 4;
			}
			else // 정상 이동
			{
				// 맵에 이동 표시
				atom_map[ny][nx] = i;

				// 자기 자신 위치 업데이트
				atom_array[i].x = nx;
				atom_array[i].y = ny;
			}
		}

		// 겹친 부분 제거 후 맵에서 지움 (중복 방지)
		for (int i = 1; i <= N; i++)
		{
			// 제외된 원소는 생략
			if (atom_array[i].direction == -1) continue;

			// 해당 원소가 충돌했을 때
			if (atom_array[i].direction == 4)
			{
				// 원소에서 제외
				atom_array[i].direction = -1;

				// 남은 개수 줄여줌
				atom_num -= 1;

				// 방출 에너지 증가
				energy += atom_array[i].energy;

				// 맵 다시 초기화
				atom_map[atom_array[i].y][atom_array[i].x] = 0;
			}
			else // 정상 이동한 원소
			{
				// 맵 초기화
				atom_map[atom_array[i].y][atom_array[i].x] = 0;
			}
		}
	}

	cout << '#' << test_case << ' ' << energy << '\n';
}