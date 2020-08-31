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
	Greedy ������⺸�ٴ� ������ ���� ������ ������
	���� �ּҰ� �Ǳ� ���ؼ��� �ߺ��Ǿ� �������� ���� ���� �۾ƾ� �Ѵ�.
	���� ���� ���� ���� ������ ��ġ�ϸ� �Ǹ�,
	�ߺ��Ǵ� Ƚ���� ��ٸ��� ��� �� ��ŭ�̴�.
*/