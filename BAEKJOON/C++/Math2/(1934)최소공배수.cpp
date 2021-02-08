#include<iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testcase;
	cin >> testcase;

	int a, b, G;
	for (int i = 0; i < testcase; i++)
	{
		cin >> a >> b;
		G = gcd(a, b);
		cout << a * b / G << '\n';
	}
	return 0;
}