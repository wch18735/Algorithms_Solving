#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) {
	string str;
	deque<char> myStack;

	while (true)
	{
		getline(cin, str);

		if ((int)str.size() == 1 && str[0] == '.') break;

		for (int i = 0; i < (int)str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') myStack.push_back(str[i]);
			else if (str[i] == ')' || str[i] == ']') {
				if (myStack.empty()) myStack.push_back(str[i]);
				else if (str[i] == ')' && myStack.back() == '(') myStack.pop_back();
				else if (str[i] == ']' && myStack.back() == '[') myStack.pop_back();
				else myStack.push_back(str[i]);
			}
		}

		//for (int i = 0; i < (int)myStack.size(); i++) cout << myStack[i] << '\n';

		if (myStack.empty()) cout << "yes\n";
		else cout << "no\n";

		myStack.clear();
	}

	return 0;
}