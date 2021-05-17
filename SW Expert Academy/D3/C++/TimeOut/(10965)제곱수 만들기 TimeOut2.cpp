#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

void solution(int test_case);

#define MAX_NUM 10000001
#define NOT_PRIME 1
#define PRIME 0
int era_che[MAX_NUM];
int prime_list[3500];

int main(int argc, char* argv[])
{
	int T;
	scanf("%d", &T);

	// eratosthenes
	era_che[0] = 1;
	era_che[1] = 1;
	int prime_idx = 0;
	for (int i = 2; i <= (int)sqrt(MAX_NUM) + 1; i++)
	{
		if (era_che[i] == NOT_PRIME) continue;
		else
		{
			// insert to prime list
			prime_list[prime_idx++] = i;

			// exclude prime numbers
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

	int dividend = N;
	int answer = 1;
	int i = 0;
	int prime_n = prime_list[i];
	while(dividend > 1)
	{
		if (dividend % prime_n == 0)
		{
			int cnt = 1;
			dividend /= prime_n;

			while (dividend % prime_n == 0)
			{
				cnt += 1;
				dividend /= prime_n;
			}

			while (cnt % 2 != 0)
			{
				answer *= prime_n;
				cnt += 1;
			}
		}
		
		// next prime number
		i++;
		prime_n = prime_list[i];
	}

	printf("#%d %d\n", test_case, answer);
}