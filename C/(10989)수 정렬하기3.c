#include <stdio.h>

#define MAX 10000

// 문제를 잘 보면 풀 수 있는 문제
// 입력으로 주어지는 N의 범위가 한정적
int main() {
	int num_arr[MAX] = { 0, };

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int tmp;
		scanf("%d", &tmp);

		num_arr[tmp - 1]++;
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < num_arr[i]; j++) {
			printf("%d\n", i + 1);
		}
	}

	return 0;
}