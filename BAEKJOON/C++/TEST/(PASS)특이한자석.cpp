#include<iostream>
#include<deque>
#include<math.h>

using namespace std;

// �ַ��
void solution(int test_case);

// ���׳�
struct magnet {
	deque<int> polar;
};

// �ڼ� �迭
magnet mg_array[5];

// ȸ��
struct rot
{
	int mg_num;
	int direction;
};
rot rot_array[20];

// ȸ�� üũ
int chk[5];

void rotation(int mg_num, int dir);

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
	// ȸ�� ��
	int K;
	cin >> K;

	// �Է�
	int polar;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			cin >> polar;
			mg_array[i].polar.push_back(polar);
		}
	}

	// ȸ�� ����
	int mg_num, dir;
	for (int i = 0; i < K; i++)
	{
		cin >> mg_num >> dir;

		rotation(mg_num, dir);
	}

	// ��
	int answer = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (mg_array[i].polar[0] == 1) answer += (int)pow(2, i - 1);
	}

	// Ŭ����
	for (int i = 1; i <= 4; i++)
	{
		mg_array[i].polar.clear();
	}

	cout << '#' << test_case << ' ' << answer << '\n';
}

void rotation(int mg_num, int dir)
{
	// ���� ������ ���
	int left_mg = mg_num - 1;
	int right_mg = mg_num + 1;

	// ���� �ڼ� ȸ��
	chk[mg_num] = 1;

	// ���� ���� üũ
	bool left_flag = false;
	if (left_mg > 0 && mg_array[left_mg].polar[2] != mg_array[mg_num].polar[6] && chk[left_mg] == 0) left_flag = true;

	// ���� ���� üũ
	bool right_flag = false;
	if (right_mg <= 4 && mg_array[mg_num].polar[2] != mg_array[right_mg].polar[6] && chk[right_mg] == 0) right_flag = true;

	// flag �� ���� �Լ� ȣ��
	if (left_flag) rotation(left_mg, (-1) * dir);
	if (right_flag) rotation(right_mg, (-1) * dir);

	// �ڱ� mg_num ��ġ ȸ��
	if (dir == 1) // �ð����
	{
		mg_array[mg_num].polar.push_front(mg_array[mg_num].polar.back());
		mg_array[mg_num].polar.pop_back();
	}
	else if (dir == -1) // �ݽð����
	{
		mg_array[mg_num].polar.push_back(mg_array[mg_num].polar.front());
		mg_array[mg_num].polar.pop_front();
	}

	// chk �ʱ�ȭ
	chk[mg_num] = 0;
}
