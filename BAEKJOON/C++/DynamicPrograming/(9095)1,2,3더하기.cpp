#include<iostream>

using namespace std;

// function
void solution();
void input();
void dfs(int num);
void init();

// variable
int TARGET;
int CNT = 0;
const int ARR[3] = { 1, 2, 3 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		solution();
	}
}

void input()
{
	cin >> TARGET;
}

void dfs(int num) 
{
	for (int i = 0; i < 3; i++)
	{
		num += ARR[i];
		if (num == TARGET)
		{
			CNT += 1;
			return;
		}
		else if (num > TARGET)
		{
			num -= ARR[i];
		}
		else
		{
			dfs(num);
			num -= ARR[i];
		}
	}
}

void init()
{
	CNT = 0;
}

void solution()
{
	// 입력
	input();

	// 1, 2, 3 이 있는 배열
	// DFS
	dfs(0);

	// 출력
	cout << CNT << '\n';

	// 전역변수 초기화
	init();
}