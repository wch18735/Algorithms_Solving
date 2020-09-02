#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main(void) {
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << '\n';
	cout << a * b / gcd(a, b);

	return 0;
}

// 유클리드 호제법
// 최소공배수: 두 수의 곱 / 최대공약수