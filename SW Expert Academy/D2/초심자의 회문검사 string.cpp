#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string str;
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
	cin >> str;
	int len = (int)str.size();

	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
		{
			cout << '#' << test_case << ' ' << 0 << '\n';
			return;
		}
	}

	cout << '#' << test_case << ' ' << 1 << '\n';
}
