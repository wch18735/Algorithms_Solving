#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isEqual(pair<string, int> a, string str) {
	return a.first == str;
}

int main(void) {

	int T;
	cin >> T;

	int n;
	string cloth_name, cloth_kind;
	vector<pair<string, int>> table;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;

		int Answer = 1;

		for (int i = 0; i < n; i++) {
			cin >> cloth_name >> cloth_kind;
			if (i == 0) table.push_back({ cloth_kind,1 });
			else {
				// check if string is in or not 
				int noneFlag = 0;

				// checking for statement
				for (int j = 0; j < table.size(); j++) {
					if (table[j].first == cloth_kind) {
						table[j].second += 1;
						noneFlag = 1;
					}
				}

				// add cloth_kind if there are no matching kinds
				if (noneFlag == 0) table.push_back({ cloth_kind, 1 });
			}
		}

		for (int i = 0; i < table.size(); i++) {
			Answer *= (table[i].second + 1);
		}

		cout << Answer - 1 << '\n';

		table.clear();
	}

	return 0;
}

/*
	�� ����!!
	a,b,c,d,e ... z
	Answer = (a+1)(b+1)*...*(z+1) - 1;

	������ n ���� ���� (���� == ���� ��)�� ���� ���տ��� �� ��, �� ��, �� ���� �÷����� n ������ ���� ��.
	�� ���ҵ�� ���� �� �ִ� ���� ��
*/