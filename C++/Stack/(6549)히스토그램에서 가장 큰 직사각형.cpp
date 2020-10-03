#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long longint;

int main(void)
{
	// (�ش� ���̰� ���簢���� �̷�� �ּ� idx, ����)
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
					// �־��� ���̰� ���� ���� ���� ���簢�� ���̺��� ���� ���
					mystack.push({ i, height });
				}
				else // �־��� ���̰� ���� ���� ���� ���簢�� ���̺��� ���� ���
				{
					// while �� �ȿ����� ���ϴ� ������ �߿��ϴ�
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