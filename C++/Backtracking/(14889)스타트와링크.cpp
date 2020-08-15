#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int gap = 4000;
int S1 = 0;
int S2 = 0;

void combi(int count, int N, int parent, int *num, int** numArr, int* store, bool* chk) {
	/*
		num: member array
		numArr: score table
		parent: to make combination
		store: stored in recursion function
		chk: to check visit or not
	*/


	// Leaf
	if (count == N / 2) {
		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				S1 += numArr[store[i]][store[j]];
				S1 += numArr[store[j]][store[i]];
			}
		}

		int* tmp = new int[N / 2];
		int tmp_idx = 0;
		for (int i = 0; i < N; i++) {
			if (chk[i] == false) {
				tmp[tmp_idx] = num[i];
				tmp_idx++;
			}
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				S2 += numArr[tmp[i]][tmp[j]];
				S2 += numArr[tmp[j]][tmp[i]];
			}
		}

		if (abs(S1 - S2) < gap) gap = abs(S1 - S2);
		
		delete(tmp);

		/*for (int i = 0; i < N / 2; i++) {
			printf("%d ", store[i]);
		}
		printf("\n");*/

		S1 = 0;
		S2 = 0;
		return;
	}

	// Not Leaf
	for (int i = parent; i < N; i++) {
		if (chk[i] == true) continue;
		chk[i] = true;
		store[count] = num[i];
		combi(count + 1, N, i + 1, num, numArr, store, chk);
		chk[i] = false;
	}
}

int main(void) {
	// input N
	int N;
	scanf("%d", &N);

	// variable
	bool* chk = new bool[N];
	for (int i = 0; i < N; i++) chk[i] = false;
	int* num = new int[N];

	// make memory
	int** numArr = new int* [N];
	for (int i = 0; i < N; i++) {
		numArr[i] = new int[N];
	}

	// Input
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &numArr[i][j]);
		}
	}

	// input location a.k.a member number
	for (int i = 0; i < N; i++) {
		num[i] = i;
	}

	int* store = new int[N];
	combi(0, N, 0, num, numArr, store, chk);

	// delete memory
	for (int i = 0; i < N; i++) {
		delete(numArr[i]);
	}
	delete(numArr);
	delete(chk);
	delete(store);

	printf("%d", gap);

	return 0;
}
