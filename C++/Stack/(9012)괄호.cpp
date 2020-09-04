#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	deque<char> myStack;

	char bracket = '(';
	string str;
	
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> str;

		for (int i = 0; i < (int)str.size(); i++) {
			if (str[i] == bracket) myStack.push_back(bracket);
			else {
				if (myStack.empty()) myStack.push_back(str[i]);
				else if (myStack.back() == '(') myStack.pop_back();
				else myStack.push_back(str[i]);
			}
		}

		if (myStack.empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		myStack.clear();
	}

	return 0;
}