#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	int result;
	int remain;
	int numArr[10] = { 0, };

	cin >> a;
	cin >> b;
	cin >> c;

	result = a * b * c;


	do {
		
		remain = result % 10;
		numArr[remain] += 1;
		result /= 10;

	} while (result != 0);

	for (int i = 0; i < 10; i++) {
		cout << numArr[i] << '\n';
	}

	return 0;
}