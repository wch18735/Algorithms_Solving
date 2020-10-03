#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int binary_search(vector<int> numArr, int num)
{
	// 오름차순으로 정렬된 배열

	int start = 0;
	int end = (int)numArr.size() - 1;
	int mid = (start + end) / 2;
	int cnt = 0;
	while (!(end < start))
	{
		if (numArr[mid] == num)
		{
			cnt += 1;
			// check left
			for (int i = mid-1; i >= 0; i--)
			{
				if (numArr[i] == num) cnt += 1;
				else break;
			}
			// check right
			for (int i = mid + 1; i < (int)numArr.size(); i++)
			{
				if (numArr[i] == num) cnt += 1;
				else break;
			}

			return cnt;
		}

		else if (numArr[mid] < num)
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
		else if (numArr[mid] > num)
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
	}

	return cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> numArr(N);

	for (int i = 0; i < N; i++) cin >> numArr[i];

	sort(numArr.begin(), numArr.end(), compare);

	int M;

	cin >> M;
	int num;

	for (int i = 0; i < M; i++)
	{
		cin >> num;

		cout << binary_search(numArr, num) << ' ';
	}

	return 0;
}