#include<iostream>
#include<string>

using namespace std;

void solution(int testcase);

int main(void)
{
	int T;
	cin >> T;

	for (int testcase = 1; testcase <= T; testcase++)
	{
		solution(testcase);
	}
}

void solution(int testcase)
{
	string str;
	cin >> str;

	int period = 1;
	bool while_flag = true;
	while (while_flag)
	{
		for (int i = 0; i <= period; i++)
		{
			if (i == period)
			{
				while_flag = false;
				break;
			}

			if (str[i] == str[i + period]) continue;
			else
			{
				period += 1;
				break;
			}
		}
		
		if (period > 10) break;
	}

	cout << '#' << testcase << ' ' << period << '\n';
}