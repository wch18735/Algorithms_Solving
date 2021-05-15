#include<iostream>
#include<algorithm>

using namespace std;


void solution();
void dfs(int c_idx, int before);

typedef struct {
	int day;
	int profit;
} DAY;

int N, res;
int SUM[15];
DAY schedule[15];

int main(void)
{
	solution();
	return 0;
}

void input()
{
	cin >> N;
	int d, p;
	for (int i = 1; i <= N; i++)
	{
		cin >> d >> p;
		schedule[i].day = d;
		schedule[i].profit = p;
	}
}

void dfs(int c_idx, int before)
{
	// dfs
	int n_idx;
	for (int i = c_idx; i <= N; i++)
	{
		n_idx = i + schedule[i].day;
		if (n_idx > N+1) continue;
		if (SUM[i] < before + schedule[i].profit)
		{
			SUM[i] = before + schedule[i].profit;
			dfs(n_idx, SUM[i]);
		}
		else continue;
	}
}

void solution()
{
	// input
	input();

	// dfs
	dfs(1, 0);

	// answer
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		answer = max(answer, SUM[i]);
	}

	cout << answer;
}

// 간단한 dfs + pruning + memoization 문제인데 꼬이게 어렵게 풀었다.
// [dfs]
// - for

// [pruning]
// - n_idx = i + schedule[i].day;
// - if (n_idx > N + 1) continue;
// - if (SUM[i] < before + schedule[i].profit)

// [memoization]
// SUM[15]