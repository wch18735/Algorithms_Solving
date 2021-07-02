#include<iostream>

using namespace std;

int numList[1000];
int answer;
int N;
int mul_val;

bool check_pair(int val)
{
	// multiplied value < 10
	if (val < 10) return true;

	int comp = val;
	while (comp / 10 != 0)
	{
		comp /= 10;
	}
	int res = comp;

	int multiplier = 10;
	while (comp < val)
	{
		if (res == val) return true;
		comp += 1;
		if (comp == multiplier) break;
		res *= multiplier;
		res += comp;
	}
	return false;
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> numList[i];
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				mul_val = numList[i] * numList[j];
				
				// check bigger than answer
				if (mul_val <= answer) continue;
				if(check_pair(mul_val)) answer = mul_val;
			}
		}

		if (answer == 0) cout << "#" << test_case << " " << -1 << '\n';
		else cout << "#" << test_case << " " << answer << '\n';

		answer = 0;
	}

	return 0;
}