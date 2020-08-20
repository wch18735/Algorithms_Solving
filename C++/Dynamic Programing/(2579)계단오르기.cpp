#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[301];
int step[301];

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &step[i]);
	}

	dp[0] = 0;
	dp[1] = step[1];
	dp[2] = max(step[1] + step[2], step[2]);

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + step[i - 1] + step[i], dp[i - 2] + step[i]);
	}

	printf("%d", dp[n]);

	return 0;
}

/*
	��ȭ���� �����
	��� n ĭ�� �������� ��,
	������ �� �ִ� ���� �� ���� �� �ϳ��̴�.
	1) n-3 ĭ���� 2ĭ �̵� �� 1ĭ �̵�
	2) n-2 ĭ���� 2ĭ �� ���� �̵�

	��,
	dp[n] = dp[n-3] + array[n-1] + array[n]
	dp[n] = dp[n-2] + array[n]

	�� 1ĭ�� �� �� �̻� �ٴ� �� �Ұ����ϱ� ������
*/