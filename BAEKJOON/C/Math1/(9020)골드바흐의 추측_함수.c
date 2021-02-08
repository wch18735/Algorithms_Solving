#include<stdio.h>
#include<math.h>

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int n;
		scanf("%d", &n);

		int *num_arr = (int*)malloc(sizeof(int)*n/2);
		
		
		for (int i = 1; i <= n/2; i++) { // 소수 행렬
			if (check_prime(i)) {
				num_arr[i-1] = i;
			}
			else num_arr[i - 1] = -1;
		}

		int x1;
		int x2;
		int dif = -1;

		for (int i = 0; i <= n/2; i++) {
			int t1 = num_arr[i];

			for (int j = i; j <= n/2; j++) {
				int t2 = num_arr[j];
				if (t1 + t2 == n && (dif == -1 || dif > t2 - t1)) {
					x1 = t1;
					x2 = t2;
					dif = t2 - t1;
				}
			}
		}

		printf("%d %d\n",x1, x2);
	}

	return 0;
}

int check_prime(int num) {
	// Return 1 when it is prime number
	
	if (num <= 1) return 0;

	int root_num = (int)sqrt(num);

	for (int i = 2; i <= root_num; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}