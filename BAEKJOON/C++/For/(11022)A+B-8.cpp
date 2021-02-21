#include <iostream>

using namespace std;

int main(int argc, char* argv)
{
	int test_case, a, b;
	cin >> test_case;

	for (int i = 1; i <= test_case; i++)
	{
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << '\n';
	}

	return 0;
}