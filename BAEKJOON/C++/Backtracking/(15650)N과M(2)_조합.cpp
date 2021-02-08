#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define idx_max 9

// ����: N�� M�� �־����� �� ���յ��� print

void print_block(bool* chk, int n, int parent_node);

void dfs(int parent_node, int move_count, int n, int m, int *store, bool *chk) {	
	//print_block(chk, n, parent_node);
	if (move_count == m) { // Leaf�� �������� ��
		for (int i = 0; i < m; i++) {
			printf("%d ", store[i]);
		}
		printf("\n"); 
		return; // Ż������
	}

	for (int i = parent_node; i <= n; i++) {
		//print_block(chk, n, parent_node);
		if (chk[i] != true) { // �湮�� ���� ���ٸ�
			
			// ��θ� store �ϰ�
			store[move_count] = i;

			// �湮�ϰ�
			chk[i] = true;

			// ���� node�� �̵�
			dfs(i, move_count + 1, n, m, store, chk);

			// ���ƿ��� ���� �ʱ�ȭ
			chk[i] = false;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int store[idx_max] = { 0, };
	bool chk[idx_max] = { false, }; // �湮:true, �̹湮: false

	dfs(1, 0, n, m, store, chk);

	return 0;
}

void print_block(bool* chk, int n, int parent_node) {
	for (int i = 1; i <= n; i++) {
		if (chk[i] == true || i < parent_node) printf("��");
		else printf("��");
	}
	printf(" %d\n",parent_node);
}

/*

	1. new �� �̿��� �����Ҵ�
	scanf("%d",&n);
	int *num = new int[n];
	
	2. DFS�� ����
	���¸� ������Ʈ�ϸ� �ϳ��� ���� ��츦 ��� Ž�� Like ����
	Leaf �� Ȯ���ϴ� �� ������ ����

	3. ����Լ��� ����ϴ� ���
	- �� recursion ���� print �Ѵ�.
	- Ż�� ������ �������� ������ print �Ѵ�.

	4. nCm �� n ���� �����ǿ� m ���� �����丷�� ���ʺ��� ���� 
	������ ������ �ϳ��� ������ �Ű�, �����ʿ� ��� �����丷�� �ְ� ����� ����� ��

	5. nPm �� n ���� �����ǿ� m ���� ������� ���� ����� ��

	6. dfs() ���� ���� ���� Ȯ������ ���ϰ� �ϴ� �������� ǰ
*/