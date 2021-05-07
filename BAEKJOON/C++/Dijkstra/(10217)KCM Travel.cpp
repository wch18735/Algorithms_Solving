#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// �ڷ��� ����
typedef tuple<int, int, int> next_info;
vector<next_info> tickets[10001];
int dp[101][10001];
const int MAXNUM = 123456789;

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N, M, K;
		cin >> N >> M >> K;

		// �ʱ�ȭ
		fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), MAXNUM);
		for (int i = 1; i <= M; i++) tickets[i].clear();

		// ���� ��� �Է�
		for (int i = 0; i < K; i++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			tickets[u].push_back({ v,c,d });
		}

		// dijkstra ���� ť
		priority_queue<next_info, vector<next_info>, greater<next_info>> pq;

		// dp �ʱ�ȭ (total time, total cost, node number)
		dp[1][0] = 0;
		pq.push({ 0, 0, 1 });

		while (!pq.empty())
		{
			int current_time = get<0>(pq.top());
			int current_cost = get<1>(pq.top());
			int current_node = get<2>(pq.top());
			pq.pop();

			for (int adj_idx = 0; adj_idx < (int)(tickets[current_node].size()); adj_idx++)
			{
				next_info ni = tickets[current_node][adj_idx];
				
				int next_node = get<0>(ni);
				int next_cost = current_cost + get<1>(ni);
				int next_time = current_time + get<2>(ni);

				// ������ ������ �ʰ��� ��
				if (next_cost > M) continue;

				// dp[next_node][next_cost] > next_time �� �ƴ� ��
				if (dp[next_node][next_cost] <= next_time) continue;

				// dp ������Ʈ
				dp[next_node][next_cost] = next_time;
				pq.push({ next_time, next_cost, next_node });
			}
		}

		// ���� Ȯ��
		int answer = MAXNUM;
		for (int i = 1; i <= M; i++) answer = min(answer, dp[N][i]);

		if (answer == MAXNUM) cout << "Poor KCM\n";
		else cout << answer << '\n';
	}

	return 0;
}