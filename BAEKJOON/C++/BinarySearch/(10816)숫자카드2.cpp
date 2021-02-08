#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	unordered_map<int, int> umap;
	
	int n;
	cin >> n;

	int input_num;

	for (int i = 0; i < n; i++)
	{
		cin >> input_num;
		umap[input_num] += 1;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> input_num;
		cout << umap[input_num] << ' ';
	}

	return 0;
}