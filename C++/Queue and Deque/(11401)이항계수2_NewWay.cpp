#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM 1000000007

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<int> odd_line(n+1,0);
	vector<int> even_line(n+1,0);

	odd_line[0] = 1;
	odd_line[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0) // even_line 에 저장
		{
			for (int j = 0; j <= i && j <= k; j++)
			{
				if (j == 0) even_line[0] = odd_line[0];
				else 
				{
					even_line[j] = (odd_line[j - 1]%MAX_NUM) + (odd_line[j]%MAX_NUM);
				}
			}
		}
		else // odd_line 에 저장
		{
			for (int j = 0; j <= i && j <= k; j++)
			{
				if (j == 0) odd_line[0] = even_line[0];
				else
				{
					odd_line[j] = (even_line[j - 1]%MAX_NUM) + (even_line[j]%MAX_NUM);
				}
			}
		}

		/*if (i % 2 == 0)
		{
			for (int t = 0; t <= k; t++) cout << even_line[t] << ' ';
			cout << ": even";
			cout << '\n';
		}
		else
		{
			for (int t = 0; t <= k; t++) cout << odd_line[t] << ' ';
			cout << ": odd";
			cout << '\n';
		}*/
	}

	if (n % 2 == 0)
	{
		cout << even_line[k];
	}
	else
	{
		cout << odd_line[k];
	}

	return 0;
}