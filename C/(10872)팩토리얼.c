#include<stdio.h>

int factorial(int n);

int main() {
	int num;
	scanf("%d", &num);
	printf("%d\n", factorial(num));
}

int factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}