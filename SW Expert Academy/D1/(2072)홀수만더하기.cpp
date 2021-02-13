#include<iostream>

using namespace std;

int num_arr[10];
void solution(int testcase);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		solution(test_case);
	}
	return 0;
}

void solution(int testcase)
{
	int res = 0;
	int tmp;

	for (int i = 0; i < 10; i++)
	{
		cin >> tmp;
		if (tmp % 2 != 0) res += tmp;
		else continue;
	}

	cout << "#" << testcase << ' ' << res << '\n';
}