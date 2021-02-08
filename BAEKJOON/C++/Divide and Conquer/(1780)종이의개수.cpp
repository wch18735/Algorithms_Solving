#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM 2187

int Map[MAX_NUM][MAX_NUM];

int zeroPaper = 0;
int onePaper = 0;
int minusPaper = 0;



bool check_zero(int x, int y, int n, int Map[MAX_NUM][MAX_NUM])
{
	for (int i = x; i < n + x; i++)
	{
		for (int j = y; j < n + y; j++)
		{
			if (Map[i][j] != 0) return false;
		}
	}

	return true;
}

bool check_one(int x, int y, int n, int Map[MAX_NUM][MAX_NUM])
{
	for (int i = x; i < n + x; i++)
	{
		for (int j = y; j < n + y; j++)
		{
			if (Map[i][j] != 1) return false;
		}
	}

	return true;
}

bool check_minus(int x, int y, int n, int Map[MAX_NUM][MAX_NUM])
{
	for (int i = x; i < n + x; i++)
	{
		for (int j = y; j < n + y; j++)
		{
			if (Map[i][j] != -1) return false;
		}
	}

	return true;
}

void check_map(int x, int y, int n, int Map[MAX_NUM][MAX_NUM])
{
	if (Map[x][y] == -1) {
		if (check_minus(x, y, n, Map))
		{
			minusPaper += 1;
			return;
		}
		else {
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					check_map(x + (n / 3) * i, y + (n / 3) * j, n / 3, Map);
				}
			}
		}
	}
	else if (Map[x][y] == 0)
	{
		if (check_zero(x, y, n, Map))
		{
			zeroPaper += 1;
			return;
		}
		else {
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					check_map(x + (n / 3) * i, y + (n / 3) * j, n / 3, Map);
				}
			}
		}
	}
	else if (Map[x][y] == 1)
	{
		if (check_one(x, y, n, Map))
		{
			onePaper += 1;
			return;
		}
		else {
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					check_map(x + (n / 3) * i, y + (n / 3) * j, n / 3, Map);
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*vector<vector<int>> Map;
	vector<int> subMap;*/
	int n;
	int num;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> Map[i][j];
		}
	}

	check_map(0, 0, n, Map);

	cout << minusPaper << '\n';
	cout << zeroPaper << '\n';
	cout << onePaper << '\n';

	return 0;
}