#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

void printPrime(int n) {
	vector<int> numArr(n + 1, 1);
	numArr[0] = 0;
	numArr[1] = 0;

	int root = (int)sqrt(n);

	for (int i = 2; i <= root; i++) {
		if (numArr[i] == 0) continue;

		for (int j = i + i; j <= n; j += i) {
			numArr[j] = 0;
		}
	}

	for (int i = 0; i <= n; i++) {
		if (numArr[i] == 1) cout << i << ' ';
	}

	return;
}

void printDivisor(int n) {
	vector<int> tmp;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			tmp.push_back(i);
			tmp.push_back(n / i);
		}
	}
	tmp.push_back(n);

	sort(tmp.begin(), tmp.end(), less<int>());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for (int i = 0; i < (int)tmp.size(); i++) cout << tmp[i] << ' ';

	return;
}

int main(void) {
	int n;
	cin >> n;

	vector<int> numArr(n);
	int sub;
	int GCD;

	for (int i = 0; i < n; i++) cin >> numArr[i];

	sort(numArr.begin(), numArr.end(), less<int>());

	GCD = numArr[1] - numArr[0];
	for (int i = 2; i < n; i++) {
		GCD = gcd(GCD, numArr[i] - numArr[i - 1]);
	}
	
	printDivisor(GCD);

	return 0;
}

/*
	1. 최대공약수: 유클리드 호제법
	2. 약수: i*i <= n 까지 구하며 나눠지는 i와 n/i를 추가 
*/