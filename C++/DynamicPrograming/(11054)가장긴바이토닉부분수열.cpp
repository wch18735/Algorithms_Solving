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
			if (numArr[i] /* 기준 */ > numArr[j] /* 이전 값 비교 */) {
				if (previos_max_length <= dp_LIS[j]) previos_max_length = dp_LIS[j];
			}
		}
		dp_LIS[i] = previos_max_length + 1;
		if (max_len < dp_LIS[i]) max_len = dp_LIS[i];
	}

	for (int i = n - 1; i >= 0; i--) { // Longest decreasing Sequence
		int previos_max_length = 0;
		for (int j = n - 1; j >= i; j--) {
			if (numArr[i] /* 기준 */ > numArr[j] /* 이전 값 비교 */) {
				if (previos_max_length <= dp_LDS[j]) previos_max_length = dp_LDS[j];
			}
		}
		dp_LDS[i] = previos_max_length + 1; // int p_m_l = 0 -> dp[idx] = p_m_l + 1 을 통해 최소 값 1 확보
		if (max_len < dp_LDS[i]) max_len = dp_LDS[i];
	}

	int Answer = 0;
	for (int i = 0; i < n; i++) {
		if (Answer < dp_LDS[i] + dp_LIS[i]) Answer = dp_LDS[i] + dp_LIS[i];
	}

	cout << Answer - 1; // 최대 값이 겹치기 때문에 -1 넣어줌

	return 0;
}

// (1) DP를 이용
// (2) Input 순서만 거꾸로 하면 LIS -> LDS 만들 수 있음
// (3) DP를 한 번 더 사용해서 두 개의 DP의 합 들의 최대를 찾음
// (4) dp_LIS[i] + dp_LDS[i] - 1 : 해당 위치까지 최대 증가 + 뒤 부터 증가 (감소) - 1 (겹친 곳 빼기)