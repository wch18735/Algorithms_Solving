#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
char str[10];
char str_rev[10];
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
	int cnt = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		str_rev[i] = str[i];
		cnt += 1;
	}

	for (int i = 0; i <= cnt; i++)
	{
		if (str_rev[cnt -1 -i] != str[i]) break;
		if (i == cnt - 1)
		{
			cout << '#' << test_case << ' ' << 1 << '\n';
			return;
		}
	}

	cout << '#' << test_case << ' ' << 0 << '\n';
}
