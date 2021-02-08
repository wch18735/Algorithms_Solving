#include <iostream>

using namespace std;

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = n; i >= 1; i--)
	{
		cout << i << '\n';
	}

	return 0;
}