#include<iostream>

using namespace std;

void solution();

int main(void)
{
	solution();
	return 0;
}

void solution()
{
	int ORIGIN, TEMP, NEW;
	int CNT = 0;
	cin >> ORIGIN;

	TEMP = ORIGIN;
	while (true)
	{
		if (TEMP < 10)
		{
			TEMP = TEMP*11;
			CNT += 1;
			if (TEMP == ORIGIN) break;
		}
		else
		{
			TEMP = (TEMP % 10) * 10 + ((TEMP / 10) + (TEMP % 10)) % 10;
			CNT += 1;
			if (TEMP == ORIGIN) break;
		}
	}

	cout << CNT;
}