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

		// size 세는 법
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

// 문제 풀면서 느낀 점
// 1. string.h 는 C에서 char* 를 처리하기 위함
// 2. string은 string C++에서 class 명
// 3. strcmp 와 strncmp 를 사용하면 char* 비교 쉬움
// 4. cout, cin 는 느리기 때문에 되도록 나중에