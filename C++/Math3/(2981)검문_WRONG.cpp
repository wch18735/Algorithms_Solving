#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<int> numArr(n);
	int min;
	int max;

	for (int i = 0; i < n; i++) cin >> numArr[i];

	sort(numArr.begin(), numArr.end(), less<int>());

	min = numArr.front();
	max = numArr.back();

	for (int i = 2; i <= max; i++) {
		int flag = 0;

		int remain = numArr[0] % i;
		for (int j = 1; j < (int)numArr.size(); j++) {
			if (remain != numArr[j] % i) {
				j = (int)numArr.size();
				flag = 1;
			}
		}

		if (flag == 0) cout << i << ' ';
	}

	return 0;
}

// min or max 까지 범위를 주었으나 오답 또는 시간초과