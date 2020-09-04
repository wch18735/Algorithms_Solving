#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	deque<int> myQ;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		myQ.push_back(i + 1);
	}

	while (myQ.size() != 1) {
		myQ.pop_front();
		myQ.push_back(myQ.front());
		myQ.pop_front();
	}

	cout << myQ[0];

	return 0;
}