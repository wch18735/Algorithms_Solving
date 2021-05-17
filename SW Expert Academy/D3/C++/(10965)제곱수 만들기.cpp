#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cstdio>

using namespace std;

void solution(int test_case);

#define MAX_NUM 10000001
#define NOT_PRIME 1
#define PRIME 0
int era_che[MAX_NUM];
vector<int> prime_list;

int main(int argc, char* argv[])
{
	int T;
	scanf("%d", &T);

	// eratosthenes
	era_che[0] = 1;
	era_che[1] = 1;
	for (int i = 2; i <= (int)sqrt(MAX_NUM) + 1; i++)
	{
		if (era_che[i] == NOT_PRIME) continue;
		else
		{
			// insert I into prime_list
			prime_list.push_back(i);

			int idx = i + i;
			while (idx <= MAX_NUM - 1)
			{
				era_che[idx] = NOT_PRIME;
				idx += i;
			}
		}
	}

	// testcase solve with prime number cache
	for (int test_case = 1; test_case <= T; test_case++)
	{
		solution(test_case);
	}

	return 0;
}

void solution(int test_case)
{
	// input N
	int N;
	scanf("%d", &N);

	if (N == 1 || era_che[N] == PRIME)
	{
		cout << '#' << test_case << ' ' << N << '\n';
		return;
	}

	// factors
	vector<pair<int, int>> factors;

	int i = 0;
	int prime_square = prime_list[i] * prime_list[i];

	while (prime_square <= N)
	{
		if (N % prime_square == 0)
		{
			N /= prime_square;
		}
		else
		{
			i++;
			prime_square = prime_list[i] * prime_list[i];
		}
	}

	printf("#%d %d\n", test_case, N);
	//cout << '#' << test_case << ' ' << N << '\n';
}