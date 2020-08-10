#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int T;
	int n;

	// Test case number
	scanf("%d", &T);

	for (int test_num = 0; test_num < T; test_num++) {
		// number n
		scanf("%d", &n);

		// prime array
		int* num_arr = (int*)malloc(sizeof(int)*(n + 1));
		num_arr[0] = num_arr[1] = -1;

		for (int i = 2; i <= n; i++) {
			if (num_arr[i] == -1) continue;

			num_arr[i] = i;
			int t = 2;
			while (i*t <= n) {
				num_arr[i*t] = -1;
				t++;
			}
		}

		// difference
		int dif = -1;
		int final_t1 = 0;
		int final_t2 = 0;

		for (int i = 2; i < n+1; i++) {
			int t1 = num_arr[i];
			if (t1 != -1) {
				for (int j = i; j < n + 1; j++) {
					// t2 >= t1
					int t2 = num_arr[j];
					if (t2 != -1 && t1 + t2 == n && (dif == -1 || dif >= abs(t2 - t1))) {
						final_t1 = t1;
						final_t2 = t2;
						dif = abs(t2 - t1);
					}
				}
			}
		}

		if (final_t1 <= final_t2)
			printf("%d %d\n", final_t1, final_t2);
		else printf("%d %d\n", final_t2, final_t1);

		free(num_arr);
	}

	return 0;
}