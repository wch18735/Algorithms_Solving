#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAXNUM 200000

int find_min(int a, int b, int c, int d) {
	int tmp = min(a, b);
	int tmp2 = min(tmp, c);
	return min(tmp2, d);
}

int main(void) {
	int subin, dong;
	cin >> subin >> dong;
	int dp[200001];
	fill_n(dp, 200001, MAXNUM);

	if (subin > dong) cout << subin - dong;
	else if (subin == dong) cout << 0;
	else {
		for (int i = 0; i <= dong; i++) {
			// subin 좌표 기준 왼쪽, 오른쪽으로 이동하려면 무조건 +1 초씩 필요한 상태
			dp[i] = abs(subin - i);
		}

		//for (int i = 0; i <= dong; i++) cout << dp[i] << ' ';
		//cout << endl;

		for (int i = subin; i <= dong; i++) {
			int value1 = MAXNUM;
			int value2 = MAXNUM;
			int value3 = MAXNUM;

			if (i % 2 == 0) value1 = dp[i / 2] + 1;
			if (i >= 1) value2 = dp[i - 1] + 1;
			if (i < MAXNUM) value3 = dp[i + 1] + 1;

			dp[i] = find_min(value1, value2, value3, dp[i]);
		}

		cout << dp[dong];
	}
	return 0;
}

/*
	dp[i] = minimum(dp[i-1], dp[i+1], dp[i/2]) (if i%2 == 0)
*/

// 반례
// 31 986 : 7
// 31 62 124 123 246 492 493 986
// 