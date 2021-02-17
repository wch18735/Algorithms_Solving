#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solution(int test_case);

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
	int max_num = 0; 
	int min_num = 123456789;
	int sum = 0;
	int tmp;
	for (int i = 0; i < 10; i++)
	{
		cin >> tmp;
		sum += tmp;
		max_num = max(tmp, max_num);
		min_num = min(tmp, min_num);
	}

	sum -= (max_num + min_num);

	cout << '#' << test_case << ' ' << (int)floor(((double)sum / 8 + 0.5)) << '\n';

}