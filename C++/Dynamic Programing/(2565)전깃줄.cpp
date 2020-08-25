#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main(void) {
	int n;
	cin >> n;

	vector<pair<int, int>> pole;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pole.push_back(pair<int, int>(a, b));
	}

	sort(pole.begin(), pole.end(), compare);

	vector <int> LIS;

	for (int i = 0; i < n; i++) {
		if (LIS.empty()) LIS.push_back(pole[i].second);
		else {
			if (LIS.back() < pole[i].second) LIS.push_back(pole[i].second);
			else {
				auto LowerBoundPointer = lower_bound(LIS.begin(), LIS.end(), pole[i].second);
				*LowerBoundPointer = pole[i].second;
			}
		}
	}

	cout << n - (int)LIS.size();

	return 0;
}

// 꼬여있다 -> 정렬되지 않았다 -> (길이 - LIS): 정렬되지 않은 수