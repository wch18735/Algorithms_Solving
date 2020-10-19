#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/******** �ʰ� �ڷ��� *********/
// ��
int MAP[21][21];

// �湮 üũ�� ��
int CHMAP[21][21];

// �Ÿ���
int DMAP[21][21];

// (��ġ��, ��ġ��),(��ǥ��, ��ǥ��)
typedef pair<pair<int, int>, pair<int, int>> sonnim_info;
typedef pair<int, int> pos;


/******** �Լ� *********/
// solution ����
void solution();
void update_map(pos a);
void print_map(int TARGET[21][21], int n);
void init_map(int N_Size);
bool compare(pair<sonnim_info,int> a, pair<sonnim_info,int> b) // �� �Լ�
{
	if (a.second == b.second) // �Ÿ��� ���� ��
	{
		// ( (�մ� ��ġ, �մ� ������), �Ÿ�)
		if (a.first.first.first == b.first.first.first) return a.first.first.second < b.first.first.second;// ���� ���� ��
		else return a.first.first.first < b.first.first.first; // �� ��ȣ�� ���� ���
	}
	else return a.second < b.second; // �Ÿ��� ª�� ��
}

int main(void)
{
	solution();

	return 0;
}

void update_map(pos a, int N)
{
	// ��� ��
	int row = a.first;
	int col = a.second;

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	// position ��ġ
	deque<pair<int, int>> pos_queue;

	// ó�� ��ġ �ʱ�ȭ
	DMAP[row][col] = 0; // �Ÿ� 0
	CHMAP[row][col] = 1; // �湮��

	// ť�� �߰�
	pos_queue.push_back({ row, col });

	// �� ������Ʈ
	while (!pos_queue.empty())
	{
		// ť
		pos now_point = pos_queue.front();
		pos_queue.pop_front();
		int x = now_point.first;
		int y = now_point.second;

		// �� ���� �˻�
		for (int i = 0; i < 4; i++)
		{
			int tmp_x = x + dx[i];
			int tmp_y = y + dy[i];
			pos next_pos = { tmp_x, tmp_y };
			if (!(1 <= tmp_x && tmp_x <= N)) continue; // �� ��
			if (!(1 <= tmp_y && tmp_y <= N)) continue; // �� ��
			if (CHMAP[tmp_x][tmp_y] != 0) continue; // �湮�ߴ� ��
			if (MAP[tmp_x][tmp_y] == 1) continue; // ��

			pos_queue.push_back(next_pos); // ť�� ���� �߰�
			DMAP[tmp_x][tmp_y] = DMAP[x][y] + 1; // �ش� ��ġ�� �Ÿ� + 1
			CHMAP[tmp_x][tmp_y] = 1;
		}
	}
}

void init_map(int N_size)
{
	for (int i = 1; i <= N_size; i++)
	{
		for (int j = 1; j <= N_size; j++)
		{
			DMAP[i][j] = 0;
			CHMAP[i][j] = 0;
		}
	}
}

void print_map(int TARGET[21][21], int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << TARGET[i][j] << ' ';
		} cout << '\n';
	}
}

bool check_visit(pos a) // �ش� ��ġ�� �ýð� �湮�� �� �ִ���
{
	return CHMAP[a.first][a.second] == 1;
}

void solution()
{
	int N, M, Fuel;
	cin >> N >> M >> Fuel;

	// �� �Է�
	for (int i = 1; i <= N; i++) // �� ��ǥ
	{
		for (int j = 1; j <= N; j++) // �� ��ǥ
		{
			cin >> MAP[i][j];
		}
	}

	// �ý� ��ġ �Է�
	pair<int, int> taxi_pos;
	cin >> taxi_pos.first >> taxi_pos.second;

	// �°� �Է�
	deque <pair<sonnim_info, int>> sonnim_list; // �մ� ���� + �Ÿ�
	sonnim_info sonnim; 
	for (int i = 0; i < M; i++)
	{
		cin >> sonnim.first.first >> sonnim.first.second >> sonnim.second.first >> sonnim.second.second;
		sonnim_list.push_back({ sonnim, 0 });
	}

	bool fail = false;

	while (!sonnim_list.empty())
	{

		// �ý� ��ġ�� ������Ʈ
		update_map(taxi_pos, N);

		// sonnim_list �� �ִ� ��ġ�� ��� ������Ʈ
		for (int i = 0; i < (int)sonnim_list.size(); i++)
		{
			// �մ� ���� ���
			sonnim = sonnim_list[i].first;
			int x = sonnim.first.first; // �մ� ��ġ ��
			int y = sonnim.first.second; // �մ� ��ġ ��

			// �ý� ~ �մ� �Ÿ� ������Ʈ
			sonnim_list[i].second = DMAP[x][y];
		}

		// �Ÿ� -> �� -> �� ������ sort
		sort(sonnim_list.begin(), sonnim_list.end(), compare);

		// �ýð� �¿� �մ� �̱�
		sonnim = sonnim_list.front().first;
		int d = sonnim_list.front().second;
		sonnim_list.pop_front(); // ���� �� �����

		// �ýð� �մ��� �¿� �� �ִ��� Ȯ�� (�����ִ��� ����)
		if (!check_visit(sonnim.first))
		{
			fail = true;
			break;
		}

		// �Ÿ� ���� �ٽ� ������Ʈ
		init_map(N);

		// �°� ������ �Ÿ� ������Ʈ
		update_map(sonnim.first, N);

		// �ýð� �մ��� �������� ������ �� �� �ִ��� Ȯ��
		if (!check_visit(sonnim.second))
		{
			fail = true;
			break;
		}

		// ��ǥ ��ġ���� �Ÿ�
		int target_x = sonnim.second.first;
		int target_y = sonnim.second.second;
		int d_t = DMAP[target_x][target_y];

		// ���� �Ǵ�
		if (Fuel - d - d_t >= 0)
		{
			Fuel = Fuel - d + d_t; // ���� ������Ʈ
			taxi_pos = sonnim.second; // �ý� ��ġ�� ��������
		}
		else
		{
			fail = true;
			break;
		}

		// �� �ʱ�ȭ
		init_map(N);
	}

	if (fail == true) cout << -1;
	else cout << Fuel;
	
	return;
}