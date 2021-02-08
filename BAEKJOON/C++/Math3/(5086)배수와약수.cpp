#include <iostream>

using namespace std;

int main(void) {
	int a, b;

	do {
		cin >> a >> b;
		if (a > b) {
			if (a % b == 0) cout << "multiple" << '\n';
			else cout << "neither" << '\n';
		}
		else if (a < b) {
			if (b % a == 0) cout << "factor" << '\n';
			else cout << "neither" << '\n';
		}
	} while (a != 0 || b != 0);

	return 0;
}