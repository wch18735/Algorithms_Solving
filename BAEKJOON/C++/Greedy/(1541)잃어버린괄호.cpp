#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main(void) {
	string expression;
	string integerStr;
	deque<int> numArr;
	deque<char> charArr;
	int tmp; char tmp_ch;
	int left = 0;
	int sub_flag = 0;

	cin >> expression;

	// 문자열 처리
	for (int i = 0; i < (int)expression.size(); i++) {
		if ('0' <= expression[i] && expression[i] <= '9') {
			integerStr.push_back(expression[i]);
			/*cout << integerStr << '\n';*/
		}
		else if (expression[i] == '-' || expression[i] == '+') {
			charArr.push_back(expression[i]);
			tmp = stoi(integerStr);
			numArr.push_back(tmp);
			integerStr.clear();
		}

		if (i == (int)expression.size() -1  && !integerStr.empty()) {
			tmp = stoi(integerStr);
			numArr.push_back(tmp);
		}
	}

	// initialize
	left = numArr.front();
	numArr.pop_front();

	while (!charArr.empty()) {
		tmp = numArr.front();
		numArr.pop_front();

		tmp_ch = charArr.front();
		charArr.pop_front();

		if (tmp_ch == '-') sub_flag = 1;

		if (sub_flag == 0) left += tmp;
		else left -= tmp;
	}

	cout << left;

	return 0;
}