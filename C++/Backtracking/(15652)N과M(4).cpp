#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define idx_max 9

void dfs(int parent, int count, int n, int m, int* store) {
	/* Leaf���� ���� */
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", store[i]);
		}
		printf("\n");
		return;
	}

	/* Leaf�� �ƴ� �� ���� */
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
* Depth First Search with recursion �� 
* 1) pointer�� �����Ͽ� ������ ����� �Ͱ�
* 2) ���ο��� Leaf ������ ����� ��Ұ� �����ϰ�
* 3) ������ Leaf �� ���� �ֺ� ��带 ã�� �̵��ϴ� �� ������ �����ȴ�.
* 
* ��, dfs()�� ���� ������ ��ġ�� �˰����� ������ ������ �ڷᱸ��, ���ǽ��� �־� ���۽�Ű�� ���� ���Ѵ�.
* 
* �� �̶�, ��� �Լ��� ����Ͽ� ��������, �������� ���� �����ϰ� �� �� ������ ����Լ� != dfs() �̴�.
* 
* BACK TRACKING: ��� ��츦 ������ ��, ������ �ɾ� �ʿ� ���� �κ��� �����ϰ� �����ϴ� ��
* - ��� ��� ����: dfs, bfs
* - ���� while(1) �̳� for(;;;) �ӿ� break �ξ� ���������� �͵� ���������� ����Լ��� �̿��� �������� �������� ������ �����ϴ�
* - �� ���̿� ���� ex) bool chk[idx_max] �� parent_node �� �����Ͽ� ����
* 
*/