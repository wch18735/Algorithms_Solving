#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	arr: if left length is 2 and it was calculated before, use this value 
	left_len: left length

	algorithm
	1. left_len == 0 -> 1
	2. if arr[left_len - i] != 0 -> arr[left_len] += arr[left_len - i]
*/

void search() {

}

int main(void) {
	int N;
	scanf("%d", &N);

	int* arr = new int[N+1];
	for (int i = 0; i <= N; i++) {
		if (i == 0) arr[i] = 1;
		else if (i == 1) arr[i] = 1;
		else if (i == 2) arr[i] = 2;
		else arr[i] = 0;
	}

	for (int i = 3; i <= N; i++) {
		arr[i] = (arr[i - 2] + arr[i - 1]) % 15746;
	}

	printf("%d", arr[N]);

	return 0;
}

/*
	�� �� ��� ������ ���������� �� Process �ð��� ���̴� ����� �ٸ���.
	Backtracking �� Dynamic Programming�� ���� ū ���̴�
	Pruning ����̶�� �����Ѵ�.

	Backtracking�� Leaf������ ���� �Ǵ� chk �� �ϴ� �ݸ�
	Dynamic Programming �� �Ϸ��� �������� ��� ���� �������� �ʰ�,
	���� ���� ����Ѵٴ� ���� �ִ�

	modulo ������ ������ ���� ��� �� modulo�� �ϴ� �Ͱ�
	���� �߰��߰��� modulo�� �ϴ� �� ��� ����
*/