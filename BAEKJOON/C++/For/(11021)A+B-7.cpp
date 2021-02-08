#include <iostream>

using namespace std;

void solution();

int main(void)
{
	solution();
	return 0;
}

void solution()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testcase;
	cin >> testcase;

	int a, b;
	for (int i = 0; i < testcase; i++)
	{
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a + b << "\n";
	}
	
}