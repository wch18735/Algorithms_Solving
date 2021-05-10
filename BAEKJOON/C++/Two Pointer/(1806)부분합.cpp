#include <iostream>
#include <algorithm>

using namespace std;

#define MAXNUM 100001 

int arr[100000];
int answer = MAXNUM;

bool compare(int a, int b)
{
	return a < b;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S, num;

	// 입력
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;
	}

	// two pointer
	int start_pointer = 0;
	int end_pointer = 0;
	int partial_sum = arr[start_pointer];

	// answer
	while (end_pointer < N)
	{	
		// 부분 합 구하기
		if (partial_sum < S)
		{
			end_pointer += 1;
			partial_sum += arr[end_pointer];
		}
		else
		{
			answer = min(answer, end_pointer - start_pointer + 1);
			partial_sum -= arr[start_pointer];
			start_pointer += 1;
		}
	}

	if (answer == MAXNUM) cout << 0;
	else cout << answer;

	return 0;
}