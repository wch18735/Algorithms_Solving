#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	int size_a = (int)a.size();
	int size_b = (int)b.size();
	int iter = min(size_a, size_b);

	for (int i = 0; i < iter; i++) {
		if (a[i] == b[i]) continue;
		else return a[i] < b[i];
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;

	string inputString;
	vector <string> no_listen;
	vector <string> no_see;
	vector <string> reduplication;

	for (int i = 0; i < n; i++) {
		cin >> inputString;
		no_listen.push_back(inputString);
	}

	sort(no_listen.begin(), no_listen.end());

	for (int i = 0; i < m; i++) {
		cin >> inputString;

		int low = 0;
		int high = n - 1;
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (no_listen[mid] == inputString) {
				reduplication.push_back(inputString);
				break;
			}
			else if (no_listen[mid] < inputString) low = mid + 1;
			else high = mid - 1;
		}
	}

	sort(reduplication.begin(), reduplication.end(), compare);
	cout << reduplication.size() << endl;
	for (int i = 0; i < reduplication.size(); i++) cout << reduplication[i] << endl;

	return 0;
}