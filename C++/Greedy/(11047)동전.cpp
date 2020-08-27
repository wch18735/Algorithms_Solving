#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	unsigned int n, k;
	cin >> n >> k;

	int cnt = 0;
	unsigned int inputCoin;
	deque<unsigned int> coin;

	for (int i = 0; i < n; i++) {
		cin >> inputCoin;
		coin.push_front(inputCoin);
	}

	while (!coin.empty()) {
		if (coin.front() > k) {
			coin.pop_front();
		}
		else {
			k = k - coin.front();
			cnt++;

			if (k == 0) break;
		}
	}

	cout << cnt;

	return 0;
}