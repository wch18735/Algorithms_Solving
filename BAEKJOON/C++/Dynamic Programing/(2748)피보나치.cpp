#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Bottom-Up ¹æ½Ä
int main(void) {
	int last_pos = 1;
	unsigned long long int mem[2] = { 0,1 };
	int n;
	scanf("%d", &n);

	for (int i = last_pos; i < n; i++) {
		unsigned long long int result = 0;
		result = mem[0] + mem[1];
		mem[0] = mem[1];
		mem[1] = result;
	}

	printf("%llu", mem[1]);

	return 0;
}