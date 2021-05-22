#include<iostream>
#include<map>
#include<string>

using namespace std;

map<char, char> mirror = {
	{'b', 'd'},
	{'p', 'q'},
	{'d', 'b'},
	{'q', 'p'}
};

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	string str;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> str;

		cout << '#' << test_case << ' ';
		for (auto i = str.rbegin(); i != str.rend(); i++) cout << mirror[*i];
		cout << '\n';
	}

	return 0;
}