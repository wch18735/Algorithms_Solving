#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int** make_map(int N) {
	int** chess_map = new int* [N];
	for (int i = 0; i < N; i++) {
		chess_map[i] = new int[N];
	}

	return chess_map;
}

void set_map(int** chess_map, int N, int value) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			chess_map[i][j] = value;
	}
}

void delete_map(int** chess_map, int N) {
	for (int i = 0; i < N; i++) {
		delete(chess_map[i]);
	}
	delete(chess_map);
}

void print_state(int** chess_map, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", chess_map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void up(int x, int y, int** chk, int N, int queen_state) {
	// Leaf 에서 동작
	if (x >= N || x < 0 || y >= N || y < 0) return;

	// chk update 후 up로 진행
	chk[x][y] += queen_state;
	up(x - 1, y, chk, N, queen_state);
}

void right(int x, int y, int** chk, int N, int queen_state) {
	// Leaf 에서 동작
	if (x >= N || x < 0 || y >= N || y < 0) return;

	// chk update 후 up로 진행
	chk[x][y] += queen_state;
	right(x, y + 1, chk, N, queen_state);
}

void left(int x, int y, int** chk, int N, int queen_state) {
	// Leaf 에서 동작
	if (x >= N || x < 0 || y >= N || y < 0) return;

	// chk update 후 up로 진행
	chk[x][y] += queen_state;
	left(x, y - 1, chk, N, queen_state);
}

void down(int x, int y, int** chk, int N, int queen_state) {
	// Leaf 에서 동작
	if (x >= N || x < 0 || y >= N || y < 0) return;

	// chk update 후 up로 진행
	chk[x][y] += queen_state;
	down(x + 1, y, chk, N, queen_state);
}

void ru(int x, int y, int** chk, int N, int queen_state) {
	// Leaf 에서 동작
	if (x >= N || x < 0 || y >= N || y < 0) return;

	// chk update 후 up로 진행
	chk[x][y] += queen_state;
	ru(x - 1, y + 1, chk, N, queen_state);
}

void lu(int x, int y, int** chk, int N, int queen_state) {
	// Leaf 에서 동작
	if (x >= N || x < 0 || y >= N || y < 0) return;

	// chk update 후 up로 진행
	chk[x][y] += queen_state;
	lu(x - 1, y - 1, chk, N, queen_state);
}

void rd(int x, int y, int** chk, int N, int queen_state) {
	// Leaf 에서 동작
	if (x >= N || x < 0 || y >= N || y < 0) return;

	// chk update 후 up로 진행
	chk[x][y] += queen_state;
	rd(x + 1, y + 1, chk, N, queen_state);
}

void ld(int x, int y, int** chk, int N, int queen_state) {
	// Leaf 에서 동작
	if (x >= N || x < 0 || y >= N || y < 0) return;

	// chk update 후 up로 진행
	chk[x][y] += queen_state;
	ld(x + 1, y - 1, chk, N, queen_state);
}

void pick_down(int x, int y, int** chk, int N) {
	up(x, y, chk, N, 1);
	down(x, y, chk, N, 1);
	right(x, y, chk, N, 1);
	left(x, y, chk, N, 1);
	ru(x, y, chk, N, 1);
	lu(x, y, chk, N, 1);
	rd(x, y, chk, N, 1);
	ld(x, y, chk, N, 1);
}

void pick_up(int x, int y, int** chk, int N) {
	up(x, y, chk, N, -1);
	down(x, y, chk, N, -1);
	right(x, y, chk, N, -1);
	left(x, y, chk, N, -1);
	ru(x, y, chk, N, -1);
	lu(x, y, chk, N, -1);
	rd(x, y, chk, N, -1);
	ld(x, y, chk, N, -1);
}

void dfs(int x, int y, int **chess_map,int N, int count, int *ptr) {
	// Leaf node
	if (count == N) {
		*ptr = *ptr + 1;
		return;
	}
	
	// Limit of point
	if (x >= N || x < 0 || y >= N || y < 0) return;

	if (chess_map[x][y] == 0) { // 놓을 수 있다면
		pick_down(x, y, chess_map, N);	// 내려놓음
		dfs(0, y + 1, chess_map, N, count + 1, ptr); // 옆으로 한 칸 이동하여 가장 위부터 탐색
		pick_up(x, y, chess_map, N); // 놨던 걸 다시 들어 올림
		dfs(x + 1, y, chess_map, N, count, ptr); // 아래로 탐색
	}
	else { // 놓을 수 없다면
		dfs(x+1, y, chess_map, N, count, ptr);
	}
}

int main(void) {
	int N;
	int t = scanf("%d", &N);

	int total = 0;
	int* ptr = &total;

	// make chess board, chk
	int** chess_map = make_map(N);

	// setting mat
	set_map(chess_map, N, 0);

	// dfs from (0,0)
	dfs(0, 0, chess_map, N, 0, ptr);

	// print total number
	printf("%d", *ptr);

	// delete memory
	delete_map(chess_map, N);

	return 0;
}

/*
	1. new 를 이용한 동적할당은 memory 자체에 공간을 할당한다.
	2. 이를 반환하기만 하면 memory 할당 및 반환 함수를 만들 수 있다.
	3. char* 과 같이 linux 등에서 socket 통신 등을 할 때는 memset or memcpy , strcpy 등이 더 유용하다.

	재귀함수는 방향성을 갖는다 (ex: 한 직선 방향 or 시계방향)
*/