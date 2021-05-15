#include<iostream>
#include<algorithm>

using namespace std;

int numArr[2001];
int palinDP[2001][2001];

const int not_visit = 2;

// MATCH WITH TimeOut4
int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// array input
	for (int i = 1; i <= N; i++) cin >> numArr[i];

	// DP init
	fill(&palinDP[0][0], &palinDP[2000][2000], not_visit);

	for (int len = 0; len <= N; len++)
	{
		for (int lp = 1; lp + len <= N; lp++)
		{
			// right point
			int rp = lp + len;

			// palindrome length 1
			if (lp == rp)
			{
				palinDP[lp][rp] = true;
				continue;
			}

			// if visited
			if (palinDP[lp][rp] != not_visit) continue;

			// not visit
			if (numArr[lp] == numArr[rp]) palinDP[lp][rp] = true;
			else 
			{
				int spread_lp = lp;
				int spread_rp = rp;
				
				while (0 < spread_lp and spread_rp <= N)
				{
					// exclude outer palinDP that is not need to be checked 
					palinDP[spread_lp][spread_rp] = false;
					spread_lp -= 1; spread_rp += 1;
				}
			}
		}
	}

	int M, S, E;
	cin >> M;

	for (int m = 0; m < M; m++)
	{
		cin >> S >> E;
		cout << palinDP[S][E] << '\n';
	}

	return 0;
}