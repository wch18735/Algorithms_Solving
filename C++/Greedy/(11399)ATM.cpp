#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main(void) {
	int n;
	cin >> n;
	
	vector<int> numArr;
	int num;
	int Answer = 0;

	for (int i = 0; i < n; i++) {
		cin >> num;
		numArr.push_back(num);
	}

	sort(numArr.begin(), numArr.end(), compare);

	for (int i = 0; i < n; i++) {
		Answer += (n - i) * numArr[i];
	}

	cout << Answer;

	return 0;
}

/*
	Greedy 문제라기보다는 오히려 수학 문제에 가깝다
	합이 최소가 되기 위해서는 중복되어 더해지는 값이 가장 작아야 한다.
	따라서 가장 작은 값을 앞으로 배치하면 되며,
	중복되는 횟수는 기다리는 사람 수 만큼이다.
*/