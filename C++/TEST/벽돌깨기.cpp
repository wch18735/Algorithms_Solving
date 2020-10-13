#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/* �ڷ��� */
typedef pair<int, int> Point;
int MAP[16][13];

/* �Լ� */
void solution(int test_case);
int boom(int MAP[16][13], int W, int H, int left_biz);
void Mcopy(int original_MAP[16][13], int copy_MAP[16][13]);

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

/* �ַ�� */
void solution(int test_case)
{
	int N, W, H;
	cin >> N >> W >> H;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> MAP[i][j];
		}
	}

	cout << '#' << test_case << ' ' << boom(MAP, W, H, N) << '\n';

	return;
}

/* �Լ� ���� */
// �� ����
void Mcopy(int original_MAP[16][13], int copy_MAP[16][13])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			copy_MAP[i][j] = original_MAP[i][j];
		}
	}

	return;
}

// �� ���
void PrintMap(int target_MAP[16][13], int W, int H)
{
	cout << '\n';
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cout << target_MAP[i][j] << ' ';
		} cout << '\n';
	}
}

// ��ź ����
int boom(int target_MAP[16][13], int W, int H, int left_biz)
{
	// Baseline
	if (left_biz == 0)
	{
		// ���� ���� ���� (MAP���� ���� 0�� �ƴ� ��)
		int cnt = 0;
		for (int i = 1; i <= H; i++)
		{
			for (int j = 0; j <= W; j++)
			{
				if (target_MAP[i][j] != 0) cnt += 1;
			}
		}

		return cnt;
	}

	// ���� ��
	int Answer = 1000;

	// ���� MAP ������ ��
	int copy_MAP[16][13];

	// ����ִ� ���� ����
	int zero_count = 0;

	for (int w = 1; w <= W; w++) // �־��� �� �߿��� ����
	{
		// ���� �� ī��
		Mcopy(target_MAP, copy_MAP);

		// �ش� ������ ó������ 0�� �ƴ� �� ã��
		int top_x = 0;
		for (int row = 1; row <= H; row++)
		{
			if (copy_MAP[row][w] == 0) continue;
			else
			{
				top_x = row;
				break;
			}
		}

		if (top_x == 0)
		{
			zero_count += 1;
			continue;
		}

		// Point p = (x,y) : ��Ʈ�� ��ġ
		Point p = Point(top_x, w);

		// ���� �߰�
		deque<pair<Point, int>> boomque;
		boomque.push_back({ p, copy_MAP[p.first][p.second] });

		// ���� �� ������: ���� ����
		while (!boomque.empty())
		{
			// ���� ��ġ ����
			Point target_point = boomque.front().first;
			int explode = boomque.front().second - 1;
			boomque.pop_front();

			// ���� ��ġ 0���� ����
			copy_MAP[target_point.first][target_point.second] = 0;

			// �� Ž��: ���� Ž��
			int row_start = max(1, target_point.first - explode);
			int row_end = min(H, target_point.first + explode);
			for (int i = row_start; i <= row_end; i++)
			{
				if (copy_MAP[i][target_point.second] <= 1) copy_MAP[i][target_point.second] = 0;
				else if (copy_MAP[i][target_point.second] > 1)
				{
					// �����ϰ�
					boomque.push_back({ Point(i,target_point.second), copy_MAP[i][target_point.second]});

					// �ʿ� ����ֱ�
					copy_MAP[i][target_point.second] = 0;
				}
			}

			// �� Ž��: ���� Ž��
			int col_start = max(1, target_point.second - explode);
			int col_end = min(W, target_point.second + explode);
			for (int i = col_start; i <= col_end; i++)
			{
				int tmp_explode = copy_MAP[target_point.first][i];

				if (tmp_explode <= 1) copy_MAP[target_point.first][i] = 0;
				else if (tmp_explode > 1)
				{
					// ���� ���� �����ϰ�
					boomque.push_back({ Point(target_point.first, i), tmp_explode });

					// ��Ʈ����
					copy_MAP[target_point.first][i] = 0;
				}
			}
		} // �� ���� ����

		// 1���� columns �� ����
		for (int col = 1; col <= W; col++) {
			// columns
			vector<int> columns;
			// �ش� column ���� 0�� �ƴ� �κ��� ��� ����
			for (int i = 1; i <= H; i++)
			{
				if (copy_MAP[i][col] > 0)
				{
					columns.push_back(copy_MAP[i][col]);
					copy_MAP[i][col] = 0;
				}
			}

			// �ش� �� 0�� �κ��� ���ְ� �ٽ� ����
			int row_idx = 0;
			while (!columns.empty())
			{
				copy_MAP[H - row_idx][col] = columns.back();
				columns.pop_back();
				row_idx += 1;
			}
		}

		// ���� w ���� �ν��� ��, map ����
		Answer = min(Answer, boom(copy_MAP, W, H, left_biz - 1));
	}

	if (zero_count == W) return 0;
	else return Answer;
}

