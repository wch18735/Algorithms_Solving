#include<iostream>
#include<algorithm>

using namespace std;

const int IMP = 0;
const int POS = 1;
const int NV = 2;

int numArr[2001];
int palinDP[2001][2001];

// MATCH WITH TimeOut6
int palindrome(int a, int b)
{
	// use previous result
	if (palinDP[a][b] != NV) return palinDP[a][b];

	// End condition
	if (a == b)
	{
		palinDP[a][b] = POS;
		return POS;
	}
	else if (b == a + 1)
	{
		if (numArr[a] == numArr[b])
		{
			palinDP[a][b] = POS;
			return POS;
		}
		else
		{
			palinDP[a][b] = IMP;
			return IMP;
		}
	}

	// check condition: each side match and inner array is palindrome
	if (numArr[a] == numArr[b] && palindrome(a + 1, b - 1) == POS)
	{
		palinDP[a][b] = POS;
		return POS;
	}
	else
	{
		palinDP[a][b] = IMP;
		return IMP;
	}
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// input sequence
	for (int i = 1; i <= N; i++) cin >> numArr[i];

	// init palinDP
	fill(&palinDP[0][0], &palinDP[2000][2000], NV);

	int M, S, E;
	cin >> M;
	
	// check palindrome
	for (int m = 0; m < M; m++)
	{
		cin >> S >> E;

		if (S == E) cout << 1 << '\n';
		else if (E == S + 1)
		{
			if (numArr[S] == numArr[E]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else {
			// palindrome: check S ~ E is palindrome
			cout << palindrome(S, E) << '\n';
		}
	}

	return 0;
}