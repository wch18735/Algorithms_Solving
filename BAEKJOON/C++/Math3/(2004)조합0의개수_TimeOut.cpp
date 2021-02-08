#include <iostream>
#include <algorithm>

using namespace std;

int twoNum(int num) {
	int cnt = 0;
	while (num % 2 == 0) {
		cnt++;
		num = num >> 1;
	}
	return cnt;
}

int fiveNum(int num) {
	int cnt = 0;
	while (num % 5 == 0) {
		cnt++;
		num /= 5;
	}
	return cnt;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	int two_nominator = 0;
	int five_nominator = 0;
	int two_denominator = 0;
	int five_denominator = 0;

	if ((n>>1) > m) {
		for (int i = n, t = 1; t <= m; i--, t++) {
			two_nominator += twoNum(i);
			five_nominator += fiveNum(i);

			two_denominator += twoNum(t);
			five_denominator += fiveNum(t);
		}
	}
	else {
		for (int i = n, t = 1; i > n - m; i--, t++) {
			two_nominator += twoNum(i);
			five_nominator += fiveNum(i);

			two_denominator += twoNum(t);
			five_denominator += fiveNum(t);
		}
	}

	cout << min(two_nominator - two_denominator, five_nominator - five_denominator);

	return 0;
}