#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int dp[101][100001];
vector<pair<int, int>> thing; // ����, ��ġ

int knapsack(int idx, int total) { // �ش� ��ġ�� �ִ� �� ��ȯ
	// �� �� ��ģ ���� �ٽ� ���� ����
	if (dp[idx][total] > 0) return dp[idx][total];
	
	if (idx == n) return 0;
	
	int value_add = 0; 
	int value_not_add = 0;

	// ����
	if(total + thing[idx].first <= k)
		value_add = thing[idx].second + knapsack(idx + 1, total + thing[idx].first);

	// ������ ����
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

// memoization�� ����� ��
// ���� ���ó�� �ش� idx�� �� ���� value ���� �����Ͽ� ����Ѵ�.