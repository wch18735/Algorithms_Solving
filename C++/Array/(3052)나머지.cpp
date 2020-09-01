#include <iostream>

using namespace std;

int main(void) {
	int remain[42] = { 0 };
	int idx;
	int numArr[10];
	int cnt = 0;

	for (int i = 0; i < 10; i++) cin >> numArr[i];

	for (int i = 0; i < 10; i++) {
		idx = numArr[i] % 42;
		remain[idx] = 1;
	}

	for (int i = 0; i < 42; i++) {
		if (remain[i] == 1) cnt++;
	}

	cout << cnt;

	return 0;
}