#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// compare function 은 sort 시 실질적으로 어떤 값을 비교하는지
bool compare(int a, int b) {
	return a > b;
}

int main() {
	string input;
	int num;

	// input
	cin >> input;

	// Integer Vector
	vector<int> numVec;
	num = stoi(input);

	for (int i = 0; i < input.size(); i++) {
		numVec.push_back(num%10);
		num /= 10;
	}

	sort(numVec.begin(), numVec.end(),compare);

	for (int i = 0; i < input.size(); i++) {
		cout << numVec[i];
	}

}