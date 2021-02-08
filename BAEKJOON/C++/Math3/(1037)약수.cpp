#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	int n;
	cin >> n;

	int num;
	vector<int> numArr;

	if (n == 1) {
		cin >> num;
		cout << num * num;
	}
	else {

		for (int i = 0; i < n; i++) {
			cin >> num;
			numArr.push_back(num);
		}

		sort(numArr.begin(), numArr.end(), compare);

		cout << numArr[0] * numArr[n - 1];
	}

	return 0;
}

/*
	��¥ ����� ����
	ũ�� ������� sort �Ͽ��� ��, �� �� ���� ���ϸ� �ڱ� �ڽ��̴�.
*/