#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

#define MAXNUM 1000000
using namespace std;

void make_one(int count, int result, int* total) {
	// pruning
	if (result < 0) return;
	
	// Leaf
	if (result == 1) {
		if(*total > count) *total = count;
		return;
	}

	// Not Leaf
	if (result % 2 == 0) make_one(count + 1, result / 2, total);
	if (result % 3 == 0) make_one(count + 1, result / 3, total);
	make_one(count + 1, result - 1, total);
}

int main(void) {
	int n;
	scanf("%d", &n);

	int total = MAXNUM;
	make_one(0, n, &total);

	printf("%d", total);

	return 0;
}

/*
	idx에 대한 점화식을 세운다
	
	세 가지 경우
	
	dp[idx] = dp[idx/3] + 1
	dp[idx] = dp[idx/2] + 1
	dp[idx] = dp[idx - 1] + 1

	이렇게 세 가지 경우로 부터 올 수 있음

	따라서 min() 을 이용해 구한다
*/