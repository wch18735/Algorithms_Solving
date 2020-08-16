#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void fibonacci_count(int n, int *count) {
	if (n == 0) {
		count[0] += 1;
	}
	else if (n == 1) {
		count[1] += 1;
	}
	else {
		fibonacci_count(n - 1, count);
		fibonacci_count(n - 2, count);
	}
}

int main(void) {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		int count[2] = { 0,0 };
		fibonacci_count(num, count);

		printf("%d %d\n", count[0], count[1]);
	}
	return 0;
}