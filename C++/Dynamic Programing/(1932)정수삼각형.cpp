#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXNUM 500000

int triangle[500][500];
int max = 0;

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j <= i - 1; j++) {
			if (triangle[i][j] < triangle[i][j + 1]) triangle[i - 1][j] += triangle[i][j + 1];
			else triangle[i - 1][j] += triangle[i][j];
		}
	}

	printf("%d", triangle[0][0]);
	
	return 0;
}