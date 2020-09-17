#include<iostream>
#include<math.h>

using namespace std;

long long int powerMod(long long int a,long long int b, long long int c)
{
	if (b == 0) return 1;
	else if (b % 2 == 0)
	{
		return powerMod(((a % c) * (a % c)) % c, b / 2, c) % c;
	}
	else
	{
		return ((a % c) * powerMod(((a % c) * (a % c)) % c, b / 2, c)) % c;
	}
}

int main(void)
{
	long long int a, b, c;
	cin >> a >> b >> c;

	cout << powerMod(a, b, c);

	return 0;
}

// https://onsil-thegreenhouse.github.io/programming/problem/2018/03/29/problem_math_power/
// pow(a,b) 는 세 가지 경우로 나뉠 수 있다.
// 1) b==0 : pow(a,b) = 1 이다.
// 2) b % 2 == 0: pow(a, b/2) * pow(a, b/2)
// 3) b % 2 != 0: pow(a, b/2) * pow(a, b/2) * a