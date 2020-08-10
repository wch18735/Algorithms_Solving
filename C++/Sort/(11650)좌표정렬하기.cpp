#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	vector<pair<int, int>> location_xy; // x,y
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		location_xy.push_back(pair<int, int>(a, b));
	}

	sort(location_xy.begin(), location_xy.end(), compare);

	for (int i = 0; i < T; i++) {
		printf("%d %d\n", location_xy[i].first, location_xy[i].second);
	}

	return 0;
}

// 문제풀면서 느낀점
// cin, cout 보다 scanf, printf 가 훨씬 빠르다
// iostream은 시간초과 -> scanf, printf는 통과