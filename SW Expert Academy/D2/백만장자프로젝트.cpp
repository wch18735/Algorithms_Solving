#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
	int idx;
	int price;
} info;
typedef long long ll;

void solution(int test_case);
bool compare(info a, info b)
{
	return a.price > b.price;
}


info day[1000000];
int price[1000000];

int main(void)
{
	int test_case;
	cin >> test_case;
	for (int i = 1; i <= test_case; i++)
	{
		solution(i);
	}
}

void solution(int test_case)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> day[i].price;
		price[i] = day[i].price;
		day[i].idx = i;
	}

	sort(day, day + N, compare);

	int from = 0, end = 0;
	ll res = 0;
	for (int i = 0; i < N; i++)
	{
		if (from > day[i].idx) continue;
		for (int j = from; j < day[i].idx; j++)
		{
			res += (day[i].price - price[j]);
		}
		from = day[i].idx + 1;
	}

	cout << '#' << test_case << ' ' << res << '\n';
}