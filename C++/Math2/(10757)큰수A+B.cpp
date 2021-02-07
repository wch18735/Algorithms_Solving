#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solution();

char add_num[100000];

int atoi_(char ch)
{
	return (int)(ch - '0');
}

char itoa_(int a)
{
	return (char)(a + '0');
}

int main(void)
{
	solution();
	return 0;
}

void solution()
{
	string a, b, res;
	cin >> a >> b;

	int max_len = max(a.length(), b.length());
	int carry = 0;
	int temp = 0;

	for (int i = 0; i < max_len; i++)
	{
		// add carry
		temp += carry;
		carry = 0;

		// sum digit
		if (i < (int)a.length())
		{
			temp += atoi_(a[(int)a.length() - i - 1]);
		}

		if (i < (int)b.length())
		{
			temp += atoi_(b[(int)b.length() - i -1]);
		}

		// assign carry
		if (temp >= 10)
		{
			temp -= 10;
			carry = 1;
		}

		// insert char temp
		add_num[i] = itoa_(temp);

		// init 0 to temp
		temp = 0;
	}

	if (carry == 1)
	{
		add_num[max_len] = itoa_(1);
		for (int i = max_len; i >= 0; i--) cout << add_num[i];
	}
	else
	{
		for (int i = max_len - 1; i >= 0; i--) cout << add_num[i];
	}
}