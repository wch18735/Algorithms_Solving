#include <stdio.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

using namespace std;
bool compare(pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else return a.second > b.second;
	
}

int main() {
	int N; // NÀº È¦¼ö
	int sum = 0;
	scanf("%d", &N);

	int *numArr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		
		numArr[i] = tmp;
		sum += tmp;
	}

	// sort
	sort(numArr, numArr + N);

	// »ê¼úÆò±Õ
	printf("%d\n", (int)round((double)sum / N));

	// Áß¾Ó°ª
	printf("%d\n", numArr[N / 2]);

	// ÃÖºó°ª
		// value, frequency
	vector<pair<int, int>> v;

		// initial vector input
	v.push_back(pair<int, int>(numArr[0], 1));

	int k = 0;

	for (int i = 1; i < N; i++) {
		if (v[k].first == numArr[i]) {
			v[k].second++;
		}
		else {
			v.push_back(pair<int, int>(numArr[i], 1));
			k++;
		}
	}

	sort(v.begin(), v.end(), compare);
	if (N == 1) {
		printf("%d\n", v[0].first);
	}
	else {
		if (v[0].second == v[1].second) printf("%d\n", v[1].first);
		else printf("%d\n", v[0].first);
	}
	// ¹üÀ§
	printf("%d", numArr[N - 1] - numArr[0]);
}