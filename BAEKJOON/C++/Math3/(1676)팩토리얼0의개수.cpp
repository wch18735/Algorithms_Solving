#include <iostream>
#include <algorithm>

using namespace std;

int twoDivisor(int num) {
	int cnt = 0;
	while (num % 2 == 0)
	{
		num /= 2;
		cnt++;
	}

	return cnt;
}

int fiveDivisor(int num) {
	int cnt = 0;
	while (num % 5 == 0)
	{
		num /= 5;
		cnt++;
	}

	return cnt;
}

int main(void) {
	int n;
	cin >> n;

	int two = 0;
	int five = 0;

	for (int i = 1; i <= n; i++) {
		two += twoDivisor(i);
		five += fiveDivisor(i);
	}

	cout << min(two, five);

	return 0;
}