#include <iostream>
#include <algorithm>

using namespace std;

void solution(int test_case);

int arr_a[20];
int arr_b[20];

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
	int a, b;
	cin >> a >> b;
	if (a <= b)
	{
		for (int i = 0; i < a; i++) cin >> arr_a[i];
		for (int i = 0; i < b; i++) cin >> arr_b[i];
	}
	else
	{
		for (int i = 0; i < a; i++) cin >> arr_b[i];
		for (int i = 0; i < b; i++) cin >> arr_a[i];
	}

	int res = -123456789;
	int tmp;
	for (int i = 0; i <= abs(b - a); i++)
	{
		tmp = 0;
		for (int j = 0; j < min(a, b); j++)
		{
			tmp += arr_a[j] * arr_b[j + i];
		}

		res = max(tmp, res);
	}

	cout << '#' << test_case << ' ' << res << '\n';

	return;
}