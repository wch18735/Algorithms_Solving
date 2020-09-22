#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int dp[101][100001];
vector<pair<int, int>> thing; // 무게, 가치

int knapsack(int idx, int total) { // 해당 위치의 최대 값 반환
	// 한 번 거친 곳은 다시 가지 않음
	if (dp[idx][total] > 0) return dp[idx][total];
	
	if (idx == n) return 0;
	
	int value_add = 0; 
	int value_not_add = 0;

	// 더함
	if(total + thing[idx].first <= k)
		value_add = thing[idx].second + knapsack(idx + 1, total + thing[idx].first);

	// 더하지 않음
	value_not_add = knapsack(idx + 1, total);

	return dp[idx][total] = max(value_add, value_not_add);
}

int main(void) {
	int weight, value;

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> weight >> value;
		thing.push_back({ weight, value });
	}

	cout <<  knapsack(0, 0);

	return 0;
}

// memoization을 사용할 때
// 위의 경우처럼 해당 idx와 그 때의 value 값을 저장하여 사용한다.