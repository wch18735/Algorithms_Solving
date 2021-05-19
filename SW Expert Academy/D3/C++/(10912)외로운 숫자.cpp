#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

char ch_arr[26];

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	string str;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		// input
		cin >> str;
		for (int i = 0; i < (int)str.size(); i++)
		{
			ch_arr[(char)str[i] - 'a'] += 1;
		}

		// good flag
		bool good_flag = true;
		
		// test case print
		cout << '#' << test_case << ' ';
		for (int i = 0; i < 26; i++)
		{
			if (ch_arr[i] % 2 != 0)
			{
				good_flag = false;
				cout << (char)('a' + i);
			}
		} 

		if (good_flag) cout << "Good\n";
		else cout << '\n';

		// initialize
		fill(ch_arr, ch_arr + 26, 0);
	}

	return 0;
}