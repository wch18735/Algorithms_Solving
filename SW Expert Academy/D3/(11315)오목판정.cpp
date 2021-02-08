#include<iostream>

using namespace std;

void solution(int testcase);

int MAP[21][21];
int N;

int main(void)
{
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= testcase; i++)
	{
		solution(i);
	}

	return 0;
}

void input()
{
	char temp;
	// Input
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			if (temp == 'o') MAP[i][j] = 1;
			else if(temp == '.') MAP[i][j] = 0;
		}
	}
}

bool check_cross(int x, int y)
{
	// init
	int px, py, num;

	// right-up
	px = x; py = y; num = 0;
	while (MAP[px][py] == 1 && (1 <= x && x <= N) && (1 <= y && y <= N))
	{
		num += 1;
		px -= 1;
		py += 1;
	}

	// left-down
	px = x; py = y;
	while (MAP[px][py] == 1 && (1 <= x && x <= N) && (1 <= y && y <= N))
	{
		num += 1;
		px += 1;
		py -= 1;
	}

	// check cross
	if (num - 1 >= 5)
	{
		return true;
	}
	
	// left-up
	px = x; py = y; num = 0;
	while (MAP[px][py] == 1 && (1 <= x && x <= N) && (1 <= y && y <= N))
	{
		num += 1;
		px -= 1;
		py -= 1;
	}

	// rigth-down
	px = x; py = y;
	while (MAP[px][py] == 1 && (1 <= x && x <= N) && (1 <= y && y <= N))
	{
		num += 1;
		px += 1;
		py += 1;
	}

	// check cross
	if (num - 1 >= 5)
	{
		return true;
	}

	// return false
	return false;
}

bool check_line(int x, int y)
{
	// init
	int px, py, num;

	// right
	px = x; py = y; num = 0;
	while (MAP[px][py] == 1 && (1 <= x && x <= N) && (1 <= y && y <= N))
	{
		num += 1;
		py += 1;
	}

	// left
	px = x; py = y;
	while (MAP[px][py] == 1 && (1 <= x && x <= N) && (1 <= y && y <= N))
	{
		num += 1;
		py -= 1;
	}

	// check cross
	if (num - 1 >= 5)
	{
		return true;
	}

	// up
	px = x; py = y; num = 0;
	while (MAP[px][py] == 1 && (1 <= x && x <= N) && (1 <= y && y <= N))
	{
		num += 1;
		px -= 1;
	}

	// down
	px = x; py = y;
	while (MAP[px][py] == 1 && (1 <= x && x <= N) && (1 <= y && y <= N))
	{
		num += 1;
		px += 1;
	}

	// check cross
	if (num - 1 >= 5)
	{
		return true;
	}

	return false;
}

bool check(int x, int y)
{
	return (check_cross(x, y) || check_line(x, y));
}

void draw()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << MAP[i][j];
		}
		cout << '\n';
	}

	cout << '\n';
}

void init_()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			MAP[i][j] = 0;
		}
	}
}

void solution(int testcase)
{
	// N ют╥б
	cin >> N;

	// Input
	input();

	// check
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if ((MAP[i][j] == 1) && check(i, j))
			{
				cout << "#" << testcase << " YES\n";
				init_();
				return;
			}
		}
	}

	cout << "#" << testcase << " NO\n";
	init_();
	return;
}