#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_IDX 9

void dfs(int count, int N, int M, int quasi_que[MAX_IDX], bool chk[MAX_IDX]) {
	// count <= M �̱� ������ quasi_que�� index�� ����Ѵ�
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ",quasi_que[i]);
		}
		printf("\n");

		// ���� ����
		return;
	}

	// �߰� ����
	for (int i = 1; i <= N; i++) {
		if (chk[i] != true /* !chk[i] */) {

			// quasi_que �� ����
			quasi_que[count] = i;

			// 'i' �� �湮 
			chk[i] = true;

			// count + 1 �� �ؼ� ���� �湮
			dfs(count + 1, N, M, quasi_que, chk);

			// stackó�� �ǵ��ƿ��� ���� ��ȯ
			chk[i] = false;
		}
	}
}

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	// �ǻ�-ť
	int quasi_que[MAX_IDX] = { 0, };

	// true: �湮, false: �̹湮
	bool chk[MAX_IDX] = { false, };

	dfs(0, N, M, quasi_que, chk);

	return 0;
}