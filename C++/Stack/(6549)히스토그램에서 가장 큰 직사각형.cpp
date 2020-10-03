#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long longint;

int main(void)
{
	// (해당 높이가 직사각형을 이루는 최소 idx, 높이)
	stack<pair<longint, longint>> mystack;

	int n;
	longint height;
	longint ans;

	while (true)
	{
		cin >> n;
		if (n == 0) break;
		longint least_idx = 0;
		for (longint i = 0; i <= n; i++)
		{
			if (i != n) cin >> height;
			else height = -1;

			if (mystack.empty())
			{
				mystack.push({ i, height });
				ans = height;
			}
			else
			{
				if (mystack.top().second <= height)
				{
					// 주어진 높이가 현재 가장 높은 직사각형 높이보다 높은 경우
					mystack.push({ i, height });
				}
				else // 주어진 높이가 현재 가장 높은 직사각형 높이보다 낮은 경우
				{
					// while 문 안에서도 비교하는 순서가 중요하다
					while (!mystack.empty() && mystack.top().second > height) {
						ans = max((i - mystack.top().first) * mystack.top().second, ans);
						least_idx = mystack.top().first;
						mystack.pop();
					}

					mystack.push({ least_idx, height });
				}
			}
		}

		cout << ans << '\n';
		while (!mystack.empty()) mystack.pop();
	}

	return 0;
}