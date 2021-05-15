#include<iostream>
#include<algorithm>

using namespace std;

int num_arr[2001];
int dp_matrix[2001][2001];

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 수열 입력
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> num_arr[i];

	// dp_matrix 초기화
	fill(&dp_matrix[0][0], &dp_matrix[2000][2000], false);
	
	// palindrome 길이가 1일 때
	for (int i = 1; i <= N; i++) dp_matrix[i][i] = true;
	
	// palindrome 길이가 2일 때
	for (int i = 1; i <= N - 1; i++)
	{
		if (num_arr[i] == num_arr[i + 1]) dp_matrix[i][i + 1] = true;
	}

	// palindrome 길이가 3 이상일 때
	for (int dif = 2; dif <= N; dif++)
	{
		for (int left_point = 1; left_point + dif <= N; left_point++)
		{
			int right_point = left_point + dif;
			if (num_arr[left_point] == num_arr[right_point] && dp_matrix[left_point + 1][right_point - 1])
			{
				dp_matrix[left_point][right_point] = true;
			}
		}
	}

	int M, S, E;
	cin >> M;

	for (int m = 0; m < M; m++)
	{
		cin >> S >> E;
		cout << dp_matrix[S][E] << '\n';
	}

	return 0;
}