#include<iostream>
#include<vector>
#include<string>

using namespace std;

void checkTree(int x, int y, int n, vector<vector<int>> Map) {
	int one_flag = 1;
	int zero_flag = 1;


	// Check
	if (Map[x][y] == 0) // Zero
	{
		for (int i = x; i < n + x; i++)
		{
			for (int j = y; j < n + y; j++)
			{
				if (Map[i][j] == 1) zero_flag = 0;
			}
		}
	}
	else if (Map[x][y] == 1)
	{
		for (int i = x; i < n + x; i++)
		{
			for (int j = y; j < n + y; j++)
			{
				if (Map[i][j] == 0) one_flag = 0;
			}
		}
	}


	// Print
	if (Map[x][y] == 0)
	{
		if (zero_flag == 1) 
		{
			cout << 0;
		}
		else 
		{
			cout << '(';
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					checkTree(x + (n >> 1) * i, y + (n >> 1) * j, (n >> 1), Map);
				}
			}
			cout << ')';
		}
	}
	else if (Map[x][y] == 1)
	{
		if (one_flag == 1)
		{
			cout << 1;
		}
		else
		{
			cout << '(';
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					checkTree(x + (n >> 1) * i, y + (n >> 1) * j, (n >> 1), Map);
				}
			}
			cout << ')';
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	string tmpstr;

	vector<vector<int>> Map;
	vector<int> subMap;

	for (int i = 0; i < n; i++)
	{
		cin >> tmpstr;

		for (int j = 0; j < n; j++)
		{
			if (tmpstr[j] == '0') subMap.push_back(0);
			else if(tmpstr[j] == '1') subMap.push_back(1);
		}

		Map.push_back(subMap);
		subMap.clear();
	}

	checkTree(0, 0, n, Map);

	return 0;
}