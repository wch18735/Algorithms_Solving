#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	int k;
	int num;
	long int sum = 0;
	deque<int> book;

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> num;

		if (num > 0) {
			sum += num;
			book.push_back(num);
		}
		else {
			sum -= book.back();
			book.pop_back();
		}
	}

	cout << sum;

	return 0;
}