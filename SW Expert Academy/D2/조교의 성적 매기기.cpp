#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void solution(int test_case);

typedef struct {
	int index;
	int total;
} student;

student arr[100];
char score[10][3] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
int N, idx;

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		solution(test_case);
	}
	return 0;
}

bool compare(student a, student b)
{
	return a.total > b.total;
}

void solution(int test_case)
{
	cin >> N >> idx;
	int ratio = N / 10;

	int md, hi, hw;

	for (int i = 1; i <= N; i++)
	{
		cin >> md >> hi >> hw;
		arr[i-1].index = i;
		arr[i-1].total = (md * 35) + (hi * 45) + (hw * 20);
	}

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++)
	{
		if (idx == arr[i].index)
		{
			cout << '#' << test_case << ' ' << score[i / ratio] << '\n';
			break;
		}
	}

	return;
}