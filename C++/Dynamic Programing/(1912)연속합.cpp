#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	int inputNum;
	cin >> n;
	vector <int> numArr;
	vector <int> sum_dp;

	for (int i = 0; i < n; i++) {
		cin >> inputNum;
		numArr.push_back(inputNum);
	}

	int Answer = -1000;
	for (int i = 0; i < n; i++) {
		if (sum_dp.empty()) {
			sum_dp.push_back(numArr[i]);
			if (Answer < numArr[i]) Answer = numArr[i];
		}
		else {
			// 나를 더한 값 < 나 자체 값
			// 이면 더할 필요 없음
			sum_dp.push_back(max(sum_dp[i - 1] + numArr[i], numArr[i]));
			if (Answer < sum_dp[i]) Answer = sum_dp[i];
		}
	}

	cout << Answer;

	return 0;
}