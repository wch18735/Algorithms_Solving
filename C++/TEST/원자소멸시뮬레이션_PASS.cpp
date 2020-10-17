#include<iostream>
#include<map>
#include<vector>

using namespace std;

// ���� ����ü
struct atom {
	int x;
	int y;
	int direction;
	int energy;
};

// �ַ��
void solution(int test_case);

// ��
int atom_map[4002][4002];

// ���� �迭 (�ִ� 1000��)
atom atom_array[1001];

// ���� (�����¿�)
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { 1,-1,0,0 };

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
	// ���� ����
	int N;
	cin >> N;
	int atom_num = N;

	// �Է� 
	for (int i = 1; i <= N; i++)
	{
		int x, y, d, e;
		cin >> x >> y >> d >> e;

		atom_array[i].x = (x + 1000) * 2;
		atom_array[i].y = (y + 1000) * 2;
		atom_array[i].direction = d;
		atom_array[i].energy = e;
	}
	
	// ������ ���ⷮ
	int energy = 0;

	// ���� �̵�
	for (int t = 0; t < 4002; t++)
	{
		// ���� ���� 1���̸� �浹 �߻�X
		if (atom_num <= 1) break;

		// �̵�, ��ħ ����
		for (int i = 1; i <= N; i++)
		{
			// �̹� �浹�� ���Ҵ� Ž�� ����
			if (atom_array[i].direction == -1) continue;

			// ���� ��ġ
			int nx = atom_array[i].x + dx[atom_array[i].direction];
			int ny = atom_array[i].y + dy[atom_array[i].direction];

			// ���� ��ġ�� ���� �ٱ��̸� ����
			if (nx < 0 || nx > 4001 || ny < 0 || ny > 4001)
			{
				atom_array[i].direction = -1;
				atom_num -= 1;
				continue;
			}

			if (atom_map[ny][nx] != 0) // �̵� ��ġ�� ���� ������ ��
			{
				// ���� ���� �浹�����Ƿ� ���� ���� �ٿ���
				atom_array[i].direction = -1;
				atom_num -= 1;

				// ������ ����
				energy += atom_array[i].energy;

				// �����ߴ� ���� ������ 4�� ǥ��
				int idx = atom_map[ny][nx];
				atom_array[idx].direction = 4;
			}
			else // ���� �̵�
			{
				// �ʿ� �̵� ǥ��
				atom_map[ny][nx] = i;

				// �ڱ� �ڽ� ��ġ ������Ʈ
				atom_array[i].x = nx;
				atom_array[i].y = ny;
			}
		}

		// ��ģ �κ� ���� �� �ʿ��� ���� (�ߺ� ����)
		for (int i = 1; i <= N; i++)
		{
			// ���ܵ� ���Ҵ� ����
			if (atom_array[i].direction == -1) continue;

			// �ش� ���Ұ� �浹���� ��
			if (atom_array[i].direction == 4)
			{
				// ���ҿ��� ����
				atom_array[i].direction = -1;

				// ���� ���� �ٿ���
				atom_num -= 1;

				// ���� ������ ����
				energy += atom_array[i].energy;

				// �� �ٽ� �ʱ�ȭ
				atom_map[atom_array[i].y][atom_array[i].x] = 0;
			}
			else // ���� �̵��� ����
			{
				// �� �ʱ�ȭ
				atom_map[atom_array[i].y][atom_array[i].x] = 0;
			}
		}
	}

	cout << '#' << test_case << ' ' << energy << '\n';
}