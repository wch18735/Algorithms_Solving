#include <iostream>
#include <stdio.h>

int main() {
	int num_arr[9];
	for (int i = 0; i < 9; i++) {
		scanf("%d", &num_arr[i]);
	}

	int tmp_max = num_arr[0];
	int tmp_idx = 1;
	
	for (int i = 1; i < 9; i++) {
		if (tmp_max < num_arr[i]) {
			tmp_max = num_arr[i];
			tmp_idx = i + 1;
		}
	}

	printf("%d\n%d", tmp_max, tmp_idx);
}