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
{// �������� arr

	// �̺�Ž��
	int start = 0;
	int end = (int)arr.size() - 1;
	int mid = (start + end) / 2;

	// �˻��� ���� end�� start�� ������ ��!!
	// mid + 1 or mid - 1 �� �ϱ� ������ �����ȴ�.
	while (end >= start)
	{
		// ����
		if (arr[mid] == a)
		{
			return 1;
		}
		
		// start �� end ������Ʈ
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

	// N �Է�
	cin >> N;

	// N���� ����
	vector<ll> arr(N);
	for (ll i = 0; i < N; i++) cin >> arr[i];

	// ����: ��������
	sort(arr.begin(), arr.end(), compare);

	// M �Է�
	cin >> M;

	// �Է¿� ����� num
	ll num;

	// M���� ����
	for (int i = 0; i < M; i++)
	{
		// ���� �Է�
		cin >> num;

		cout << binary_search(arr, num) << '\n';
	}

	return 0;
}