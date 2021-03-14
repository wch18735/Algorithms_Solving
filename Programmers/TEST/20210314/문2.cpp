#include<iostream>
#include<algorithm>

using namespace std;

int dp[100000];
int arr[100000];
int chk[100000];
int N;

int main(void)
{
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	// 최대 주기
	int res = 0;

	// 탐색
	for (int i = 1; i <= N; i++)
	{
		// 현재 위치
		int cur_p = i;
		
		// 주기
		int cnt = 0;

		// 발판 초기화
		fill(chk, chk + N, 0);

		// 발판 밟기
		int period_flag = 0;
		while (chk[cur_p] != -1)
		{
			// 방문 한 곳으로 바꿈
			chk[cur_p] = -1;

			// 현재 위치에서 주기를 알 수 있는지 확인
			if (dp[cur_p] != 0)
			{
				// 주기 체크 플래그 ON
				period_flag = 1;
				break;
			}

			// 현재 위치 변경
			cur_p += arr[cur_p];
		}

		// 변경 된 해당 위치부터 주기 체크
		if (period_flag != 1)
		{
			int start = cur_p;
			cur_p += arr[cur_p];
			cnt += 1;
			while (start != cur_p)
			{
				cur_p += arr[cur_p];
				cnt += 1;
			}

			// 해당 위치에서의 주기 삽입
			dp[start] = cnt;
			res = max(cnt, res);
		}
		else
		{
			// 현재 위치에 주기 삽입
			dp[i] = dp[cur_p];
			res = max(dp[i], res);
		}
	}

	cout << res;

	return 0;
}