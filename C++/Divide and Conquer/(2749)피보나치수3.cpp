#include <iostream>

using namespace std;

#define DENOM 1000000

int pisano_period(int m)
{
	int count = 0;
	int temp;
	int fn_1 = 0;
	int fn_2 = 1;

	do
	{
		temp = fn_1;
		fn_1 = fn_2;
		fn_2 = (temp + fn_1) % m;
		count += 1;

	} while (!(fn_1 == 0 && fn_2 == 1));

	return count;
}

int main(void)
{
	long long unsigned int n;
	int period = pisano_period(DENOM);

	cin >> n;

	int numIndex = n % period;

	int fn3, fn1 = 0, fn2 = 1;

	if (numIndex == 0) cout << fn1;
	else if (numIndex == 1) cout << fn2;
	else 
	{
		for (int i = 2; i <= numIndex; i++)
		{
			fn3 = (fn1 + fn2) % DENOM;
			fn1 = fn2;
			fn2 = fn3;
		}
		cout << fn3;
	}

	return 0;
}