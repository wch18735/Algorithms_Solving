#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int numArr[1001];
int Answer;
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> numArr[i];

		int len = 0;
		for (int j = 0; j < i; j++) {
			if (numArr[i] > numArr[j]) len = max(len, dp[j]);
		}
		dp[i] = len + 1;
		Answer = max(dp[i], Answer);
	}

	cout << Answer;

	return 0;
}