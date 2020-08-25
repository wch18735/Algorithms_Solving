#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

void PrintDP(int* dp, int n) {
	for (int i = 0; i < n; i++) cout << dp[i] << ' ';
	cout << endl;
}

int main(void) {
	int n;
	vector<pair<int, int>> pole;
	int dp[101] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		pole.push_back(pair<int, int>(a, b));
	}

	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((pole[i].first - pole[j].first) * (pole[i].second - pole[j].second) < 0) k += 1;
		}
		dp[i] = k;
	}

	// Get max-index
	int Answer = 0;
	while (true) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int k = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if ((pole[i].first - pole[j].first) * (pole[i].second - pole[j].second) < 0) {
					k += 1;
					sum += 1;
				}
			}
			dp[i] = k;
		}

		if (sum > 0) {
			int idx = distance(dp, max_element(dp, dp + n));
			pole[idx].first = 0; pole[idx].second = 0;
			Answer += 1;
		}
		else break;
	}

	cout << Answer;

	return 0;
}