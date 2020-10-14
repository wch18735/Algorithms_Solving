#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

// �ַ��
void solution(int test_case);

// ��
int info_map[370][370];	// information
int na_map[370][370];	// non-activate
int a_map[370][370];	// activate

// �� ���
void printMap(int map[370][370]);

// �� Ŭ����
void clear_map(int map[370][370]);

// ����Ʈ
#define base 160

// ��ġ �ڷ��� ����
typedef pair<int, int> Point;

// ť
deque<pair<Point, int>> bunsikQ; // ����ť
deque<pair<Point, int>> next_bunsikQ; // �ؽ�Ʈ ����ť
deque<pair<Point, int>> non_activeQ; // ��Ȱ��ť
deque<pair<Point, int>> activeQ; // Ȱ��ť

// count
int count_non(int map[370][370]);
int count_active(int map[370][370]);

// ����
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = {0, 1, 0, -1};

// �� �Լ�
bool compare(pair<Point, int> a, pair<Point, int> b)
{
	// ����� ���� ����
	return a.second > b.second;
}

/* ------------------------------------------------- */
/* ------------------------------------------------- */

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// �ַ��
		solution(test_case);

		// ���� �� Ŭ����
		for (int i = 0; i < 370; i++)
		{
			for (int j = 0; j < 370; j++)
			{
				info_map[i][j] = 0;
				na_map[i][j] = 0;
				a_map[i][j] = 0;
			}
		}

		// ���� ť Ŭ����
		bunsikQ.clear();
		non_activeQ.clear();
		activeQ.clear();
	}

	return 0;
}

/* ------------------------------------------------- */
/* ------------------------------------------------- */

// �ַ��
void solution(int test_case)
{
	// �Է�
	int N, M, K; // ����, ����, �ð�
	cin >> N >> M >> K;

	// �ʱ� �� �Է� (�ʱ�: ��Ȱ�� ť�� ����)
	for (int i = 0; i < N; i++) // ����
	{
		for (int j = 0; j < M; j++) // ����
		{
			// base �������� �Է�
			cin >> info_map[base + i][base + j];

			// ������� �ִ� ĭ�̶�� ��Ȱ�� ť�� ����
			if (info_map[base + i][base + j] != 0) non_activeQ.push_back({ Point(base + i,base + j),info_map[base + i][base + j] });
		}
	}

	// K �ð� ��
	// K = 1 �̸� 1�ð����� ������ ��
	for (int time = 0; time <= K; time++)
	{
		// ************ ���� �� ������Ʈ ***************
		while(!bunsikQ.empty())
		{
			// ���ĵ� ��ġ �޾ƿ�
			Point point = bunsikQ.front().first; // ����� ������������ ����: ���� �۾���
			int life = bunsikQ.front().second;

			// �ش� ��� ����
			bunsikQ.pop_front();

			// �ش� ��ġ 0���� Ȯ��
			if (info_map[point.first][point.second] == 0)
			{
				// �ش� ��ġ�� ���� �����ϸ� ���� ����
				info_map[point.first][point.second] = life;

				// �̸� ��Ȱ�� ť�� ����
				non_activeQ.push_back({ point, life });
			}
		
		}



		// ************* ��Ȱ�� �� ������Ʈ ***********
		// 0���� ū �� -1 �ϴ� ��, �̶� �� ���� 0�� �Ǹ� (Ȱ���̸�) Ȱ�� ť�� ����
		for (int i = 0; i < 370; i++)
		{
			for (int j = 0; j < 370; j++)
			{
				if (na_map[i][j] > 0)
				{
					na_map[i][j] -= 1;
					if (na_map[i][j] == 0) activeQ.push_back({ Point(i,j), info_map[i][j] });
				}
			}
		}
		
		while (!non_activeQ.empty()) 
		{
			// ť���� ����
			Point point = non_activeQ.front().first;
			int life = non_activeQ.front().second;
			non_activeQ.pop_front(); // ����


			// ��ġ�� ��� ����
			na_map[point.first][point.second] = life;
		}

		// *********** Ȱ�� �� ������Ʈ *************
		for (int i = 0; i < 370; i++) // ������ ���� 0���� ū �͵� -1
		{
			for (int j = 0; j < 370; j++)
			{
				if (a_map[i][j] > 0)
				{
					a_map[i][j] -= 1;
				}
			}
		}
		
		//// �ؽ�Ʈ ���� ť���� ���� ť�� �̵�
		//while (!next_bunsikQ.empty())
		//{
		//	bunsikQ.push_back(next_bunsikQ.front());
		//	next_bunsikQ.pop_front();
		//}

		// ���� ��ŭ �̾Ƽ� Ȱ�� �ʿ� ����� ����
		while (!activeQ.empty()) 
		{
			// ��ǥ
			Point point = activeQ.front().first;
			int life = activeQ.front().second;
			activeQ.pop_front();

			// �� ��ġ�� ����� ����
			a_map[point.first][point.second] = life;

			// ���� ť�� �� ���� ����
			for (int i = 0; i < 4; i++)
			{
				// �̹� �ڸ��� �ִٸ�
				if (info_map[point.first + dx[i]][point.second + dy[i]] != 0) continue;

				// �ؽ�Ʈ ���� ť�� �� ���� ���� ����
				bunsikQ.push_back({ Point(point.first + dx[i], point.second + dy[i]), life });
			}
		}

		// ����� ������ sort
		sort(bunsikQ.begin(), bunsikQ.end(), compare);

		//printMap(info_map);
		/*cout << "non active: " << count_non(na_map) << '\n';
		cout << "active: " << count_active(a_map) << '\n';
		cout << '\n';*/
	}

	// ��Ȱ�� �ʰ� Ȱ�� �ʿ��� 0���� ū ��
	int Answer = 0;
	for (int i = 0; i < 370; i++)
	{
		for (int j = 0; j < 370; j++)
		{
			if (na_map[i][j] > 0)
			{
				Answer += 1;
			}
			if (a_map[i][j] > 0)
			{
				Answer += 1;
			}
		}
	}

	cout << '#' << test_case << ' ' << Answer << '\n';
}

// �� ��� (140 ~ 210)
void printMap(int map[370][370])
{
	cout << '\n';
	for (int i = 140; i < 210; i++)
	{
		for (int j = 140; j < 210; j++)
		{
			cout << map[i][j] << ' ';
		} cout << '\n';
	}
	cout << '\n';
}

// ���� ����
int count_non(int map[370][370])
{
	int non = 0;
	for (int i = 0; i < 370; i++)
	{
		for (int j = 0; j < 370; j++)
		{
			if (map[i][j] > 0)
			{
				non += 1;
			}
		}
	}
	return non;
}

int count_active(int map[370][370])
{
	int active = 0;
	for (int i = 0; i < 370; i++)
	{
		for (int j = 0; j < 370; j++)
		{
			if (map[i][j] > 0)
			{
				active += 1;
			}
		}
	}
	return active;
}

// ��� ��
// 1) test_case �� ���� ������ ���� ������ �׻� Ŭ�����ϴ� ����!!
// 2) �۷ι� �Լ��� �ٽ� �ʱ�ȭ�ϴ� ���
// 3) ��¥ �������� Ŭ��� ���� �߿�...