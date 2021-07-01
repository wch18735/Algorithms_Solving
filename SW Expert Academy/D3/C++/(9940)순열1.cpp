#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];

bool solution()
{
	int N;
	cin >> N;

	int _in;
	for (int i = 0; i < N; i++)
	{
		cin >> _in;
		arr[_in] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0) return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		fill(arr, arr + 100001, 0);
		if (solution()) cout << "#" << test_case << " Yes\n";
		else cout << "#" << test_case << " No\n";
	}

	return 0;
}