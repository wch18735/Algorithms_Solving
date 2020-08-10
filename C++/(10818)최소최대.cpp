#include <stdio.h>

int main() {
	int N;
	int tmp;
	int max = -1000000;
	int min = 1000000;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp < min) min = tmp;
		if (tmp > max) max = tmp;
	}

	printf("%d %d", min, max);
}