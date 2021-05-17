#include<iostream>

using namespace std;

void solution(int test_case);
int N;

struct city_info {
	int x;
	int y;
	double s;
	char state = 'K';
	int follow = -1;
	double threaten;
};

city_info cities[1001];

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		solution(test_case);
	}

	return 0;
}

void input()
{
	cin >> N;
	int x, y, s;

	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y >> s;
		cities[i].x = x;
		cities[i].y = y;
		cities[i].s = s;
	}
}

void solution(int test_case)
{
	// input
	input();

	// calculate relative with brute force
	int distance;
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (cities[i].s == cities[j].s) continue;

			// distance between i and j
			distance = (cities[i].x - cities[j].x) * (cities[i].x - cities[j].x) + (cities[i].y - cities[j].y) * (cities[i].y - cities[j].y);

			// check if threatend
			if (cities[i].s < cities[j].s / distance)
			{
				if (cities[i].state != 'T')
				{
					cities[i].state = 'T';
					cities[i].follow = j;
					cities[i].threaten = cities[j].s / distance;
				}
				else
				{
					// already threaten
					if (cities[i].threaten > cities[j].s / distance) continue;
					else if (cities[i].threaten == cities[j].s / distance && cities[i].state == 'T')
					{
						cities[i].state = 'D';
						cities[i].follow = -1;
					}
					else if (cities[i].threaten < cities[j].s / distance)
					{
						// threaten newly
						cities[i].state = 'T';
						cities[i].follow = j;
						cities[i].threaten = cities[j].s / distance;
					}
				}
			}
			else if (cities[j].s < cities[i].s / distance)
			{
				if (cities[j].state != 'T')
				{
					cities[j].state = 'T';
					cities[j].follow = i;
					cities[j].threaten = cities[i].s / distance;
				}
				else
				{
					// already threaten
					if (cities[j].threaten > cities[i].s / distance) continue;
					else if (cities[j].threaten == cities[i].s / distance && cities[j].state == 'T')
					{
						cities[j].state = 'D';
						cities[j].follow = -1;
					}
					else if (cities[j].threaten < cities[i].s / distance)
					{
						// threaten newly
						cities[j].state = 'T';
						cities[j].follow = i;
						cities[j].threaten = cities[i].s / distance;
					}
				}
			}
		}
	}

	int follow_node = 0;
	cout << '#' << test_case << ' ';
	for (int i = 1; i <= N; i++)
	{
		if (cities[i].state != 'T') cout << cities[i].state << ' ';
		else
		{
			follow_node = i;
			while (cities[follow_node].state == 'T') follow_node = cities[follow_node].follow;
			cout << follow_node << ' ';
		}
	}
	cout << '\n';
}