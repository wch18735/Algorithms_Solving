#include<iostream>
#include<algorithm>

using namespace std;

int dp[30+1][15000+1];
int chNum, guNum;
int chArr[30+1];
int guArr[7+1];

void check_weight(int chuIndex, int currentWeight)
{
	// 방문했음 == 가능 (추 번호 chuIndex 개를 사용했을 때, currentWeight 가능)
	if (dp[chuIndex][currentWeight] == 1) return;
	else dp[chuIndex][currentWeight] = 1;

	// 주어진 추 개수보다 많을 때 탐색 끝
	if (chuIndex == chNum) return;

	// 왼쪽/놓지않음/오른쪽
	check_weight(chuIndex + 1, abs(currentWeight - chArr[chuIndex+1]));
	check_weight(chuIndex + 1, currentWeight);
	check_weight(chuIndex + 1, currentWeight + chArr[chuIndex+1]);
}

int main(void)
{
	cin >> chNum;
	for (int i = 1; i <= chNum; i++) cin >> chArr[i];

	cin >> guNum;
	for (int i = 1; i <= guNum; i++) cin >> guArr[i];

	// 메모리 초기화: -1 (불가능) or 1 (가능)
	// 주어진 추 조건으로 구할 수 있는 모든 경우 구함
	// check_weight(1, chArr[1]) => 오답: 맨 처음 추도 놓지 않을 수 있음
	check_weight(0, 0);

	for (int i = 1; i <= guNum; i++)
	{
		if (guArr[i] > 15000) cout << "N ";
		else {
			if (dp[chNum][guArr[i]] == 1) cout << "Y ";
			else cout << "N ";
		}
	}

	return 0;
}

// REFERENCE: https://www.acmicpc.net/board/view/39785