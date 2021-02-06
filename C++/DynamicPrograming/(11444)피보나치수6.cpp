#include <iostream>

using namespace std;

// typedef
typedef long long ll;
typedef struct
{
	ll arr[2][2];
} matrix;

// function
void solution();

// variable
ll TARGET;

int main(void)
{
	solution();
	return 0;
}

matrix operator * (const matrix& a, const matrix& b)
{
	// temporary matrix
	matrix c;

	// matrix init
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			c.arr[i][j] = 0;
		}
	}

	// matrix multiplication 2x2
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				c.arr[i][j] += a.arr[i][k] * b.arr[k][j];
			}
			c.arr[i][j] %= 1000000007;
		}
	}

	return c;
}

matrix power(matrix a, ll n)
{
	matrix res;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == j) res.arr[i][j] = 1;
			else res.arr[i][j] = 0;
		}
	}

	while (n > 0) {
		if (n % 2 == 1)
		{
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}

void solution()
{
	cin >> TARGET;
	matrix a;
	a.arr[0][0] = 1; a.arr[0][1] = 1; a.arr[1][0] = 1; a.arr[1][1] = 0;
	matrix res = power(a, TARGET - 1);
	cout << res.arr[0][0] % 1000000007;
}