#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second) 
		return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	int T;
	scanf("%d", &T);

	vector<pair<int, int>> numVec;

	for (int i = 0; i < T; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		numVec.push_back(pair<int, int>(a, b));
	}

	sort(numVec.begin(), numVec.end(), compare);

	for (int i = 0; i < T; i++) {
		printf("%d %d\n", numVec[i].first, numVec[i].second);
	}

	return 0;
}