#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

// 솔루션
void solution(int test_case);

// 도시
int city[21][21];

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
	// 도시 크기와 집 하나당 지불 가능 비용
	int N, M;
	cin >> N >> M;

	// 입력
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> city[i][j];
		}
	}

	// 최대 집 개수
	int house = 0;

	// K 만큼 판단
	for (int k = 1; k <= N+1; k++)
	{
		int cost = k * k + (k - 1) * (k - 1);

		// city의 모든 좌표
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				// 운영범위 내부 가능한 집 개수
				int cnt = 0;

				// city[i][j] 기준으로 운영범위 탐색
				for (int row = max(1, i - k + 1); row <= min(N, i + k - 1); row++)
				{
					for (int col = max(1, j - k + 1); col <= min(N, j + k - 1); col++)
					{
						if (abs(i - row) + abs(j - col) < k && city[row][col] == 1)
						{
							cnt += 1;
						}
					}
				}

				// 운영 비용 판단 (같을 때도 포함!!)
				if (M * cnt - cost >= 0 && cnt > house) house = cnt;
			}
		}
	}

	cout << '#' << test_case << ' ' << house << '\n';

	// 전역 변수 초기화
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			city[i][j] = 0;
		}
	}
}