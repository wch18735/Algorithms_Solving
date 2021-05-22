#include<iostream>
#include<algorithm>

using namespace std;

bool check_list[101];

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	// init
	fill(check_list, check_list + 101, false);

	// fill check list
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			check_list[i * j] = true;
		}
	}

	int num;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> num;

		if (check_list[num]) cout << '#' << test_case << ' ' << "Yes\n";
		else cout << '#' << test_case << ' ' << "No\n";
	}

	return 0;
}