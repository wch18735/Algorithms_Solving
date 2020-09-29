#include <iostream>
#include <vector>

using namespace std;

#define DENOM 1000

vector<vector<int>> matrix_mul(vector<vector<int>> matrix_a, vector<vector<int>> matrix_b)
{
	// matrix_a 와 matrix_b 는 정사각 행렬

	int n = (int)matrix_a.size();

	vector<int> num(n,0);
	vector<vector<int>> re_matrix;
	for (int i = 0; i < n; i++) re_matrix.push_back(num);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				re_matrix[i][j] += (matrix_a[i][k] % DENOM) * (matrix_b[k][j] % DENOM) % DENOM;
			}
			re_matrix[i][j] %= DENOM;
		}
	}

	return re_matrix;
}

vector<vector<int>> matrix_power(vector<vector<int>> matrix, long long int num)
{
	if (num == 1) return matrix;
	else if (num % 2 == 0)
	{
		return matrix_power(matrix_mul(matrix, matrix), num / 2);
	}
	else {
		return matrix_mul(matrix, matrix_power(matrix_mul(matrix, matrix), num / 2));
	}
}

int main(void)
{
	int n; long long int num;

	cin >> n >> num;

	vector<vector<int>> matrix;
	vector<int> numvec(n);

	for (int i = 0; i < n; i++) matrix.push_back(numvec);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	matrix = matrix_power(matrix, num);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] % DENOM << ' ';
		} cout << '\n';
	}

	return 0;
}