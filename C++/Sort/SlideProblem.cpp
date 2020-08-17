/*
	Input�� Ư�� identifier�� ���� �����̵尡 Ŭ�� �� �������
	�� �� õ �� ���� ����
	�̵��� ��� �����Ͽ� ���� ���� Ŭ���� 100���� ����

	100�� ������ �����ϴٰ� 100���� �Ѿ�� ���� �ΰ�
	Search�� ���� Store�� �д�
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define MAXNUM 100000

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	srand(1);
	int num[MAXNUM];
	vector < pair<int, int>> store;

	// Input
	for (int i = 0; i < MAXNUM; i++) {
		num[i] = rand() % 1000;
	}

	// initialize
	store.push_back(pair<int, int>(num[0], 1));

	// Put in
	for (int i = 1; i < MAXNUM; i++) {
		int idx = (int)store.size();
		for (int j = 0; j < (int)store.size(); j++) {
			if (store[j].first == num[i]) {
				idx = j;
			}
		}
		if (idx != (int)store.size()) store[idx].second += 1;
		else store.push_back(pair<int, int>(num[i], 1));
	}

	sort(store.begin(), store.end(), compare);

	for (int i = 0; i < store.size(); i++) {
		printf("%d:\t%d ȸ\n", store[i].first, store[i].second);
	}

	return 0;


}