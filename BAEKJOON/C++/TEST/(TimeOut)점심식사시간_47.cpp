#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Ÿ��
struct Person
{
	int x,y,arrive;
};

// ��� ��ġ�� �����ð��� ������ �迭
Person p_arr[10];

// �Ÿ��� ���� ���� ť
deque<Person> a_q;
deque<Person> b_q;

// ���
struct Stair
{
	int x, y,k;
};

// ��
int MAP[11][11];

// �ַ��
void solution(int test_case);

// ���Լ�
bool compare(Person a, Person b)
{
	return a.arrive < b.arrive;
}

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
	// ���簢�� ����
	int N;
	cin >> N;

	// ��� ��
	int person_num = 0;

	// ��� ��
	Stair a;
	Stair b;
	int s_num = 0;

	// �Է�
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> MAP[i][j];
			
			if (MAP[i][j] == 1) // ��� ����
			{
				Person p;
				p.x = i;
				p.y = j;
				p.arrive = 0;

				p_arr[person_num] = p;
				person_num += 1;
			}
			else if (MAP[i][j] > 1) // ��� ����
			{
				Stair s;
				s.x = i;
				s.y = j;
				s.k = MAP[i][j];
				if (s_num == 0)
				{
					a = s;
					s_num += 1;
				}
				else
				{
					b = s;
					s_num += 1;
				}
			}
		}
	}

	// �ɸ��� �ð�
	int time = 10000;

	for (int i = 0; i <= person_num; i++) // ����
	{
		vector<int> permt;
		for (int j = 0; j < person_num-i; j++) permt.push_back(0);
		for (int j = 0; j < i; j++) permt.push_back(1);
		sort(permt.begin(), permt.end());

		do{// �۹����̼� ����
			for (int p_idx = 0; p_idx < person_num; p_idx++)
			{
				// �����ð� ������Ʈ
				if (permt[p_idx] == 0)
				{
					p_arr[p_idx].arrive = abs(p_arr[p_idx].x - a.x) + abs(p_arr[p_idx].y - a.y);
					a_q.push_back(p_arr[p_idx]);
				}
				else
				{
					p_arr[p_idx].arrive = abs(p_arr[p_idx].x - b.x) + abs(p_arr[p_idx].y - b.y);
					b_q.push_back(p_arr[p_idx]);
				}
			}

			//cout << a_q.size() << ' ' << b_q.size() << '\n';

			// �����ð����� ����
			sort(a_q.begin(), a_q.end(), compare);
			sort(b_q.begin(), b_q.end(), compare);

			// ���� ������ ������ ����� �������� �ð� ���
			int a_last = 0; // ���� ������� �������� ��, ���� �����ִ� ����� �̵��Ϸ� �ð�
			while ((int)a_q.size() > 3 && !a_q.empty())
			{
				a_last = max(a_last + a.k, a_q.front().arrive + 1 + a.k);
				a_q.pop_front();
			}
			if (!a_q.empty()) a_last = max(a_last + a.k, a_q.back().arrive + 1 + a.k);

			int b_last = 0; // ���� ������� �������� ��, ���� �����ִ� ����� �̵��Ϸ� �ð�
			while ((int)b_q.size() > 3 && !b_q.empty())
			{
				b_last = max(b_last + b.k, b_q.front().arrive + 1 + b.k);
				b_q.pop_front();
			}
			if (!b_q.empty()) b_last = max(b_last + b.k, b_q.back().arrive + 1 + b.k);

			time = min(max(a_last, b_last), time);

			// ���� ���� Ŭ����
			a_q.clear();
			b_q.clear();

		} while (next_permutation(permt.begin(), permt.end()));
	}

	cout << "#" << test_case << ' ' << time << '\n';
}
