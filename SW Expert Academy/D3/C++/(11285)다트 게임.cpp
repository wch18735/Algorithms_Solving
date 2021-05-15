#include<iostream>

using namespace std;

void solution(int test_case);

int dart_num;
int result;
int dart_x, dart_y, dart_r;

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

void solution(int test_case)
{
	cin >> dart_num;
	
	for (int i = 0; i < dart_num; i++)
	{
		cin >> dart_x >> dart_y;

		if (dart_x == 0 and dart_y == 0)
		{
			result += 10;
			continue;
		}

		dart_r = dart_x * dart_x + dart_y * dart_y;

		for (int i = 0; i < 10; i++)
		{
			if ((20 * i) * (20 * i) < dart_r && dart_r <= (20 * (i + 1)) * (20 * (i + 1)))
			{
				result += (11 - (i + 1));
				break;
			}
		}
	}

	cout << '#' << test_case << ' ' << result << '\n';
	result = 0;
}