#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int arr[1000000];
struct pos {
	int value;
	int index = -1;
};
pos dp[1000000];

int greater_or_equal(vector<int> lis ,int left, int right, int target)
{
	// left = 0
	// right = len(lis)
	int middle;
	while (left < right)
	{
		middle = floor((double)((double)left + (double)right)/2);

		if (lis[middle] <= target) left = middle + 1;
		else right = middle;
	}

	if (right == 0) return 0;
	else if (lis[right - 1] == target) return right - 1;
	else return right;
}

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
			int index_in_lis = greater_or_equal(lis, 0, (int)lis.size(), arr[i]);
			dp[i].index = index_in_lis;
			lis[index_in_lis] = arr[i];
		}
	}
	
	// lis length print
	cout << (int)lis.size() << '\n';

	// get lis element by possible index cache
	int length = (int)lis.size();
	vector<int> answer;
	
	for (int i = N-1; i >= 0; i--)
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