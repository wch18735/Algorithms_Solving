#include<iostream>
#include<string>

using namespace std;

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	string str;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> str;

		if (str[0] == str[1] && str[1] == str[2] && str[2] == str[3]) cout << '#' << test_case << " No\n";
		else if(str[0] == str[1] && str[2] == str[3]) cout << '#' << test_case << " Yes\n";
		else if(str[0] == str[2] && str[1] == str[3]) cout << '#' << test_case << " Yes\n";
		else if(str[0] == str[3] && str[1] == str[2]) cout << '#' << test_case << " Yes\n";
		else cout << '#' << test_case << " No\n";
	}

	return 0;
}