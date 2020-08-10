#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void* make_prime_arr(int n);

int main() {
	int T=200;
	//int n;
	int count = 0;

	// Test case number
	//scanf("%d", &T);

	for (int test_num = 4; test_num <= T; test_num=test_num + 2) {
		// number n
		//scanf("%d", &n);
		printf("Test: %d\n", test_num);


		// prime array
		int* prime_arr = (int*)make_prime_arr(test_num);

		// size of prime_arr
		for (int i = 0; ; i++) {
			if (prime_arr[i] == -1) break;
			count++;
		}

		// difference
		int dif = -1;
		int final_t1 = 0;
		int final_t2 = 0;

		for (int i = 0; i < count; i++) {
			int t1 = prime_arr[i];
			for (int j = 0; j < count; j++) {
				// t2 >= t1
				int t2 = prime_arr[j];
				if (t1 + t2 == test_num && (dif == -1 || dif >= abs(t2-t1))) {
					final_t1 = t1;
					final_t2 = t2;
					dif = abs(t2 - t1);
				}
			}
		}
		
		if(final_t1 <= final_t2)
			printf("%d %d\n", final_t1, final_t2);
		else printf("%d %d\n", final_t2, final_t1);
		free(prime_arr);
	}

	return 0;
}

void* make_prime_arr(int n) {
	int count = 0;
	int* num_arr = (int*)malloc(sizeof(int)*(n+1));
	num_arr[0] = num_arr[1] = -1;

	for (int i = 2; i <= n; i++) {
		if (num_arr[i] == -1) continue;

		// number of prime under n
		count++;

		num_arr[i] = i;
		int t = 2;
		while (i*t <= n) {
			num_arr[i*t] = -1;
			t++;
		}
	}

	int* prime_arr = (int*)malloc(sizeof(int)*(count+1));
	
	prime_arr[count] = -1; //end

	int pidx = 0;
	for (int i = 2; i <= n; i++) {
		if (num_arr[i] != -1) {
			prime_arr[pidx] = num_arr[i];
			pidx++;
		}
	}

	free(num_arr);

	return prime_arr;
}