#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
	deque<int> myQ;

	cin >> n >> k;
	int move = k;

	for (int i = 1; i <= n; i++) myQ.push_back(i);
	
	cout << '<';
	while (myQ.size() != 1) {
		if (k < (int)myQ.size()) {
			rotate(myQ.begin(), myQ.begin() + (k - 1), myQ.end());
			cout << myQ.front() << ", ";
			myQ.pop_front();
		}
		else if (k == (int)myQ.size()) {
			cout << myQ.back() << ", ";
			myQ.pop_back();
		} 
		else{
			move = k % (int)myQ.size();
			rotate(myQ.begin(), myQ.begin() + (k - 1), myQ.end());
			cout << myQ.front() << ", ";
			myQ.pop_front();
		}
	}

	cout << myQ[0] << '>';

	return 0;
}