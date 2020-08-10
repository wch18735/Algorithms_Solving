#include <stdio.h>
#include <math.h>

#define MAX 10000

int num[MAX+1] = { 0, };

int main() {
	int T;
	int n;

	// 에라토스테네스의 체
	for (int i = 2; i <= (int)sqrt(MAX); i++) {
		for (int j = i * i; j <= MAX; j += i) {
			if (num[j] % i == 0) num[j] = 1;
		}
	}

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &n);

		// n = (n-j) + j
		// num[j] 와 num[n-j] 가 모두 소수인 경우 Check
		// index == value 인 경우
		// 또한 j 가 가장 클 때, 그 차이가 가장 작음
		for (int j = n/2; j > 0; j++) {
			if (num[j] != 1 && num[n - j] != 1) {
				printf("%d %d\n",n-j, j);
				break;
			}
		}
	}

	return 0;
}