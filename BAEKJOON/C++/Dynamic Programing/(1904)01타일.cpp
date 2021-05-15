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
	둘 다 모든 과정을 조사하지만 그 Process 시간을 줄이는 방법이 다르다.
	Backtracking 과 Dynamic Programming의 가장 큰 차이는
	Pruning 방식이라고 생각한다.

	Backtracking은 Leaf에서의 조건 또는 chk 로 하는 반면
	Dynamic Programming 은 일련의 과정에서 결과 값을 연산하지 않고,
	이전 값을 사용한다는 데에 있다

	modulo 연산의 성질은 곱의 결과 후 modulo를 하는 것과
	곱의 중간중간에 modulo를 하는 것 모두 같음
*/