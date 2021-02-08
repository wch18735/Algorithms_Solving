#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) 
{
	int T;
	string oper;
	string str;
	deque<int> myDq;
	int num;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		// state % 2 == 0 : left
		// state % 2 == 1 : right
		int state = 0;
		int error_state = 0;

		cin >> oper;
		cin >> num;
		cin >> str;

		size_t previous = 1;
		size_t current = str.find(',');

		if (num != 0) {
			while (current != string::npos)
			{
				string substring = str.substr(previous, current - previous);
				myDq.push_back(stoi(substring));
				previous = current + 1;
				current = str.find(',', previous);
			}
			myDq.push_back(stoi(str.substr(previous, current - 1)));
			// string 잘라서 집어 넣기
		}

		for (int i = 0; i < (int)oper.size(); i++)
		{
			if (oper[i] == 'R')
			{
				state = (state + 1) % 2;
			}
			else if (oper[i] == 'D')
			{
				if (state % 2 == 0)
				{ // 왼쪽에서 보는 것
					if (myDq.empty()) error_state = 1;
					else myDq.pop_front();
				}
				else if(state % 2 == 1)
				{ // 오른쪽에서 보는 것
					if (myDq.empty()) error_state = 1;
					else myDq.pop_back();
				}
			}
		}

		if (error_state == 1) cout << "error\n";
		else if (state % 2 == 0) {
			cout << '[';
			for (int i = 0; i < (int)myDq.size(); i++) {
				if (i < (int)myDq.size() - 1) cout << myDq[i] << ',';
				else cout << myDq[i];
			} cout << ']' << '\n';
		}
		else if (state % 2 == 1) {
			cout << '[';
			for (int i = (int)myDq.size() - 1; i >= 0; i--) {
				if (i > 0) cout << myDq[i] << ',';
				else cout << myDq[i];
			} cout << ']' << '\n';
		}

		myDq.clear();
	}

	return 0;
}