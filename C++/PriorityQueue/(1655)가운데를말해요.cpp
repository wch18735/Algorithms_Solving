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
	0. 입력이 들어옴
	1. 왼쪽이 하나 더 많거나 같은 숫자
	2. 왼쪽보다 큰 값이면 오른쪽으로 삽입
	2-1. 이때, 오른쪽 길이가 왼쪽보다 많으면 오른쪽 top을 왼쪽으로 옮기고 pop()
	3. 왼쪽보다 작으면 왼쪽으로 삽입
	3-1. 이때, 왼쪽 길이이랑 오른쪽이랑 2개 이상 차이나면 맨 끝을 오른쪽으로 넣기
	4. 왼쪽의 top을 반환
*/

void print_pq(priority_queue<int, vector<int>> a)
{
	for (int i = 0; i < (int)a.size(); i++)
	{
		cout << a.top() << ' ';
		a.pop();
	} cout << '\n';
}