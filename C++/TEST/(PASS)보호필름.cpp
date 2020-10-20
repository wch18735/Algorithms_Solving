#include <iostream>

using namespace std;

// �ַ��
void solution(int test_case);

// �ʸ�
int film[21][21];
int origin[21][21];

// ����, ����, �հݱ���
int D, W, K;

// �ַ��
void solution(int test_case);

// �˻�
bool check_film();

// ���� ����
int inject_state[21];

// �ּ� ���� Ƚ��
int min_cnt = 20;

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		solution(test_case);
	}

	return 0;
}

void inject_film(int film_idx, int cnt)
{
	// ���� �Ϸ�
	if (film_idx == D + 1)
	{
		if (check_film())
		{
			if (min_cnt > cnt) min_cnt = cnt;
		}
		return;
	}

	// film_idx �� �����ϴ� ������ Ȯ��
	if (inject_state[film_idx] == 1) 
	{
		// A�� ���� film_idx �� ����
		for (int i = 1; i <= W; i++) film[film_idx][i] = 0;
		inject_film(film_idx + 1, cnt);
		
		// B�� ����
		for (int i = 1; i <= W; i++) film[film_idx][i] = 1;
		inject_film(film_idx + 1, cnt);

		// film_idx �ٽ� ���� ����
		for (int i = 1; i <= W; i++) film[film_idx][i] = origin[film_idx][i];
	}
	else
	{
		inject_film(film_idx + 1, cnt);
	}

	return;
}

void update_inject(int film_idx, int cnt)
{
	// ����ġ��
	if (cnt >= min_cnt) return; // �� ���� ���� �� �ʿ� ����
	
	if (cnt > K) return;

	// ���� ���� ������Ʈ �Ϸ�
	if (film_idx == D + 1)
	{
		// ������� ���¸� �̿��� ���� �� �˻�
		inject_film(1, cnt);

		return;
	}


	for (int i = 0; i < 2; i++)
	{
		inject_state[film_idx] = i;
		
		if (i == 0) update_inject(film_idx + 1, cnt);
		else update_inject(film_idx + 1, cnt + 1);
	}

}

void solution(int test_case)
{
	// ����, ����, �հݱ���
	cin >> D >> W >> K;

	// �ʸ��Է�
	for (int i = 1; i <= D; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> film[i][j];
		}
	}

	// ���� ����
	for (int i = 1; i <= D; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			origin[i][j] = film[i][j];
		}
	}

	// �ʱ� �հݿ��� �˻�
	if (check_film() || K == 1)
	{
		cout << '#' << test_case << ' ' << 0 << '\n';
		return;
	}

	// ���� ���� ���� (���)
	update_inject(1, 0);

	// ���
	cout << '#' << test_case << ' ' << min_cnt << '\n';

	// �ʱ�ȭ
	min_cnt = 20;
}

bool check_film()
{
	for (int i = 1; i <= W; i++)
	{
		bool line_pass = false;
		for (int j = 1; j + K - 1 <= D; j++)
		{
			int start = film[j][i];
			int cnt = 0;
			for (int t = 0; t < K; t++)
			{
				if (film[j + t][i] == start) cnt++;
			}
			if (cnt == K)
			{
				line_pass = true;
			}
		}
		if (line_pass == false) return line_pass;
	}

	return true;
}