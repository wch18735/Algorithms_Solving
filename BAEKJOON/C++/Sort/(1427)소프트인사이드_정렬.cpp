#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// compare function �� sort �� ���������� � ���� ���ϴ���
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