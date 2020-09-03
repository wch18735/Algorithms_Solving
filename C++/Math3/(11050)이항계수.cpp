#include <iostream>
#include <vector>

using namespace std;

int total = 0;

void binary_coefficient(int n, int k, int previous, int cnt,vector<int> chk){
	// Leaf
	if (cnt == k) {
		total += 1;
		return;
	}

	// Not Leaf
	for (int i = previous; i < n; i++) {
		// visit check
		if (chk[i] == 1) continue;

		// not visit
		chk[i] = 1;
		binary_coefficient(n, k, i + 1, cnt + 1, chk);
		chk[i] = 0;
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;

	vector<int> chk(n,0);

	binary_coefficient(n, k, 0, 0, chk);

	cout << total;

	return 0;
}