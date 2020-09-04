#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	string str;
	int num;

	cin >> n;

	deque<int> myQ;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			myQ.push_back(num);
		}
		else if (str == "size") cout << (int)myQ.size() << '\n';
		else if (str == "empty") {
			if (myQ.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str == "front") {
			if (myQ.empty()) cout << -1 << '\n';
			else cout << myQ.front() << '\n';
		}
		else if (str == "back") {
			if (myQ.empty()) cout << -1 << '\n';
			else cout << myQ.back() << '\n';
		}
		else if (str == "pop") {
			if (myQ.empty()) cout << -1 << '\n';
			else {
				cout << myQ.front() << '\n';
				myQ.pop_front();
			}
		}
	}

	return 0;
}