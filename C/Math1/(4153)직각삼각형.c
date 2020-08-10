#include <stdio.h>

int main() {
	while (1) {
		int num[3];
		scanf("%d %d %d", &num[0], &num[1], &num[2]);

		if (num[0] == 0 && num[1] == 0 && num[2] == 0) break;

		int c = num[0];
		int idx = 0;
		int sum = 0;

		for (int i = 0; i < 3; i++) {
			num[i] = num[i] * num[i];

			if (c < num[i]) {
				c = num[i];
				idx = i;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (i == idx) sum = sum - num[i];
			else sum = sum + num[i];
		}

		if (sum == 0) printf("right\n");
		else printf("wrong\n");
	}

	return 0;
}