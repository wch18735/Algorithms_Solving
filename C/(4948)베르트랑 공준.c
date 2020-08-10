#include <stdio.h>
#include <math.h>

int main() {
	int n;
	int count = 0;
	
	while (1) {
		scanf("%d", &n);
		if (n == 0) return 0;

		for (int i = n + 1; i <= 2 * n; i++) {
			if (check_prime(i)) count++;
		}

		printf("%d\n", count);
		count = 0;
	}
}

int check_prime(int num) {
	if (num <= 1) {
		return 0;
	}
	
	for (int i = 2; i <= (int)sqrt(num); i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}