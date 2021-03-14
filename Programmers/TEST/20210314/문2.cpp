#include<iostream>
#include<algorithm>

using namespace std;

int dp[100000];
int arr[100000];
int chk[100000];
int N;

int main(void)
{
	// �Է�
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	// �ִ� �ֱ�
	int res = 0;

	// Ž��
	for (int i = 1; i <= N; i++)
	{
		// ���� ��ġ
		int cur_p = i;
		
		// �ֱ�
		int cnt = 0;

		// ���� �ʱ�ȭ
		fill(chk, chk + N, 0);

		// ���� ���
		int period_flag = 0;
		while (chk[cur_p] != -1)
		{
			// �湮 �� ������ �ٲ�
			chk[cur_p] = -1;

			// ���� ��ġ���� �ֱ⸦ �� �� �ִ��� Ȯ��
			if (dp[cur_p] != 0)
			{
				// �ֱ� üũ �÷��� ON
				period_flag = 1;
				break;
			}

			// ���� ��ġ ����
			cur_p += arr[cur_p];
		}

		// ���� �� �ش� ��ġ���� �ֱ� üũ
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

			// �ش� ��ġ������ �ֱ� ����
			dp[start] = cnt;
			res = max(cnt, res);
		}
		else
		{
			// ���� ��ġ�� �ֱ� ����
			dp[i] = dp[cur_p];
			res = max(dp[i], res);
		}
	}

	cout << res;

	return 0;
}