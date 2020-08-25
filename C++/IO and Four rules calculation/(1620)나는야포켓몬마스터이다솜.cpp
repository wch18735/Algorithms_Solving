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

	// 길이 순 오름 차순으로 정렬
	sort(sorted_dogam.begin(), sorted_dogam.end());

	for (int i = 0; i < m; i++) {
		cin >> inputStr;

		if ('0' <= inputStr[0] && inputStr[0] <= '9') { // 입력이 숫자
			int indexDogam = stoi(inputStr) - 1;
			cout << dogam[indexDogam] << '\n';
		}
		else { // 입력이 string일 경우 이진탐색
			int low = 0;
			int high = n - 1;
			int mid;
			while (low <= high) {
				mid = (low + high) / 2;
				if (sorted_dogam[mid].first == inputStr) { // 내용 비교
					cout << sorted_dogam[mid].second << '\n';
					break;
				}
				else if (sorted_dogam[mid].first < inputStr) { // string 수 비교
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

// input을 받을 때, for 안에서 매번 선언하는 것은 엄청난 시간 낭비
// for 바깥에 선언하면 속도 매우 빨라짐