#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int n, idx;
		cin >> n >> idx;
		int num;
		int count = 1;

		// priority and index
		deque<pair<int, int>> entry;
		priority_queue<int> pq;
		vector<pair<int, int>> Answer;

		for (int i = 0; i < n; i++) {
			cin >> num;
			entry.push_back({ num, i });
			pq.push(num);
		}

		while (!entry.empty()) {
			if (entry.front().first == pq.top()) {
				pq.pop();
				Answer.push_back(entry.front());
				entry.pop_front();
			}
			else {
				entry.push_back(entry.front());
				entry.pop_front();
			}
		}

		for (int i = 0; i < (int)Answer.size(); i++) {
			if (Answer[i].second == idx) {
				cout << i + 1 << '\n';
				break;
			}
		}

		entry.clear();
		Answer.clear();
	}

	return 0;
}