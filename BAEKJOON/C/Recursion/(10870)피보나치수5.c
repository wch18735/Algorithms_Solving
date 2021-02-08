#include <stdio.h>

int fibonacci(int F_2, int F_1, int n);

int main() {
	int num;
	scanf("%d", &num);

	// test case 분명히 0 과 1이 들어있을 것
	// 예상하는 Input의 범위를 더욱 넓히는 연습

	if (num == 0) printf("%d\n", 0);
	else if (num == 1) printf("%d\n", 1);
	else printf("%d\n", fibonacci(0, 1, num));
}

int fibonacci(int F_2, int F_1, int n) {
	if (n - 2 == 0) return F_1 + F_2;
	return fibonacci(F_1, F_1 + F_2, n - 1);
}