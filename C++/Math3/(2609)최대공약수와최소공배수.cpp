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

// ��Ŭ���� ȣ����
// �ּҰ����: �� ���� �� / �ִ�����