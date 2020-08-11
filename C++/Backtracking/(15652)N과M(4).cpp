#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define idx_max 9

void dfs(int parent, int count, int n, int m, int* store) {
	/* Leaf에서 동작 */
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", store[i]);
		}
		printf("\n");
		return;
	}

	/* Leaf가 아닐 때 동작 */
	for (int i = parent; i <= n; i++) {
		store[count] = i;
		dfs(i, count+1, n, m, store);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int store[idx_max];

	dfs(1, 0, n, m, store);
}

/*
* 
* Depth First Search with recursion 은 
* 1) pointer로 전달하여 조건을 만드는 것과
* 2) 내부에서 Leaf 조건을 만드는 요소가 존재하고
* 3) 동작은 Leaf 일 때와 주변 노드를 찾고 이동하는 두 가지로 구성된다.
* 
* 즉, dfs()는 위의 과정을 거치는 알고리즘을 적절한 변수나 자료구조, 조건식을 넣어 동작시키는 것을 뜻한다.
* 
* ※ 이때, 재귀 함수를 사용하여 분할정복, 병합정렬 등을 가능하게 할 수 있으니 재귀함수 != dfs() 이다.
* 
* BACK TRACKING: 모든 경우를 조사할 때, 조건을 걸어 필요 없는 부분을 제외하고 조사하는 것
* - 모든 경우 조사: dfs, bfs
* - 또한 while(1) 이나 for(;;;) 속에 break 두어 빠져나오는 것도 가능하지만 재귀함수를 이용해 유동적인 제한조건 적용이 가능하다
* - 그 사이에 조건 ex) bool chk[idx_max] 나 parent_node 를 전달하여 제한
* 
*/