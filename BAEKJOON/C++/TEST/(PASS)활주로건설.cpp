#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void solution(int test_case);

// 활주로
int h_map[21][21];

// 구간
struct interval
{
	int start = 0;
	int end = 0;
	int length = end - start + 1;
	int r = 0; // 구간의 대표 값

	interval() {}
	interval(int start, int end, int represent) : start(start), end(end), r(represent)
	{
		this->length = end - start + 1;
		this->r = represent;
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

	// 행 검사
	for (int row = 1; row <= N; row++)
	{
		// 구간을 나누고 대표 값을 얻음
		int start = 1;
		int end = 1;
		for (int i = 1; i <= N; i++)
		{
			if (h_map[row][start] == h_map[row][i]) end = i;
			else
			{
				inter_vec.push_back(interval(start, end, h_map[row][start]));
				start = i;
				end = i;
			}

			if (i == N) inter_vec.push_back(interval(start, N, h_map[row][start]));
		}

		bool possible = true;

		// 각 구간별로 오른쪽 검사
		for (int i = 0; i < (int)inter_vec.size() - 1; i++)
		{
			if (inter_vec[i].r < inter_vec[i + 1].r)
			{
				// 높이 차이 1일 때, 건설 불가능하면 fail (높이 차이 1인 구간은 무조건 건설시도)
				if (abs(inter_vec[i].r - inter_vec[i + 1].r) == 1)
				{
					if (inter_vec[i].length >= X)
					{
						inter_vec[i].length -= X;
					}
					else {
						possible = false;
					}
				}
				else possible = false;
			}

			if (inter_vec[i].r > inter_vec[i + 1].r)
			{
				// 높이 차이 1일 때, 건설 불가능하면 fail (높이 차이 1인 구간은 무조건 건설시도)
				if (abs(inter_vec[i].r - inter_vec[i + 1].r) == 1)
				{
					if (inter_vec[i + 1].length >= X)
					{
						inter_vec[i + 1].length -= X;
					}
					else {
						possible = false;
					}
				}
				else possible = false;
			}
		}
		
		if ((int)inter_vec.size() == 1) Answer += 1;
		else if (possible) Answer += 1;
		//if (possible) cout << "success row in " << row << '\n';
		inter_vec.clear();
	}

	// 열검사
	for (int col = 1; col <= N; col++)
	{
		// 구간을 나누고 대표 값을 얻음
		int start = 1;
		int end = 1;
		for (int i = 1; i <= N; i++)
		{
			if (h_map[start][col] == h_map[i][col]) end = i;
			else
			{
				inter_vec.push_back(interval(start, end, h_map[start][col]));
				start = i;
				end = i;
			}

			if (i == N) inter_vec.push_back(interval(start, N, h_map[start][col]));
		}

		bool possible = true;

		// 각 구간별로 오른쪽 검사
		for (int i = 0; i < (int)inter_vec.size() - 1; i++)
		{
			if (inter_vec[i].r < inter_vec[i + 1].r)
			{
				// 높이 차이 1일 때, 건설 불가능하면 fail (높이 차이 1인 구간은 무조건 건설시도)
				if (abs(inter_vec[i].r - inter_vec[i + 1].r) == 1)
				{
					if (inter_vec[i].length >= X)
					{
						inter_vec[i].length -= X;
					}
					else {
						possible = false;
					}
				}
				else possible = false;
			}

			if (inter_vec[i].r > inter_vec[i + 1].r)
			{
				// 높이 차이 1일 때, 건설 불가능하면 fail (높이 차이 1인 구간은 무조건 건설시도)
				if (abs(inter_vec[i].r - inter_vec[i + 1].r) == 1)
				{
					if (inter_vec[i + 1].length >= X)
					{
						inter_vec[i + 1].length -= X;
					}
					else {
						possible = false;
					}
				}
				else possible = false;
			}
		}

		if ((int)inter_vec.size() == 1) Answer += 1;
		else if (possible) Answer += 1;
		//if (possible) cout << "success column in " << col << '\n';
		inter_vec.clear();
	}


	cout << '#' << test_case << ' ' << Answer << '\n';
}