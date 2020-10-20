#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

// �ַ��
void solution(int test_case);

// ����
int city[21][21];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		solution(test_case);
	}
	return 0;
}

void solution(int test_case)
{
	// ���� ũ��� �� �ϳ��� ���� ���� ���
	int N, M;
	cin >> N >> M;

	// �Է�
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> city[i][j];
		}
	}

	// �ִ� �� ����
	int house = 0;

	// K ��ŭ �Ǵ�
	for (int k = 1; k <= N+1; k++)
	{
		int cost = k * k + (k - 1) * (k - 1);

		// city�� ��� ��ǥ
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				// ����� ���� ������ �� ����
				int cnt = 0;

				// city[i][j] �������� ����� Ž��
				for (int row = max(1, i - k + 1); row <= min(N, i + k - 1); row++)
				{
					for (int col = max(1, j - k + 1); col <= min(N, j + k - 1); col++)
					{
						if (abs(i - row) + abs(j - col) < k && city[row][col] == 1)
						{
							cnt += 1;
						}
					}
				}

				// � ��� �Ǵ� (���� ���� ����!!)
				if (M * cnt - cost >= 0 && cnt > house) house = cnt;
			}
		}
	}

	cout << '#' << test_case << ' ' << house << '\n';

	// ���� ���� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			city[i][j] = 0;
		}
	}
}