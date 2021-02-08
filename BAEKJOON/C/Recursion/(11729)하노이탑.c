#include <stdio.h>

int count = 0;
void hanoi(int num, int from, int temp, int to);
void hanoi_count(int num, int from, int temp, int to);

int main() {
	int num;
	scanf("%d", &num);
	hanoi_count(num, 1, 2, 3);
	printf("%d\n", count);
	hanoi(num, 1, 2, 3);
}

// hanoi(n, from, temp, to): n���� �ϳ��� ���� from ���� temp�� ���ļ� to�� ������ ���´� 
void hanoi(int num, int from, int temp, int to) {
	if (num == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(num - 1, from, to, temp);
		printf("%d %d\n", from, to);
		hanoi(num - 1, temp, from, to);
	}
}

void hanoi_count(int num, int from, int temp, int to) {
	count++;
	if (num == 1) {}
	else {
		hanoi_count(num - 1, from, to, temp);
		hanoi_count(num - 1, temp, from, to);
	}
}

