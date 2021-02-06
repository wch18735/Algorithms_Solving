#include<iostream>
#define DIVIDOR 10007

using namespace std;

// Function
void solution();
void dfs(int num);

// Variable
const int BRICK[2] = { 1, 2 };
int WIDTH;
int CNT = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solution();
}

void dfs(int num)
{
	for (int i = 0; i < 2; i++)
	{
		num += BRICK[i];
		if (num == WIDTH)
		{
			CNT += 1;
			CNT %= DIVIDOR;
			return;
		}
		else if (num < WIDTH)
		{
			dfs(num);
			num -= BRICK[i];
		}
		else
		{
			num -= BRICK[i];
		}
	}
}

void input()
{
	cin >> WIDTH;
}

void solution()
{
	// input
	input();

	// dfs
	dfs(0);

	// answer
	cout << CNT;
}