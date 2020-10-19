#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void solution(int test_case);

// Ȱ�ַ�
int h_map[21][21];

// �˻翭
int check_seq[21];
int check_reverse[21];

// ����
struct interval
{
	int start = 0;
	int end = 0;
	int length = end - start + 1;

	interval() {}
	interval(int start, int end) : start(start), end(end) 
	{
		this->length = end - start + 1;
	};
};

// ������ ���� ����
vector<interval> inter_vec;

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
	// ����, Ȱ�ַ� ���� ����
	int N, X;
	cin >> N >> X;

	// ����
	int Answer = 0;

	// �ʿ� �Է�
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> h_map[i][j];
		}
	}

	// ���� �˻�
	for (int row = 1; row <= N; row++)
	{
		// ���� ����
		int start = 1;
		int end = 1;
		for (int i = 2; i <= N; i++)
		{
			if (h_map[row][start] == h_map[row][i]) end = i;
			else
			{
				inter_vec.push_back(interval(start, end));
				start = i;
				end = i;
			}

			if (i == N) inter_vec.push_back(interval(start, end));
		}

		for (int i = 0; i < (int)inter_vec.size(); i++) cout << inter_vec[i].length << ' ';
		cout << '\n';

		// �� row �� �ִ밪
		int max_num = 0;
		for (int i = 1; i <= N; i++) max_num = max(max_num, h_map[row][i]);

		// ���� ���ϴ� �� �����ϸ� false
		int possible = true;

		// ������ �˻� (�˻� Ƚ���� ���� - 1)
		for (int i = 0; i < (int)inter_vec.size()-1; i++)
		{
			// �ش� ���� ��ǥ ��
			int current_h = h_map[row][inter_vec[i].start];
			int next_h = h_map[row][inter_vec[i + 1].start];

			// Ȱ�ַ� ���� X �̻�
			if (inter_vec[i].length < X) // ���̰� ���� ���
			{	
				// �ִ� ���� �ƴϸ� fail
				if (h_map[row][inter_vec[i].start] != max_num)
				{
					possible = false;
				}
			}

			// ���� �� 1
			if (abs(next_h - current_h) != 1) possible = false;
			

			if (possible == false) break;
		}

		inter_vec.clear();

		if (possible == true) Answer += 1;
	}

	cout << '#' << test_case << ' ' << Answer << '\n';
}