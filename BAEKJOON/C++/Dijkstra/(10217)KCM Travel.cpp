#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// 자료형 정의
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

		// 초기화
		fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), MAXNUM);
		for (int i = 1; i <= M; i++) tickets[i].clear();

		// 인접 노드 입력
		for (int i = 0; i < K; i++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			tickets[u].push_back({ v,c,d });
		}

		// dijkstra 위한 큐
		priority_queue<next_info, vector<next_info>, greater<next_info>> pq;

		// dp 초기화 (total time, total cost, node number)
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

				// 가능한 수량을 초과할 때
				if (next_cost > M) continue;

				// dp[next_node][next_cost] > next_time 이 아닐 때
				if (dp[next_node][next_cost] <= next_time) continue;

				// dp 업데이트
				dp[next_node][next_cost] = next_time;
				pq.push({ next_time, next_cost, next_node });
			}
		}

		// 정답 확인
		int answer = MAXNUM;
		for (int i = 1; i <= M; i++) answer = min(answer, dp[N][i]);

		if (answer == MAXNUM) cout << "Poor KCM\n";
		else cout << answer << '\n';
	}

	return 0;
}