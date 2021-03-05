#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

bool compare(ll a, ll b)
{
	// �������� ����
	return a < b;
}

ll N, C;
ll dp_arr[100][100000];
ll res;

struct Thing {
	ll weight;
	ll value;
};

Thing arr[100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].weight >> arr[i].value;
	}

	for (ll w = 0; w <= C; w++)
	{
		for (ll i = 0; i < N; i++)
		{
			// �ִ� ���� �� �ִ� ���Ժ��� ���� ��
			if (w < arr[i].weight)
			{
				// ���� ���� ���ٸ�
				if (i - 1 < 0) dp_arr[i][w] = 0;
				else
				{
					dp_arr[i][w] = dp_arr[i - 1][w];
				}
			}
			else
			{
				if (i - 1 < 0) dp_arr[i][w] = arr[i].value;
				else
				{
					dp_arr[i][w] = max(dp_arr[i - 1][w], dp_arr[i - 1][w - arr[i].weight] + arr[i].value);
				}
			}
		}
	}

	cout << dp_arr[N - 1][C];
}