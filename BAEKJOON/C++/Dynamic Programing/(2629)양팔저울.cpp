#include<iostream>
#include<algorithm>

using namespace std;

int dp[30+1][15000+1];
int chNum, guNum;
int chArr[30+1];
int guArr[7+1];

void check_weight(int chuIndex, int currentWeight)
{
	// �湮���� == ���� (�� ��ȣ chuIndex ���� ������� ��, currentWeight ����)
	if (dp[chuIndex][currentWeight] == 1) return;
	else dp[chuIndex][currentWeight] = 1;

	// �־��� �� �������� ���� �� Ž�� ��
	if (chuIndex == chNum) return;

	// ����/��������/������
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

	// �޸� �ʱ�ȭ: -1 (�Ұ���) or 1 (����)
	// �־��� �� �������� ���� �� �ִ� ��� ��� ����
	// check_weight(1, chArr[1]) => ����: �� ó�� �ߵ� ���� ���� �� ����
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