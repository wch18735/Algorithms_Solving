#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void solution(int test_case);

// 활주로
int h_map[21][21];

// 검사열
int check_seq[21];
int check_reverse[21];

// 구간
struct interval
{
	int start = 0;
	int end = 0;
	int length = end - start + 1;

	interval() {}
	interval(int start, int end) : start(start), end(end) 
	{
		this->length = end - start + 1;
	};
};

// 구간을 가진 벡터
vector<interval> inter_vec;

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
	// 길이, 활주로 가로 길이
	int N, X;
	cin >> N >> X;

	// 정답
	int Answer = 0;

	// 맵에 입력
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> h_map[i][j];
		}
	}

	// 가로 검사
	for (int row = 1; row <= N; row++)
	{
		// 구간 나눔
		int start = 1;
		int end = 1;
		for (int i = 2; i <= N; i++)
		{
			if (h_map[row][start] == h_map[row][i]) end = i;
			else
			{
				inter_vec.push_back(interval(start, end));
				start = i;
				end = i;
			}

			if (i == N) inter_vec.push_back(interval(start, end));
		}

		for (int i = 0; i < (int)inter_vec.size(); i++) cout << inter_vec[i].length << ' ';
		cout << '\n';

		// 행 row 의 최대값
		int max_num = 0;
		for (int i = 1; i <= N; i++) max_num = max(max_num, h_map[row][i]);

		// 만족 못하는 것 존재하면 false
		int possible = true;

		// 구간별 검사 (검사 횟수는 개수 - 1)
		for (int i = 0; i < (int)inter_vec.size()-1; i++)
		{
			// 해당 구간 대표 값
			int current_h = h_map[row][inter_vec[i].start];
			int next_h = h_map[row][inter_vec[i + 1].start];

			// 활주로 길이 X 이상
			if (inter_vec[i].length < X) // 길이가 작은 경우
			{	
				// 최대 값이 아니면 fail
				if (h_map[row][inter_vec[i].start] != max_num)
				{
					possible = false;
				}
			}

			// 높이 차 1
			if (abs(next_h - current_h) != 1) possible = false;
			

			if (possible == false) break;
		}

		inter_vec.clear();

		if (possible == true) Answer += 1;
	}

	cout << '#' << test_case << ' ' << Answer << '\n';
}