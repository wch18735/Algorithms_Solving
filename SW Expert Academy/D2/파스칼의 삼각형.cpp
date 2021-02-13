#include<iostream>

using namespace std;

void solution(int test_case);

int main(void)
{
	int test_case;
	cin >> test_case;

	for (int i = 1; i <= test_case; i++)
	{
		solution(i);
	}
	
	return 0;
}

void solution(int test_case)
{
	cout << '#' << test_case << '\n';
	int up[11] = { 0, };
	int low[11] = { 0, };
	int N;
	cin >> N;
	
	int* tmp;
	int* left; 
	int* right;
	left = up; right = low;

	up[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << left[j] << ' ';
			right[j] += left[j];
			right[j + 1] += left[j];
			left[j] = 0;
		}
		
		tmp = left;
		left = right;
		right = tmp;

		cout << '\n';
	}
}