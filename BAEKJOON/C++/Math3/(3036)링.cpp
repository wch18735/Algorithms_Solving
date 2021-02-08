#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main(void) {
	int n;
	cin >> n;

	int root;
	int num;
	int GCD;

	for (int i = 0; i < n; i++) {
		if (i == 0) cin >> root;
		else {
			cin >> num;

			GCD = gcd(root, num);

			if (GCD != 1) cout << root / GCD << '/' << num / GCD << '\n';
			else cout << root << '/' << num << '\n';
		}
	}

	return 0;
}