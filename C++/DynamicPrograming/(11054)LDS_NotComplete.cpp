#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void DequePrint(deque<int> LIS) {
	for (deque<int>::iterator it = LIS.begin(); it != LIS.end(); it++) {
		cout << *it << ' ';
	} cout << endl;
}

int main(void) {
	int n;
	cin >> n;

	deque<int> LIS;
	deque<int> LDS;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (LIS.empty() && LDS.empty()) {
			LIS.push_back(num);
			LDS.push_back(num);
		}
		else {
			if (LIS.back() < num) LIS.push_back(num);
			else {
				auto LowerBoundPointer = lower_bound(LIS.begin(), LIS.end(), num);
				*LowerBoundPointer = num;
			}

			if (LDS.front() > num) LDS.push_front(num);
			else {
				auto LowerBoundPointer = lower_bound(LDS.begin(), LDS.end(), num);
				if (LowerBoundPointer == LDS.end()) { // num 이 최대이면 맨 뒤에 넣고
					LDS.pop_back();
					LDS.push_back(num);
				}
				else *LowerBoundPointer = num;	// 아니면 중간 자리에 넣고
			}
		}

		//DequePrint(LDS);
	}

	cout << (int)LIS.size() + (int)LDS.size() - 1;

	return 0;
}