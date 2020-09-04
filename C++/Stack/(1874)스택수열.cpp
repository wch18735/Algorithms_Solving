#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int num;
	int flag = 0;

	deque<char> myStr;
	deque<int> myRight;
	deque<int> myLeft;

	for (int i = 0; i < n; i++) {
		myRight.push_back(i+1);
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		while (true) {
			if (myRight.empty()) {
				if (num != myLeft.back()) {
					flag = 1;
					break;
				}
				else {
					myLeft.pop_back();
					myStr.push_back('-');
					break;
				}
			}
			else {
				if (myLeft.empty()) {
					myLeft.push_back(myRight.front());
					myRight.pop_front();
					myStr.push_back('+');
				}
				else {
					if (myLeft.back() != num) {
						myLeft.push_back(myRight.front());
						myRight.pop_front();
						myStr.push_back('+');
					}
					else {
						myLeft.pop_back();
						myStr.push_back('-');
						break;
					}
				}
			}
		}
	}

	if (flag == 1) cout << "NO";
	else {
		for (int i = 0; i < (int)myStr.size(); i++) cout << myStr[i] << '\n';
	}

	return 0;
}