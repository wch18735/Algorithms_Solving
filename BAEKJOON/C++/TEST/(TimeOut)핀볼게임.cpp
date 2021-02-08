#include<iostream>
#include<algorithm>

using namespace std;

// �ַ��
void solution(int test_case);

// �� ��
int pin_map[102][102];

// ��ġ
typedef pair<int, int> Point;
typedef pair<int, int> Direction;

// �Լ�
int bounce(Point p, Direction d, int N);
Direction block(int n, Direction d);
bool check_start(Point start, Point point);


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		solution(test_case);

		// pin_map �ʱ�ȭ
		for (int i = 0; i <= 101; i++)
		{
			for (int j = 0; j <= 101; j++)
			{
				pin_map[i][j] = 0;
			}
		}
	}
	return 0;
}

void solution(int test_case)
{
	// ���� ���� N �Է�
	int N;
	cin >> N;

	// �� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> pin_map[i][j];
		}
	}

	// �� �����ڸ� 5
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			if (i == 0 || i == N + 1) pin_map[i][j] = 5;
			else {
				if (j == 0 || j == N + 1) pin_map[i][j] = 5;
			}
		}
	}
	
	// ��
	int Answer = 0;

	// ����
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (pin_map[i][j] == 0)
			{
				for (int k = 0; k < 4; k++)
				{
					Answer = max(Answer, bounce(Point(i, j), Direction(dx[k], dy[k]), N));
				}
			}
		}
	}

	cout << '#' << test_case << ' ' <<  Answer << '\n';
}

void print_map(int N)
{
	// �� �����ڸ� 5
	cout << '\n';
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			cout << pin_map[i][j] << ' ';
		} cout << '\n';
	}
	cout << '\n';
}

int bounce(Point p, Direction d, int N)
{
	// ƨ��� Ƚ��
	int CNT = 0;
	
	// ���� ����
	Point start_p = p;

	// ���� ������ �������� �÷���
	bool start_flag = false;

	// ���� ��ġ������ Ž�� ����
	while (true)
	{
		// ��ǥ ����Ʈ
		/*cout << "position: (" << p.first << ' ' << p.second << ")\n";
		cout << "direction: (" << d.first << ' ' << d.second << ")\n";*/

		// ���⿡ ���� Ž��
		int value = 0; // �ش� ��ġ �� (0 ~ 10)
		Point next_point; // ���� ��ġ

		// ������ (���� ó�� 0�� �ƴ� �� ã��)
		if (d.first == 0 && d.second == 1)
		{
			for (int i = p.second + 1; i <= N + 1; i++)
			{
				// �������� ��ο� ������ �ִ��� Ȯ��
				start_flag = check_start(start_p, Point(p.first, i));

				if (pin_map[p.first][i] != value)
				{
					value = pin_map[p.first][i];
					next_point = Point(p.first, i);
					break;
				}
			}
		}
		
		// ���� (���� ó�� 0�� �ƴ� �� ã��)
		if (d.first == 0 && d.second == -1)
		{
			for (int i = p.second - 1; i >= 0; i--)
			{
				// �������� ��ο� ������ �ִ��� Ȯ��
				start_flag = check_start(start_p, Point(p.first, i));

				if (pin_map[p.first][i] != value)
				{
					value = pin_map[p.first][i];
					next_point = Point(p.first, i);
					break;
				}
			}
		}

		// �� (���� ó�� 0�� �ƴ� �� ã��)
		if (d.first == -1 && d.second == 0)
		{
			for (int i = p.first - 1; i >= 0; i--)
			{
				// �������� ��ο� ������ �ִ��� Ȯ��
				start_flag = check_start(start_p, Point(i,p.second));

				if (pin_map[i][p.second] != value)
				{
					value = pin_map[i][p.second];
					next_point = Point(i, p.second);
					break;
				}
			}
		}

		// �Ʒ� (���� ó�� 0�� �ƴ� �� ã��)
		if (d.first == 1 && d.second == 0)
		{
			for (int i = p.first + 1; i <= N+1; i++)
			{
				// �������� ��ο� ������ �ִ��� Ȯ��
				start_flag = check_start(start_p, Point(i, p.second));

				if (pin_map[i][p.second] != value)
				{
					value = pin_map[i][p.second];
					next_point = Point(i, p.second);
					break;
				}
			}
		}

		// �������� ��ο� �������� �ִ� ���
		if (start_flag) break;

		// ��Ȧ�� ���
		if (value == -1) break;

		// ���� ���� + ���� ���� == 0�� ���
		if (value == 5)
		{
			CNT = CNT * 2 + 1;
			break;
		}

		// ����̸�
		if (1 <= value && value <= 4)
		{
			// ��Ͽ� �ε����� ���⿡ ���� ���ο� ����
			Direction new_d = block(value, d);

			if (d.first + new_d.first == 0 && d.second + new_d.second == 0)
			{
				CNT = CNT * 2 + 1;
				break;
			}
			else {
				CNT += 1;
				p = next_point;
				d = new_d;
				continue;
			}
		}

		// ��Ȧ�̸�
		if (6 <= value && value <= 10)
		{
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					if (pin_map[i][j] == value && !(i == next_point.first && j == next_point.second))
					{
						// ��Ȧ ��ġ�� �ʱ�ȭ
						p = Point(i, j);
						break;
					}
				}
			}
			continue;
		}
	}
	//cout << '\n';
	return CNT;
}

// �ش� ��ǥ�� �������� ���� ��ġ����
bool check_start(Point start, Point point)
{
	return ((start.first == point.first) && (start.second == point.second));
}

// ��� ã��
Direction block(int n, Direction d)
{
	if (n == 1)
	{
		if (d.first == 0 && d.second == 1) return Direction(0, -1);
		if (d.first == 1 && d.second == 0) return Direction(0, 1);
		if (d.first == 0 && d.second == -1) return Direction(-1, 0);
		if (d.first == -1 && d.second == 0) return Direction(1, 0);
	}
	else if (n == 2)
	{
		if (d.first == 0 && d.second == 1) return Direction(0, -1);
		if (d.first == 1 && d.second == 0) return Direction(-1, 0);
		if (d.first == 0 && d.second == -1) return Direction(1, 0);
		if (d.first == -1 && d.second == 0) return Direction(0, 1);
	}
	else if (n == 3)
	{
		if (d.first == 0 && d.second == 1) return Direction(1, 0);
		if (d.first == 1 && d.second == 0) return Direction(-1, 0);
		if (d.first == 0 && d.second == -1) return Direction(0, 1);
		if (d.first == -1 && d.second == 0) return Direction(0, -1);
	}
	else if (n == 4)
	{
		if (d.first == 0 && d.second == 1) return Direction(-1, 0);
		if (d.first == 1 && d.second == 0) return Direction(0, -1);
		if (d.first == 0 && d.second == -1) return Direction(0, 1);
		if (d.first == -1 && d.second == 0) return Direction(1, 0);
	}
	else if (n == 5)
	{
		if (d.first == 0 && d.second == 1) return Direction(0, -1);
		if (d.first == 1 && d.second == 0) return Direction(-1, 0);
		if (d.first == 0 && d.second == -1) return Direction(0, 1);
		if (d.first == -1 && d.second == 0) return Direction(1, 0);
	}
}