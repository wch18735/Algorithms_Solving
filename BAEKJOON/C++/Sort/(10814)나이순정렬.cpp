#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool compare(pair<int, pair<char*, int>> a, pair<int, pair<char*, int>> b) {
	if (a.second.second == b.second.second) return a.first < b.first;
	else return a.second.second < b.second.second;
}

int main() {
	int N;
	scanf("%d", &N);

	char** name = new char*[N];
	for (int i = 0; i < N; i++) {
		name[i] = new char[101];
	}

	vector<pair<int,pair<char*, int>>> memberVec; // ���Լ���, �̸�, ����

	for (int i = 0; i < N; i++) {
		int age;
		scanf("%d %s", &age, name[i]);

		memberVec.push_back(pair<int, pair<char*, int>>(i, pair<char*, int>(name[i], age)));
	}

	sort(memberVec.begin(), memberVec.end(), compare);

	for (int i = 0; i < (int)memberVec.size(); i++) {
		printf("%d %s\n", memberVec[i].second.second, memberVec[i].second.first);
	}

	for (int i = 0; i < N; i++) {
		delete name[i];
	}
	delete name;

	return 0;
}

// ������ Ǯ�鼭 ������
// 1. pair�� ���� ���� ���̽�� �ٸ��� Template�� ����ؼ� ��������� �Ѵ�.
// 2. #include <string.h> �� new �� �̿��� �����Ҵ� ���
//	: malloc�� ����ϰ� 2���� �迭�� for ���� ����Ѵ�
// 3. delete�� ���� (������ ������ ����)