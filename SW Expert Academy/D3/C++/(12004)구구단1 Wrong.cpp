#include<iostream>
#include<algorithm>

using namespace std;

bool prime_number[101];

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	// prime number list
	fill(prime_number, prime_number + 101, true);
	prime_number[0] = false;
	prime_number[1] = false;
	for (int i = 2; i*i <= 100; i++)
	{
		if (prime_number[i] == false) continue;

		int n = i + i;
		while (n <= 100)
		{
			prime_number[n] = false;
			n += i;
		}
	}


	int num;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> num;

		if (num <= 10)
		{
			cout << '#' << test_case << ' ' << "Yes\n";
			continue;
		}

		if (num > 81)
		{
			cout << '#' << test_case << ' ' << "No\n";
			continue;
		}

		if (prime_number[num] || num % 10 == 0)
		{
			cout << '#' << test_case << ' ' << "No\n";
			continue;
		}

		cout << '#' << test_case << ' ' << "Yes\n";
		continue;
	}

	return 0;
}