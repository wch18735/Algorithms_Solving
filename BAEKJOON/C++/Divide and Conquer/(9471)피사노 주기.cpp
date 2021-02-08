#include <iostream>
#include <vector>

using namespace std;

bool check_2n(int m)
{
	while (m % 2 == 0)
	{
		m /= 2;
		if (m == 1) return true;
	}
	return false;
}

bool check_5n(int m)
{
	while (m % 5 == 0)
	{
		m /= 5;
		if (m == 1) return true;
	}
	return false;
}

bool check_2_by_5n(int m)
{
	if (m % 2 != 0) return false;
	m /= 2;

	return check_5n(m);
}

bool check_10n(int m)
{
	while (m % 10 == 0)
	{
		m /= 10;
		if (m == 1) return true;
	}
	return false;
}

int solution(int m);

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int n, m;
		cin >> n >> m;

		cout << n << ' ' << solution(m) << '\n';
	}

	return 0;
}

int solution(int m)
{
	int count = 0;
	int temp;
	int fn_1 = 0;
	int fn_2 = 1;

	do
	{
		// fn_1 에 fn_2를 넣고, fn_2에 fn_1 + fn_2 를 대입
		temp = fn_1;
		fn_1 = fn_2;
		fn_2 = (fn_1 + temp) % m;
		count += 1;

	} while (!(fn_1 == 0 && fn_2 == 1));

	return count;
}