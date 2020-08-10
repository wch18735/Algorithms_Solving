#include<stdio.h>

void check_prime(int num, int div);

int main() {
	int num;
	scanf("%d", &num);
	check_prime(num, num-1);
}

void check_prime(int num, int div) {
	if (div > 1) {
		if (num % div == 0) printf("소수가 아님\n");
		else check_prime(num, div - 1);
	}
	else printf("소수\n");
}