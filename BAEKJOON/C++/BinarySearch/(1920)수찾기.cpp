#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
 
bool compare(ll a, ll b)
{
	return a < b;
}

int binary_search(vector<ll>& arr, ll a)
{// 오름차순 arr

	// 이분탐색
	int start = 0;
	int end = (int)arr.size() - 1;
	int mid = (start + end) / 2;

	// 검색의 끝은 end와 start이 역전될 때!!
	// mid + 1 or mid - 1 을 하기 때문에 역전된다.
	while (end >= start)
	{
		// 존재
		if (arr[mid] == a)
		{
			return 1;
		}
		
		// start 와 end 업데이트
		else if (arr[mid] < a)
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
		else if (a < arr[mid])
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
	}

	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// N, M
	int N, M;

	// N 입력
	cin >> N;

	// N개의 정수
	vector<ll> arr(N);
	for (ll i = 0; i < N; i++) cin >> arr[i];

	// 정렬: 오름차순
	sort(arr.begin(), arr.end(), compare);

	// M 입력
	cin >> M;

	// 입력에 사용할 num
	ll num;

	// M개의 정수
	for (int i = 0; i < M; i++)
	{
		// 정수 입력
		cin >> num;

		cout << binary_search(arr, num) << '\n';
	}

	return 0;
}