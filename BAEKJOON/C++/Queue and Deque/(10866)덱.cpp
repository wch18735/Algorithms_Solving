#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	deque<int> myDq;
	int n;
	int num;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		
		if (str == "push_back") {
			cin >> num;
			myDq.push_back(num);
		}
		else if (str == "push_front") {
			cin >> num;
			myDq.push_front(num);
		}
		else if (str == "front") {
			if (myDq.empty()) cout << -1 << "\n";
			else {
				cout << myDq.front() << "\n";
			}
		}
		else if (str == "back") {
			if (myDq.empty()) cout << -1 << "\n";
			else {
				cout << myDq.back() << "\n";
			}
		}
		else if (str == "size") {
			cout << (int)myDq.size() << "\n";
		}
		else if (str == "empty") {
			if (myDq.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "pop_front") {
			if (myDq.empty()) cout << -1 << "\n";
			else {
				cout << myDq.front() << "\n";
				myDq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (myDq.empty()) cout << -1 << "\n";
			else {
				cout << myDq.back() << "\n";
				myDq.pop_back();
			}
		}
	}

	return 0;
}