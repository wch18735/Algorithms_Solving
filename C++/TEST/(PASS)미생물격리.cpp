#include<iostream>

using namespace std;

// ��
int Map[101][101];

// ����
struct G
{
	int x, y, amount,dir;
	int tmp = 0;
};

// �̻��� ����
G g_arr[1001];

// ����
const int dx[5] = {0,0,0,-1,1};
const int dy[5] = {0,-1,1,0,0};

// �ַ��
void solution(int test_case);

void map_print(int N);

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
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= K; i++)
	{
		int y, x, amount, dir;
		cin >> y >> x >> amount >> dir;

		g_arr[i].x = x;
		g_arr[i].y = y;
		g_arr[i].amount = amount;
		g_arr[i].dir = dir;
	}

	for (int i = 0; i < M; i++) // M �ð�����
	{
		// �̵��ϸ鼭 ��ġ�� Map�� ��ġ��Ŵ
		for (int g_idx = 1; g_idx <= K; g_idx++)
		{
			// ����� �����̸�
			if (g_arr[g_idx].dir == -1) continue;

			// �� ��ǥ
			int nx = g_arr[g_idx].x + dx[g_arr[g_idx].dir];
			int ny = g_arr[g_idx].y + dy[g_arr[g_idx].dir];

			// �ش� ��ǥ�� ��ǰ�̸�
			if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1)
			{
				g_arr[g_idx].amount /= 2;

				if (g_arr[g_idx].amount == 0)
				{
					g_arr[g_idx].dir = -1;
					continue;
				}

				if (g_arr[g_idx].dir % 2 == 1) g_arr[g_idx].dir += 1;
				else g_arr[g_idx].dir -= 1;

				// �ڱ� ��ġ ������Ʈ
				g_arr[g_idx].x = nx;
				g_arr[g_idx].y = ny;
			}

			// ������ ��ġ�� ���
			if (Map[ny][nx] != 0)
			{
				// ��ģ ����
				int g = Map[ny][nx];

				// ������ �� (���� ���� ������ �� �켼)
				if (g_arr[g].amount < g_arr[g_idx].amount)
				{
					g_arr[g_idx].tmp += g_arr[g].amount;
					g_arr[g_idx].tmp += g_arr[g].tmp;
					
					// ���� ������ ó��
					g_arr[g].dir = -1;
					
					// �ش� ��ġ�� ���ο� ���� ��ġ
					Map[ny][nx] = g_idx;
					
					// ���� ��ǥ ������Ʈ
					g_arr[g_idx].x = nx;
					g_arr[g_idx].y = ny;
				}
				else
				{
					g_arr[g].tmp += g_arr[g_idx].amount;
					g_arr[g_idx].dir = -1;
				}
			}
			else // �̵� ��ġ�� �ƹ��͵� ���� ���
			{
				// �̵� ��ġ�� ���� idx �ΰ� �Ѿ
				Map[ny][nx] = g_idx;
				g_arr[g_idx].x = nx;
				g_arr[g_idx].y = ny;
			}
		}

		//map_print(N);

		// �̵��� ��� �������� Map Ŭ����
		for (int g_idx = 1; g_idx <= K; g_idx++)
		{
			if (g_arr[g_idx].dir == -1 && Map[g_arr[g_idx].y][g_arr[g_idx].x] == 0) continue;
			else Map[g_arr[g_idx].y][g_arr[g_idx].x] = 0;

			if (g_arr[g_idx].tmp != 0) // ���������� ������ ��
			{
				g_arr[g_idx].amount += g_arr[g_idx].tmp;
				g_arr[g_idx].tmp = 0;
			}

			// Ŭ����
			Map[g_arr[g_idx].y][g_arr[g_idx].x] = 0;
		}
	}

	int Answer = 0;

	for (int i = 1; i <= K; i++)
	{
		if (g_arr[i].dir == -1) continue;
		else {
			Answer += g_arr[i].amount;
		}
	}

	cout << '#' << test_case << ' ' << Answer << '\n';

	// ���� tmp �ʱ�ȭ
	for (int i = 1; i <= K; i++) g_arr[i].tmp = 0;

	return;
}

void map_print(int N)
{
	// �� ������
	cout << '\n';
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cout << Map[row][col] << ' ';
		} cout << '\n';
	} cout << '\n';
}