#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int, int> b){
	// 끝나는 시간이 같을 때에는 
	// 시작 시간이 빠른 것으로
	// (8,8), (7,8) -> 이런 경우 (7,8) 이 먼저 나오도록
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(void) {
	int n;
	cin >> n;

	vector<pair<int, int>> conference;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		conference.push_back({ start, end });
	}

	// sorting 을 이용해
	// LEFT | start ---- end | RIGHT 중
	// LEFT 영역을 고민하지 않고 포함 관계를 유추할 수 있음
	// Greedy 하게 다음에 오는 회의시간이 RIGHT에만 포함된다면 추가하고
	// bound를 RIGHT 끝으로 옮김
	sort(conference.begin(), conference.end(), compare);

	int bound = 0;
	int Answer = 0;

	for (int i = 0; i < n; i++) {
		if (bound <= conference[i].second && bound <= conference[i].first) {
			Answer++;
			bound = conference[i].second;
		}
	}

	cout << Answer;

	return 0;
}