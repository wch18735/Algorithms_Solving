#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		vector<long long unsigned int> numArr(3);
		numArr[0] = 1;
		numArr[1] = 1;
		numArr[2] = 1;

		for (int i = 3; i < N; i++) {
			numArr.push_back(numArr[i - 2] + numArr[i - 3]);
		}

		printf("%lld\n", numArr[N - 1]);
	}

	return 0;
}