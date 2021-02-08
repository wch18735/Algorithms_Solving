#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	vector<string> dogam;
	vector<pair<string, int>> sorted_dogam;
	string name;
	string inputStr;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		dogam.push_back(name);
		sorted_dogam.push_back({ name, i + 1 });
	}

	// ���� �� ���� �������� ����
	sort(sorted_dogam.begin(), sorted_dogam.end());

	for (int i = 0; i < m; i++) {
		cin >> inputStr;

		if ('0' <= inputStr[0] && inputStr[0] <= '9') { // �Է��� ����
			int indexDogam = stoi(inputStr) - 1;
			cout << dogam[indexDogam] << '\n';
		}
		else { // �Է��� string�� ��� ����Ž��
			int low = 0;
			int high = n - 1;
			int mid;
			while (low <= high) {
				mid = (low + high) / 2;
				if (sorted_dogam[mid].first == inputStr) { // ���� ��
					cout << sorted_dogam[mid].second << '\n';
					break;
				}
				else if (sorted_dogam[mid].first < inputStr) { // string �� ��
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			}
		}
	}

	return 0;
}

// input�� ���� ��, for �ȿ��� �Ź� �����ϴ� ���� ��û�� �ð� ����
// for �ٱ��� �����ϸ� �ӵ� �ſ� ������