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
				// 해당 위치가 서로 같으면
				// 둘 다 없었을 때의 LCS에서 +1 값과 같음
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				// 해당 위치가 서로 다르면
				// 둘 중 하나가 없었을 때 중
				// LCS 값이 더 큰 것으로 대입
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	cout << dp[s1.length()][s2.length()];

	return 0;
}

// 이차원 DP
// https://hsp1116.tistory.com/37
// 모든 DP -> LCS 이다
// 즉, 해당 인덱스까지는 최장 공통 수열이 보장되어있다