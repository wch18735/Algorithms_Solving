#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void backtrack(int count, int N, vector<int> numArr, vector<pair<char,int>> operArr, int result, int *minPtr, int *maxPtr) {
	// Leaf
	if (count == N) {
		if (result > *maxPtr) *maxPtr = result;
		if (result < *minPtr) *minPtr = result;
		return;
	}

	// Not Leaf
	for (int i = 0; i < operArr.size(); i++) {
		for (int j = 0; j < operArr[i].second; j++) {
			if (operArr[i].first == '+') {
				operArr[i].second -= 1;
				backtrack(count + 1, N, numArr, operArr, result + numArr[count], minPtr, maxPtr);
				operArr[i].second += 1;
			}
			if (operArr[i].first == '-') {
				operArr[i].second -= 1;
				backtrack(count + 1, N, numArr, operArr, result - numArr[count], minPtr, maxPtr);
				operArr[i].second += 1;
			}
			if (operArr[i].first == '*') {
				operArr[i].second -= 1;
				backtrack(count + 1, N, numArr, operArr, result * numArr[count], minPtr, maxPtr);
				operArr[i].second += 1;
			}
			if (operArr[i].first == '/') {
				operArr[i].second -= 1;
				backtrack(count + 1, N, numArr, operArr, result / numArr[count], minPtr, maxPtr);
				operArr[i].second += 1;
			}
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> numArr;
	vector<pair<char, int>> operArr;
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		numArr.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		int num = 0;
		scanf("%d", &num);
		if (num == 0) continue;
		if(i == 0) operArr.push_back(pair<char, int>('+', num));
		if(i == 1) operArr.push_back(pair<char, int>('-', num));
		if(i == 2) operArr.push_back(pair<char, int>('*', num));
		if(i == 3) operArr.push_back(pair<char, int>('/', num));
	}

	int* maxPtr;
	int* minPtr;
	int max = -1000000000;
	int min = 1000000000;
	maxPtr = &max;
	minPtr = &min;

	backtrack(1, N, numArr, operArr, numArr[0], minPtr, maxPtr);

	printf("%d \n%d", max, min);

	return 0;
}