#include<iostream>
#include<deque>
#include<math.h>

using namespace std;

// 솔루션
void solution(int test_case);

// 마그넷
struct magnet {
	deque<int> polar;
};

// 자석 배열
magnet mg_array[5];

// 회전
struct rot
{
	int mg_num;
	int direction;
};
rot rot_array[20];

// 회전 체크
int chk[5];

void rotation(int mg_num, int dir);

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
	// 회전 수
	int K;
	cin >> K;

	// 입력
	int polar;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			cin >> polar;
			mg_array[i].polar.push_back(polar);
		}
	}

	// 회전 방향
	int mg_num, dir;
	for (int i = 0; i < K; i++)
	{
		cin >> mg_num >> dir;

		rotation(mg_num, dir);
	}

	// 답
	int answer = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (mg_array[i].polar[0] == 1) answer += (int)pow(2, i - 1);
	}

	// 클리어
	for (int i = 1; i <= 4; i++)
	{
		mg_array[i].polar.clear();
	}

	cout << '#' << test_case << ' ' << answer << '\n';
}

void rotation(int mg_num, int dir)
{
	// 왼쪽 오른쪽 노드
	int left_mg = mg_num - 1;
	int right_mg = mg_num + 1;

	// 현재 자석 회전
	chk[mg_num] = 1;

	// 좌측 가능 체크
	bool left_flag = false;
	if (left_mg > 0 && mg_array[left_mg].polar[2] != mg_array[mg_num].polar[6] && chk[left_mg] == 0) left_flag = true;

	// 우측 가능 체크
	bool right_flag = false;
	if (right_mg <= 4 && mg_array[mg_num].polar[2] != mg_array[right_mg].polar[6] && chk[right_mg] == 0) right_flag = true;

	// flag 에 따른 함수 호출
	if (left_flag) rotation(left_mg, (-1) * dir);
	if (right_flag) rotation(right_mg, (-1) * dir);

	// 자기 mg_num 위치 회전
	if (dir == 1) // 시계방향
	{
		mg_array[mg_num].polar.push_front(mg_array[mg_num].polar.back());
		mg_array[mg_num].polar.pop_back();
	}
	else if (dir == -1) // 반시계방향
	{
		mg_array[mg_num].polar.push_back(mg_array[mg_num].polar.front());
		mg_array[mg_num].polar.pop_front();
	}

	// chk 초기화
	chk[mg_num] = 0;
}
