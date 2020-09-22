#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);

	int grape[10000];
	int dp[10000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &grape[i]);
	}

	dp[0] = grape[0];
	dp[1] = grape[0] + grape[1];
	dp[2] = max({ grape[0] + grape[1], grape[0] + grape[2], grape[1] + grape[2] });

	for (int i = 3; i < n; i++) {
		dp[i] = max({ dp[i - 3] + grape[i - 1] + grape[i],dp[i - 2] + grape[i], dp[i - 1] });
	}

	printf("%d", dp[n - 1]);

	return 0;
}

/*
	dp[idx] (idx���� �ִ�) �� ������ ��
	1) dp[idx-3] + grape[idx-1] + grape[idx]
	2) dp[idx-2] + grape[idx]
	3) dp[idx-1]

	dp[idx]: idx ��ġ���� ���ô� �� ���ô� ȥ�յ� ����
	�� ������ �и��� �����Ǵ� �� �������� dp �� ���� ����
*/