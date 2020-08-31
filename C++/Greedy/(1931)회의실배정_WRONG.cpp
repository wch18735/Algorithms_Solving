#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<pair<unsigned int,unsigned int>, unsigned int> a, pair<pair<unsigned int, unsigned int>, unsigned int> b) {
	return a.second < b.second;
}

int main(void) {
	int n;
	cin >> n;

	vector<pair<pair<unsigned int, unsigned int>, unsigned int>> conference;
	vector<pair<pair<unsigned int, unsigned int>, unsigned int>> entry;

	for (int i = 0; i < n; i++) {
		unsigned int start; unsigned int end;
		cin >> start >> end;

		//conference.push_back(pair<pair<int, int>, int>(pair<int, int>(start, end), end - start));
		conference.push_back({ { start,end}, end - start });
	}

	sort(conference.begin(), conference.end(), compare);

	for (int i = 0; i < n; i++) {
		int flag = 0;
		if (entry.empty()) entry.push_back(conference[i]);
		else {
			for (int j = 0; j < (int)entry.size(); j++) {
				if (!((conference[i].first.first < entry[j].first.first && conference[i].first.second < entry[j].first.first)
					|| (entry[j].first.second < conference[i].first.first && entry[j].first.second < conference[i].first.second))) {
					flag = 1;
					j = (int)entry.size();
				}
			}
			if (flag == 0) entry.push_back(conference[i]);
		}
	}

	for (int i = 0; i < entry.size(); i++) cout << entry[i].first.first << ' ' << entry[i].first.second << '\n';

	cout << entry.size();

	return 0;
}

// 회의 시간이 가장 짧은 것들을 기준으로 정렬한 후 하나씩 집어 넣으며 확인