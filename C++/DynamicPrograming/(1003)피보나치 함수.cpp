#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>

using namespace std;

/*
	[First Access]
	n: target fibonacci index
	chk: check whether calculated or not
	vec: if calculated, the matched value: pair<int,pair<int,int>>

	[Second Access]
	Rule of fiibonacii
*/

int main(void) {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> vec(41);
	vec[0].first = 1; vec[0].second = 0;
	vec[1].first = 0; vec[1].second = 1;

	for (int i = 2; i <= 40; i++) {
		vec[i].first = vec[i - 2].first + vec[i - 1].first;
		vec[i].second = vec[i - 2].second + vec[i - 1].second;
	}

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		printf("%d %d\n", vec[num].first, vec[num].second);
	}
}