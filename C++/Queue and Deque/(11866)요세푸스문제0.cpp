#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
	deque<int> myQ;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) myQ.push_back(i);

	cout << '<';
	while (!myQ.empty()) {
		for (int i = 0; i < k - 1; i++) {
			myQ.push_back(myQ.front());
			myQ.pop_front();
		}
		cout << myQ.front();
		myQ.pop_front();

		if (!myQ.empty()) cout << ", ";
	}
	cout << '>';

	return 0;
}