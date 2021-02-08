#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void solution();

int main(void)
{
	solution();

	return 0;
}

void solution()
{
	int n;
	cin >> n;

	vector<int> lis;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (lis.empty()) lis.push_back(num);
		else
		{
			if (lis.back() < num) lis.push_back(num);
			else
			{
				auto p = lower_bound(lis.begin(), lis.end(), num);
				*p = num;
			}
		}
	}
	/*for (auto i = lis.begin(); i != lis.end(); i++) cout << *i << ' ';
	cout << '\n';*/
	cout << (int)lis.size();
}
