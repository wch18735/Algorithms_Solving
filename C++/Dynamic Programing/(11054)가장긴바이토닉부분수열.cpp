#include <iostream>
#include <algorithm>

using namespace std;

void PrintArr(int* numArr,int n) {
	for (int i = 0; i < n; i++) cout << numArr[i] << endl;
}

int main(void) {
	int dp_LIS[1001] = { 0 };
	int dp_LDS[1001] = { 0 };
	int numArr[1001] = { 0 };

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> numArr[i];

	int max_len = 0;
	
	for (int i = 0; i < n; i++) { // Longest Increasing Sequence
		int previos_max_length = 0;
		for (int j = 0; j < i; j++) {
			if (numArr[i] /* ���� */ > numArr[j] /* ���� �� �� */) {
				if (previos_max_length <= dp_LIS[j]) previos_max_length = dp_LIS[j];
			}
		}
		dp_LIS[i] = previos_max_length + 1;
		if (max_len < dp_LIS[i]) max_len = dp_LIS[i];
	}

	for (int i = n - 1; i >= 0; i--) { // Longest decreasing Sequence
		int previos_max_length = 0;
		for (int j = n - 1; j >= i; j--) {
			if (numArr[i] /* ���� */ > numArr[j] /* ���� �� �� */) {
				if (previos_max_length <= dp_LDS[j]) previos_max_length = dp_LDS[j];
			}
		}
		dp_LDS[i] = previos_max_length + 1; // int p_m_l = 0 -> dp[idx] = p_m_l + 1 �� ���� �ּ� �� 1 Ȯ��
		if (max_len < dp_LDS[i]) max_len = dp_LDS[i];
	}

	int Answer = 0;
	for (int i = 0; i < n; i++) {
		if (Answer < dp_LDS[i] + dp_LIS[i]) Answer = dp_LDS[i] + dp_LIS[i];
	}

	cout << Answer - 1; // �ִ� ���� ��ġ�� ������ -1 �־���

	return 0;
}

// (1) DP�� �̿�
// (2) Input ������ �Ųٷ� �ϸ� LIS -> LDS ���� �� ����
// (3) DP�� �� �� �� ����ؼ� �� ���� DP�� �� ���� �ִ븦 ã��
// (4) dp_LIS[i] + dp_LDS[i] - 1 : �ش� ��ġ���� �ִ� ���� + �� ���� ���� (����) - 1 (��ģ �� ����)