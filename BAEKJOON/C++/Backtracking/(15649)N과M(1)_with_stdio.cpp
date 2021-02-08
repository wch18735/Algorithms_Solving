#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_IDX 9

void dfs(int count, int N, int M, int quasi_que[MAX_IDX], bool chk[MAX_IDX]) {
	// count <= M 이기 때문에 quasi_que의 index로 사용한다
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ",quasi_que[i]);
		}
		printf("\n");

		// 종료 조건
		return;
	}

	// 중간 동작
	for (int i = 1; i <= N; i++) {
		if (chk[i] != true /* !chk[i] */) {

			// quasi_que 에 저장
			quasi_que[count] = i;

			// 'i' 를 방문 
			chk[i] = true;

			// count + 1 을 해서 다음 방문
			dfs(count + 1, N, M, quasi_que, chk);

			// stack처럼 되돌아오며 상태 변환
			chk[i] = false;
		}
	}
}

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	// 의사-큐
	int quasi_que[MAX_IDX] = { 0, };

	// true: 방문, false: 미방문
	bool chk[MAX_IDX] = { false, };

	dfs(0, N, M, quasi_que, chk);

	return 0;
}