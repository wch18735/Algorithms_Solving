#include <stdio.h>

/*
	알고리즘
	: Loop은 이중 for문으로 해결
	: 판단을 재귀함수 이용
	: n/3 < x % n < 2*n/3 이고 n/3 < y % n < 2*n/3 이면 띄어쓰기
	: 아닌 경우만 * 인 것을 활용
*/

void print_star(int x, int y, int n);

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			print_star(i, j, num);
		}
		printf("\n");
	}
}

void print_star(int x, int y, int n) {
	if (n == 1) printf("*");
	else {
		if ((n / 3 < x % n && x % n <= 2 * n / 3) && (n / 3 < y % n && y % n <= 2 * n / 3)) printf(" ");
		else print_star(x, y, n / 3);
	}
}