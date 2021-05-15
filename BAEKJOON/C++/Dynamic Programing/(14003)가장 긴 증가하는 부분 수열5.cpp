#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[1000000];
struct pos {
	int value;
	int index = -1;
};
pos dp[1000000];

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// input sequence
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i].value = arr[i];
	}

	// lis dp and init cache
	vector<int> lis;
	lis.push_back(arr[0]);
	dp[0].index = 0;
	int index_in_lis;
	for (int i = 1; i < N; i++)
	{
		if (lis.back() == arr[i]) continue;
		if (lis.back() < arr[i])
		{
			lis.push_back(arr[i]);
			dp[i].index = (int)lis.size() - 1;
		}
		else
		{
			index_in_lis = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			dp[i].index = index_in_lis;
			lis[index_in_lis] = arr[i];
		}
	}

	// lis length print
	cout << (int)lis.size() << '\n';

	// get lis element by possible index cache
	int length = (int)lis.size();
	vector<int> answer;

	for (int i = N - 1; i >= 0; i--)
	{
		if (dp[i].index + 1 == length)
		{
			answer.push_back(dp[i].value);
			length--;
		}

		if (length == 0) break;
	}

	// lis element print
	for (int i = (int)answer.size() - 1; i >= 0; i--) cout << answer[i] << ' ';

	return 0;
}