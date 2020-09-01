#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int maxNum = 0;
	int sum = 0;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		if (maxNum < num) maxNum = num;
	}

	cout << fixed;
	cout.precision(3);
	cout << (float)sum / (n * maxNum) * 100;

	/*
	value = SUM/(N*MAX)*100
	*/

	return 0;
}