#include <stdio.h>
#include <math.h>

#define MAX 10000

int num[MAX+1] = { 0, };

int main() {
	int T;
	int n;

	// �����佺�׳׽��� ü
	for (int i = 2; i <= (int)sqrt(MAX); i++) {
		for (int j = i * i; j <= MAX; j += i) {
			if (num[j] % i == 0) num[j] = 1;
		}
	}

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &n);

		// n = (n-j) + j
		// num[j] �� num[n-j] �� ��� �Ҽ��� ��� Check
		// index == value �� ���
		// ���� j �� ���� Ŭ ��, �� ���̰� ���� ����
		for (int j = n/2; j > 0; j++) {
			if (num[j] != 1 && num[n - j] != 1) {
				printf("%d %d\n",n-j, j);
				break;
			}
		}
	}

	return 0;
}