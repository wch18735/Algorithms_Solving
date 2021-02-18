#include<iostream>

using namespace std;

void solution(int test_case);

int sudoku[9][9];
int h_check[9];
int v_check[9];
int s_check[9];

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		solution(test_case);
	}
	return 0;
}

void input()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
		}
	}
}

void solution(int test_case)
{
	input();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i % 3 == 0 && j % 3 == 0)
			{
				for (int p = 0; p < 3; p++)
				{
					for (int q = 0; q < 3; q++)
					{
						s_check[sudoku[i + p][j + q] - 1] = 1;
					}
				}

				for (int p = 0; p < 9; p++)
				{
					if (s_check[p] == 0)
					{
						cout << '#' << test_case << ' ' << 0 << '\n';
						return;
					}
					s_check[p] = 0;
				}
			}

			h_check[sudoku[i][j] - 1] = 1;
			v_check[sudoku[j][i] - 1] = 1;
		}

		for (int p = 0; p < 9; p++)
		{
			if (h_check[p] == 0)
			{
				cout << '#' << test_case << ' ' << 0 << '\n';
				return;
			}
			h_check[p] = 0;
		}

		for (int p = 0; p < 9; p++)
		{
			if (v_check[p] == 0)
			{
				cout << '#' << test_case << ' ' << 0 << '\n';
				return;
			}
			v_check[p] = 0;
		}
	}

	cout << '#' << test_case << ' ' << 1 << '\n';
	return;
}