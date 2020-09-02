#include <iostream>
#include <cmath>
#include <deque>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	deque<int> numArr(n+1,1);
	deque<int> primeArr;

	numArr[0] = 0;
	numArr[1] = 0;

	int root = (int)sqrt(n);

	for (int i = 2; i <= root; i++) {
		if (numArr[i] == 0) continue;

		for (int j = i + i; j <= n; j = j + i) {
			numArr[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (numArr[i] == 1) primeArr.push_back(i);
	}

	while (n != 1 && !primeArr.empty())
	{
		int primeNum = primeArr.front();
		primeArr.pop_front();

		while (n % primeNum == 0) {
			cout << primeNum << '\n';
			n = n / primeNum;
		}
	}

	return 0;
}