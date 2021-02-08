#include<iostream>
#include<algorithm>

using namespace std;

void solution();

// 랜선 개수, 필요한 랜선 개수
int K, N;

// 배열
typedef unsigned long long int new_int;
new_int arr[10000];

// 최대값
#define MAXVALUE 2<<31 - 1

int main(void)
{

	solution();

	return 0;
}

void solution()
{
	// K 랑 N 입력
	cin >> K >> N;

	// 숫자 입력 (동시에 최소값 찾음)
	new_int min_value = MAXVALUE;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];

		min_value = max(min_value, arr[i]);
	}

	// 이진탐색
	new_int start = 1;
	new_int end = min_value;
	new_int mid = (start + end) / 2;
	while ( end >= start)
	{
		new_int cnt = 0;

		for (int i = 0; i < K; i++) cnt += arr[i] / mid;

		if (cnt < N) end = mid - 1;
		else start = mid + 1;

		mid = (start + end) / 2;
	}

	cout << mid;
}