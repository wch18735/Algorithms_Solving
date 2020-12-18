#include<iostream>
#include<queue>

using namespace std;

void print_pq(priority_queue<int, vector<int>> a);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, less<int>> left_pq;
	priority_queue<int, vector<int>, greater<int>> right_pq;

	int num, input_num;
	cin >> num;

	cin >> input_num;
	left_pq.push(input_num);
	cout << left_pq.top() << '\n';

	for (int i = 1; i < num; i++)
	{
		cin >> input_num;

		if (left_pq.top() < input_num) right_pq.push(input_num);
		else left_pq.push(input_num);
		
		if ((int)left_pq.size() < (int)right_pq.size())
		{
			left_pq.push(right_pq.top());
			right_pq.pop();
		}
		else if((int)left_pq.size() - (int)right_pq.size() >= 2)
		{
			right_pq.push(left_pq.top());
			left_pq.pop();
		}

		cout << left_pq.top() << '\n';
	}

	return 0;
}

/*
	0. �Է��� ����
	1. ������ �ϳ� �� ���ų� ���� ����
	2. ���ʺ��� ū ���̸� ���������� ����
	2-1. �̶�, ������ ���̰� ���ʺ��� ������ ������ top�� �������� �ű�� pop()
	3. ���ʺ��� ������ �������� ����
	3-1. �̶�, ���� �����̶� �������̶� 2�� �̻� ���̳��� �� ���� ���������� �ֱ�
	4. ������ top�� ��ȯ
*/

void print_pq(priority_queue<int, vector<int>> a)
{
	for (int i = 0; i < (int)a.size(); i++)
	{
		cout << a.top() << ' ';
		a.pop();
	} cout << '\n';
}