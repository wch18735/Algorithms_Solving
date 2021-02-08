#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define max_n 14

void dfs(int row, int N, int *ptr, bool* column, bool* d_left, bool* d_right) {
	// Leaf
	if (row == N) {
		*ptr += 1;
		return;
	}

	// Not leaf: row, i 값을 이용해 어떤 열의 어떤 대각선에 속하는지 표현할 수 있다
	// row = y_point, i = x_point
	for (int i = 0; i < N; i++) {
		// limit condition
		if (column[i] == true || d_left[row - i + N -1] == true || d_right[row+i] == true) continue;

		// if pick down possible
		column[i] = true;
		d_left[(row - i + N - 1)] = true;
		d_right[(row + i)] = true;

		// row + 1
		dfs(row + 1, N, ptr, column, d_left, d_right);

		// back from next row
		// clean checking array
		column[i] = false;
		d_left[(row - i + N - 1)] = false;
		d_right[(row + i)] = false;
	}
}

int main(void) {
	int N;
	int row = scanf("%d", &N); row--;
	int count = 0;

	bool column[max_n*2 - 1] = {false,};
	bool diagonal_right[max_n*2 - 1] = { false, }; // (x + y) can be index 
	bool diagonal_left[max_n*2 - 1] = { false, }; // (x - y + N - 1) can be index

	dfs(row, N, &count, column, diagonal_left, diagonal_right);

	printf("%d", count);

	return 0;
}

/*
	POD 일 때는 new
	그렇지 않을 때는 malloc, memset

	급하게 함수를 짤 때는 내부 동작을 생각하며 짜고, 때마다 인자를 추가해준다

	dfs(){
		dfs()
		=========
		여기는 search하고 돌아온 다음 수행하는 것
		chk[] 를 초기화하는 역할들이 많이 수행됨
		=========

	}
*/