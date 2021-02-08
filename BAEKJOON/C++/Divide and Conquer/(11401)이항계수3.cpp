#include <iostream>

using namespace std;

#define MAXNUM 1000000007

long long int factorial(long long int n)
{
	long long int num = 1;
	for (long long int i = n; i >= 2; i--)
	{
		num *= i;
		num %= MAXNUM;
	}

	return num;
}

long long int power(long long int n, long long int p)
{
	if (p == 0) return 1;
	else if (p % 2 == 0)
	{
		return power(((n%MAXNUM) * (n%MAXNUM))%MAXNUM, p / 2) % MAXNUM;
	}
	else
	{
		return ((n%MAXNUM) * (power(((n % MAXNUM) * (n % MAXNUM)) % MAXNUM, p / 2)%MAXNUM)) % MAXNUM;
	}
}

int main(void)
{
	long long int n, k;

	cin >> n >> k;

	long long int A = factorial(n);
	long long int B1 = factorial(n - k);
	long long int B2 = factorial(k);
	long long int B = power((B1 % MAXNUM) * (B2 % MAXNUM) % MAXNUM, MAXNUM - 2);

	cout << (A % MAXNUM) * (B % MAXNUM) % MAXNUM;

	return 0;
}