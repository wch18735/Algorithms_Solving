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

	vector<pair<int,pair<char*, int>>> memberVec; // 가입순서, 이름, 나이

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

// 문제를 풀면서 느낀점
// 1. pair를 넣을 때는 파이썬과 다르게 Template을 계속해서 지정해줘야 한다.
// 2. #include <string.h> 의 new 를 이용한 동적할당 방법
//	: malloc과 비슷하게 2차원 배열은 for 문을 사용한다
// 3. delete는 역순 (조립은 분해의 역순)