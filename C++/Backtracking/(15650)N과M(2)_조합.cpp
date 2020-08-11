#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define idx_max 9

// 문제: N과 M이 주어지면 이 조합들을 print

void print_block(bool* chk, int n, int parent_node);

void dfs(int parent_node, int move_count, int n, int m, int *store, bool *chk) {	
	//print_block(chk, n, parent_node);
	if (move_count == m) { // Leaf에 도달했을 때
		for (int i = 0; i < m; i++) {
			printf("%d ", store[i]);
		}
		printf("\n"); 
		return; // 탈출조건
	}

	for (int i = parent_node; i <= n; i++) {
		//print_block(chk, n, parent_node);
		if (chk[i] != true) { // 방문한 적이 없다면
			
			// 경로를 store 하고
			store[move_count] = i;

			// 방문하고
			chk[i] = true;

			// 다음 node로 이동
			dfs(i, move_count + 1, n, m, store, chk);

			// 돌아오며 상태 초기화
			chk[i] = false;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int store[idx_max] = { 0, };
	bool chk[idx_max] = { false, }; // 방문:true, 미방문: false

	dfs(1, 0, n, m, store, chk);

	return 0;
}

void print_block(bool* chk, int n, int parent_node) {
	for (int i = 1; i <= n; i++) {
		if (chk[i] == true || i < parent_node) printf("■");
		else printf("□");
	}
	printf(" %d\n",parent_node);
}

/*

	1. new 를 이용한 동적할당
	scanf("%d",&n);
	int *num = new int[n];
	
	2. DFS의 본질
	상태를 업데이트하며 하나의 깊은 경우를 모두 탐색 Like 스택
	Leaf 를 확인하는 데 목적이 있음

	3. 재귀함수를 사용하는 방법
	- 매 recursion 마다 print 한다.
	- 탈출 조건이 만족됐을 때마다 print 한다.

	4. nCm 은 n 개의 격자판에 m 개의 나무토막을 왼쪽부터 놓고 
	오른쪽 끝부터 하나씩 옆으로 옮겨, 오른쪽에 모든 나무토막이 있게 만드는 경우의 수

	5. nPm 은 n 개의 격자판에 m 개를 순서대로 놓는 경우의 수

	6. dfs() 에서 이전 것은 확인하지 못하게 하는 조건으로 품
*/