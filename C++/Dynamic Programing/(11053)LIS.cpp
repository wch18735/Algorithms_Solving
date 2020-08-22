#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void VectorPrint(vector<int> LIS) {
	for (vector<int>::iterator it = LIS.begin(); it != LIS.end(); it++) {
		cout << *it << ' ';
	} cout << endl;
}

vector<int> LIS;
int numArr[1001];
int n;

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> numArr[i];
		if (LIS.empty()) LIS.push_back(numArr[i]);
		else {
			if (LIS.back() < numArr[i]) LIS.push_back(numArr[i]);
			else {
				auto LowerBoundPointer = lower_bound(LIS.begin(), LIS.end(), numArr[i]);
				*LowerBoundPointer = numArr[i];
			}
		}

		//VectorPrint(LIS);
	}

	cout << (int)LIS.size();

	return 0;
}