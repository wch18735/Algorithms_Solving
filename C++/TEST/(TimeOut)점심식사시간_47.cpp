#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 타입
struct Person
{
	int x,y,arrive;
};

// 사람 위치와 도착시간을 가지는 배열
Person p_arr[10];

// 거리에 따른 도착 큐
deque<Person> a_q;
deque<Person> b_q;

// 계단
struct Stair
{
	int x, y,k;
};

// 맵
int MAP[11][11];

// 솔루션
void solution(int test_case);

// 비교함수
bool compare(Person a, Person b)
{
	return a.arrive < b.arrive;
}

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
	// 정사각형 길이
	int N;
	cin >> N;

	// 사람 수
	int person_num = 0;

	// 계단 수
	Stair a;
	Stair b;
	int s_num = 0;

	// 입력
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> MAP[i][j];
			
			if (MAP[i][j] == 1) // 사람 저장
			{
				Person p;
				p.x = i;
				p.y = j;
				p.arrive = 0;

				p_arr[person_num] = p;
				person_num += 1;
			}
			else if (MAP[i][j] > 1) // 사람 저장
			{
				Stair s;
				s.x = i;
				s.y = j;
				s.k = MAP[i][j];
				if (s_num == 0)
				{
					a = s;
					s_num += 1;
				}
				else
				{
					b = s;
					s_num += 1;
				}
			}
		}
	}

	// 걸리는 시간
	int time = 10000;

	for (int i = 0; i <= person_num; i++) // 조합
	{
		vector<int> permt;
		for (int j = 0; j < person_num-i; j++) permt.push_back(0);
		for (int j = 0; j < i; j++) permt.push_back(1);
		sort(permt.begin(), permt.end());

		do{// 퍼뮤테이션 적용
			for (int p_idx = 0; p_idx < person_num; p_idx++)
			{
				// 도착시간 업데이트
				if (permt[p_idx] == 0)
				{
					p_arr[p_idx].arrive = abs(p_arr[p_idx].x - a.x) + abs(p_arr[p_idx].y - a.y);
					a_q.push_back(p_arr[p_idx]);
				}
				else
				{
					p_arr[p_idx].arrive = abs(p_arr[p_idx].x - b.x) + abs(p_arr[p_idx].y - b.y);
					b_q.push_back(p_arr[p_idx]);
				}
			}

			//cout << a_q.size() << ' ' << b_q.size() << '\n';

			// 도착시간별로 정렬
			sort(a_q.begin(), a_q.end(), compare);
			sort(b_q.begin(), b_q.end(), compare);

			// 가장 마지막 도착한 사람이 내려가는 시간 계산
			int a_last = 0; // 가장 끝사람이 도착했을 때, 가장 먼저있던 사람이 이동완료 시간
			while ((int)a_q.size() > 3 && !a_q.empty())
			{
				a_last = max(a_last + a.k, a_q.front().arrive + 1 + a.k);
				a_q.pop_front();
			}
			if (!a_q.empty()) a_last = max(a_last + a.k, a_q.back().arrive + 1 + a.k);

			int b_last = 0; // 가장 끝사람이 도착했을 때, 가장 먼저있던 사람이 이동완료 시간
			while ((int)b_q.size() > 3 && !b_q.empty())
			{
				b_last = max(b_last + b.k, b_q.front().arrive + 1 + b.k);
				b_q.pop_front();
			}
			if (!b_q.empty()) b_last = max(b_last + b.k, b_q.back().arrive + 1 + b.k);

			time = min(max(a_last, b_last), time);

			// 전역 변수 클리어
			a_q.clear();
			b_q.clear();

		} while (next_permutation(permt.begin(), permt.end()));
	}

	cout << "#" << test_case << ' ' << time << '\n';
}
