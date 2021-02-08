#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int n;
		cin >> n;

		vector<int> numArr;
		int num;
		int sum = 0;
		double average;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			cin >> num;
			sum += num;
			numArr.push_back(num);
		}

		average = (double)sum / n;

		for (int i = 0; i < n; i++) {
			if (numArr[i] > average) cnt++;
		}

		cout << fixed;
		cout.precision(3);
		cout << (double)cnt / n * 100 << '%' << '\n';
	}

	return 0;
}