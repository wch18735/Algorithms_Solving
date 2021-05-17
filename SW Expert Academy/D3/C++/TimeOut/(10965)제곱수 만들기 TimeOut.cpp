#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

void solution(int test_case);

int main(int argc, char* argv[])
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
	// input N
	int N;
	cin >> N;
	
	// result map
	map<int, int> results;

	// add results by factorization
	int n = 2;
	int target = N;
	while (n <= N && target != 1)
	{
		while (target % n == 0)
		{
			// divide
			target /= n;

			// add to result map
			auto results_find = results.find(n);
			if (results_find == results.end())
			{
				results.insert(make_pair(n, 1));
			}
			else
			{
				results_find->second += 1;
			}
		}
		
		n++;
	}

	int answer = 1;
	for (auto i = results.begin(); i != results.end(); i++)
	{
		int factor = i->first;
		int factor_num = i->second;

		while (factor_num % 2 != 0)
		{
			answer *= factor;
			factor_num += 1;
		}
	}

	// testcase
	cout << '#' << test_case << ' ';
	cout << answer << '\n';
}