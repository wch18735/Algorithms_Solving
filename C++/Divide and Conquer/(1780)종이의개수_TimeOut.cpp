#include <iostream>
#include <vector>

using namespace std;

int zeroPaper = 0;
int onePaper = 0;
int minusPaper = 0;

bool check_zero(int x, int y, int n, vector<vector<int>> Map)
{
	int zero_flag = 1;
	
	for (int i = x; i < n + x; i++)
	{
		for (int j = y; j < n + y; j++)
		{
			if (Map[i][j] != 0) zero_flag = 0;
		}
	}

	return (zero_flag == 1);
}

bool check_one(int x, int y, int n, vector<vector<int>> Map)
{
	int one_flag = 1;

	for (int i = x; i < n + x; i++)
	{
		for (int j = y; j < n + y; j++)
		{
			if (Map[i][j] != 1) one_flag = 0;
		}
	}

	return (one_flag == 1);
}

bool check_minus(int x, int y, int n, vector<vector<int>> Map)
{
	int minus_flag = 1;

	for (int i = x; i < n + x; i++)
	{
		for (int j = y; j < n + y; j++)
		{
			if (Map[i][j] != -1) minus_flag = 0;
		}
	}

	return (minus_flag == 1);
}

void check_map(int x, int y, int n, vector<vector<int>> Map)
{
	if (check_minus(x, y, n, Map))
	{
		minusPaper += 1;
		return;
	}
	else if (check_zero(x, y, n, Map))
	{
		zeroPaper += 1;
		return;
	}
	else if (check_one(x, y, n, Map))
	{
		onePaper += 1;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			check_map(x + (n / 3) * i, y + (n / 3) * j, n / 3, Map);
		}
	}

	return;
}

int main(void) {
	vector<vector<int>> Map;
	vector<int> subMap;
	int n;
	int num;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			subMap.push_back(num);
		}
		Map.push_back(subMap);
		subMap.clear();
	}

	check_map(0, 0, n, Map);

	cout << minusPaper << '\n';
	cout << zeroPaper << '\n';
	cout << onePaper << '\n';

	return 0;
}