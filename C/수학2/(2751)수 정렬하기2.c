#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}

int main() {
	int T;
	scanf("%d", &T);

	int *num_arr = (int*)malloc(sizeof(int)*T);

	for (int i = 0; i < T; i++) {
		int tmp;
		scanf("%d", &tmp);
		num_arr[i] = tmp;
	}

	qsort(num_arr, T, sizeof(int), compare);

	for (int i = 0; i < T; i++) {
		printf("%d\n", num_arr[i]);
	}

	return 0;
}