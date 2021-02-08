#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int ll;

ll N, k;

ll check_num(ll a)
{
	ll cnt = 0;

	for (ll i = 1; i <= N; i++)
	{
		cnt += min(a / i, N);
	}

	return cnt;
}

int main(void)
{
	cin >> N;
	cin >> k;

	ll min_ = 1;
	ll max_ = N * N;
	ll Answer = 1; // possible minimum value
	ll mid = (max_ + min_) / 2;

	while (max_ >= min_)
	{
		ll cnt = check_num(mid);
		if (cnt >= k)
		{
			max_ = mid - 1; // 언제 답을 업데이트 하는가가 매우 중요!!
			Answer = mid;
		}
		else {
			min_ = mid + 1;
		}
		mid = (max_ + min_) / 2;
	}

	cout << Answer;

	return 0;
}