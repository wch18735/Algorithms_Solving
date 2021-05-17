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
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (cities[i].s == cities[j].s) continue;

			// distance between i and j
			int dist_x = cities[i].x - cities[j].x;
			int dist_y = cities[i].y - cities[j].y;
			distance = dist_x*dist_x + dist_y*dist_y;
			
			// threaten each other
			double i_to_j = cities[i].s / distance;
			double j_to_i = cities[j].s / distance;

			// check if j -> i threaten
			if (cities[i].s < j_to_i)
			{
					// threaten as much power as cities[i].threaten
					if (cities[i].threaten == j_to_i)
					{
						cities[i].state = 'D';
						cities[i].follow = -1;
					}
					else if (cities[i].threaten < j_to_i)
					{
						// threaten newly
						cities[i].state = 'T';
						cities[i].follow = j;
						cities[i].threaten = j_to_i;
					}
			}
			
			if (cities[j].s < i_to_j)
			{
				if (cities[j].threaten == i_to_j)
				{
					cities[j].state = 'D';
					cities[j].follow = -1;
				}
				else if (cities[j].threaten < i_to_j)
				{
					// threaten newly
					cities[j].state = 'T';
					cities[j].follow = i;
					cities[j].threaten = i_to_j;
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

	// re-initialize
	for (int i = 1; i <= N; i++)
	{
		cities[i].follow = -1;
		cities[i].state = 'K';
		cities[i].threaten = 0.0;
	}
}