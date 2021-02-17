#include <iostream>

using namespace std;

void solution(int test_case);
int N;

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		solution(test_case);
	}
	return 0;
}

void solution(int test_case)
{
	cin >> N;

	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 == 0) res -= i;
		else res += i;
	}

	cout << '#' << test_case << ' ' << res << '\n';
}