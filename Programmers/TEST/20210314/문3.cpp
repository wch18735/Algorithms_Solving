#include<iostream>
#include<algorithm>

using namespace std;

int toji[33][33];
int dp[33][33][33][33];
int N;

int select_area(int a, int b, int c, int d);
int search(int row_s, int row_f, int col_s, int col_f);

int main(void)
{
	// �� ����
	cin >> N;

	// �Է�
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> toji[i][j];
		}
	}

	int res = search(1, N, 1, N);

	cout << res;

	return 0;
}

int search(int row_s, int row_f, int col_s, int col_f)
{
	if (row_s == row_f && col_s == col_f) return 0;
	
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	if (row_s != row_f)
	{
		// 1�� ����
		a = select_area(row_s, (row_s + row_f) / 2, col_s, col_f) + search((row_s + row_f) / 2 + 1, row_f, col_s, col_f);
	}
	
	if (row_s != row_f)
	{
		// 2�� ����
		b = select_area((row_s + row_f) / 2 + 1, row_f, col_s, col_f) + search(row_s, (row_s + row_f) / 2, col_s, col_f);
	}

	if (col_s != col_f)
	{
		// 3�� ����
		c = select_area(row_s, row_f, col_s, (col_s + col_f) / 2) + search(row_s, row_f, (col_s + col_f) / 2 + 1, col_f);
	}

	if (col_s != col_f)
	{
		// 4�� ����
		int d = select_area(row_s, row_f, (col_s + col_f) / 2 + 1, col_f) + search(row_s, row_f, col_s, (col_s + col_f) / 2);
	}

	// �� �� �ִ� �� ��ȯ
	return max(max(a, b), max(c, d));
}

int select_area(int row_s, int row_f, int col_s, int col_f)
{
	int max_val = 0;

	if (dp[row_s][row_f][col_s][col_f] != 0) return dp[row_s][row_f][col_s][col_f];

	// �ش� �������� �ִ� �� ã��
	for (int i = row_s; i <= row_f; i++)
	{
		for (int j = col_s; j <= col_f; j++)
		{
			max_val = max(toji[i][j], max_val);
		}
	}
	
	// return
	dp[row_s][row_f][col_s][col_f] = max_val;
	return max_val;
}