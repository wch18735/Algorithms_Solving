#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	// n x n matrix initialized to 0
	vector<vector<int>> dp(1001);
	vector<int> sub_dp(1001,0);
	for (int i = 0; i < 1001; i++) dp[i] = sub_dp;

	string s1;
	string s2;
	
	cin >> s1;
	cin >> s2;

	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) { 
				// �ش� ��ġ�� ���� ������
				// �� �� ������ ���� LCS���� +1 ���� ����
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				// �ش� ��ġ�� ���� �ٸ���
				// �� �� �ϳ��� ������ �� ��
				// LCS ���� �� ū ������ ����
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	cout << dp[s1.length()][s2.length()];

	return 0;
}

// ������ DP
// https://hsp1116.tistory.com/37
// ��� DP -> LCS �̴�
// ��, �ش� �ε��������� ���� ���� ������ ����Ǿ��ִ�