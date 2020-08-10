#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool compare(pair<char*, int> a, pair<char*, int> b) {
	if (a.second == b.second) {
		int i = 0;
		while (true) {
			if (a.first[i] != b.first[i]) return a.first[i] < b.first[i];
			i++;
		}
	}
	else return a.second < b.second;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<pair<char*,int>> charVec; // (string, size)

	char str[20001][51] = { '\0' };

	for (int i = 0; i < N; i++) {
		scanf("%s", str[i]);

		int count = 0;

		// size ���� ��
		while (str[i][count] != '\0') {
			count++;
		}
		
		int sameFlag = 0;
		for (int j = 0; j < (int)charVec.size(); j++) {
			if (!(strcmp(charVec[j].first, str[i]))) {
				sameFlag = 1;
			}
		}
		if (sameFlag) continue;
		charVec.push_back(pair<char*, int>(str[i], count));
	}

	sort(charVec.begin(), charVec.end(), compare);
	/*charVec.erase(unique(charVec.begin(), charVec.end()), charVec.end());*/

	for (int i = 0; i < (int)charVec.size(); i++) {
			printf("%s\n", charVec[i].first);
	}

	return 0;
}

// ���� Ǯ�鼭 ���� ��
// 1. string.h �� C���� char* �� ó���ϱ� ����
// 2. string�� string C++���� class ��
// 3. strcmp �� strncmp �� ����ϸ� char* �� ����
// 4. cout, cin �� ������ ������ �ǵ��� ���߿�