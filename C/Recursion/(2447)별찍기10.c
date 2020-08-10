#include <stdio.h>

/*
	�˰���
	: Loop�� ���� for������ �ذ�
	: �Ǵ��� ����Լ� �̿�
	: n/3 < x % n < 2*n/3 �̰� n/3 < y % n < 2*n/3 �̸� ����
	: �ƴ� ��츸 * �� ���� Ȱ��
*/

void print_star(int x, int y, int n);

int main() {
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			print_star(i, j, num);
		}
		printf("\n");
	}
}

void print_star(int x, int y, int n) {
	if (n == 1) printf("*");
	else {
		if ((n / 3 < x % n && x % n <= 2 * n / 3) && (n / 3 < y % n && y % n <= 2 * n / 3)) printf(" ");
		else print_star(x, y, n / 3);
	}
}