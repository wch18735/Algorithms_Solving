#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	total: total number of sequence
	chk: full of length
	left_idx: left idx to add
*/

void search(int *total, int left_idx) {
	// Leaf
	if (left_idx == 0) {
		*total += 1;
		return;
	}

	// Not Leaf
	for (int i = 1; i <= 2; i++) {
		if (i > left_idx) return;
		search(total, left_idx - i);
	}
}

int main() {
	int total = 0;
	int N;

	scanf("%d", &N);
	search(&total, N);

	printf("%d", total % 15746);

	return 0;
}