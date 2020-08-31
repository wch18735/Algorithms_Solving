#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int, int> b){
	// ������ �ð��� ���� ������ 
	// ���� �ð��� ���� ������
	// (8,8), (7,8) -> �̷� ��� (7,8) �� ���� ��������
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(void) {
	int n;
	cin >> n;

	vector<pair<int, int>> conference;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		conference.push_back({ start, end });
	}

	// sorting �� �̿���
	// LEFT | start ---- end | RIGHT ��
	// LEFT ������ ������� �ʰ� ���� ���踦 ������ �� ����
	// Greedy �ϰ� ������ ���� ȸ�ǽð��� RIGHT���� ���Եȴٸ� �߰��ϰ�
	// bound�� RIGHT ������ �ű�
	sort(conference.begin(), conference.end(), compare);

	int bound = 0;
	int Answer = 0;

	for (int i = 0; i < n; i++) {
		if (bound <= conference[i].second && bound <= conference[i].first) {
			Answer++;
			bound = conference[i].second;
		}
	}

	cout << Answer;

	return 0;
}