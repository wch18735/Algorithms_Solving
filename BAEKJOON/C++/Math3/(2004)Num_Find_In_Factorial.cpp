#include <iostream>

using namespace std;

int countTwo(int num) {
	int cnt = 0;
	for (int i = 2; num / i >= 1; i *= 2) {
		cnt += num / i;
	}

	return cnt;
}

int main(void) {
	int num;
	cin >> num;

	cout << countTwo(num);

	return 0;
}