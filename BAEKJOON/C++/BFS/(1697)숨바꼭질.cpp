#include <iostream>
#include <deque>

using namespace std;

#define MAXNUM 200001

int bfs(int pos, int target, int* dp) {
	int Answer = 0;

	deque<pair<int, int>> next_pos; // 위치,count
	
	next_pos.push_back({ pos, 0 });

	while (!next_pos.empty()) {
		int poped = next_pos.front().first;
		int count = next_pos.front().second;
		next_pos.pop_front();

		// target일 경우
		if (poped == target) {
			Answer = count;
			break;
		}

		// target이 아닐 경우

		if (poped * 2 <= MAXNUM) {
			if (dp[poped * 2] > count) {
				next_pos.push_back({ poped * 2, count + 1 });
				dp[poped * 2] = count+1;
			}
		}
		if (poped - 1 >= 0) {
			if (dp[poped - 1] > count) {
				next_pos.push_back({ poped - 1, count + 1 });
				dp[poped - 1] = count + 1;
			}
		}
		if (poped + 1 <= MAXNUM) {
			if (dp[poped + 1] > count) {
				next_pos.push_back({ poped + 1, count + 1 });
				dp[poped + 1] = count;
			}
		}
	}

	return Answer;
}

int main(void) {
	int pos, target;
	cin >> pos >> target;

	int dp[200001];
	fill_n(dp, MAXNUM, MAXNUM);

	int Answer = bfs(pos, target, dp);

	cout << Answer;

	return 0;
}