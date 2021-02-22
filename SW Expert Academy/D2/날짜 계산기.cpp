#include<iostream>

// 1/31, 2/28, 3/31, 4/30, 5/31, 6/30, 7/31, 8/31, 9/30, 10/31, 11/30, 12/31
using namespace std;
void solution(int test_case);

int mm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month, day, t_month, t_day;

int main(int argc, char* argv)
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) solution(i);
	return 0;
}

void solution(int test_case)
{
	cin >> month >> day >> t_month >> t_day;

	int res = 0;
	for (int i = month; i < t_month; i++)
	{
		res += mm[i];
	}

	res -= (day-1);
	res += t_day;

	cout << '#' << test_case << ' ' << res << '\n';

	return;
}