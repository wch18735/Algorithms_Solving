#include <stdio.h>

#define MAX 10000

// ������ �� ���� Ǯ �� �ִ� ����
// �Է����� �־����� N�� ������ ������
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