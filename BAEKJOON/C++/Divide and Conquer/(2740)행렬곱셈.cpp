#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<vector<int>> matrix_a;
	vector<vector<int>> matrix_b;
	vector<vector<int>> matrix_c;

	int n, m;
	int m2, k;
	
	// Matrix A
	cin >> n >> m;
	vector<int> num1(m);
	for (int i = 0; i < n; i++) matrix_a.push_back(num1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix_a[i][j];
		}
	}

	// Matrix B
	cin >> m2 >> k;
	vector<int> num2(k);
	for (int i = 0; i < m2; i++) matrix_b.push_back(num2);

	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> matrix_b[i][j];
		}
	}

	// Matrix C
	vector<int> num3(k, 0);
	for (int i = 0; i < n; i++) matrix_c.push_back(num3);

	// Calculate
	for (int i = 0; i < n; i++)
	{
		for (int p = 0; p < k; p++)
		{
			for (int j = 0; j < m; j++)
			{
				matrix_c[i][p] += matrix_a[i][j] * matrix_b[j][p];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << matrix_c[i][j] << ' ';
		}cout << '\n';
	}

	return 0;
}