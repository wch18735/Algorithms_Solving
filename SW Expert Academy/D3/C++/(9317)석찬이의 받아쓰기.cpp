#include<iostream>
#include<string>

using namespace std;

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	int N;
	int cnt = 0;
	string str1, str2;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		cin >> str1;
		cin >> str2;

		for (int i = 0; i < N; i++)
		{
			if (str1[i] != str2[i]) cnt += 1;
		}

		cout << "#" << test_case << " " << N - cnt << '\n';
		cnt = 0;
	}

	return 0;
}