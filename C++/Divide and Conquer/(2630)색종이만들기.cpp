#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<vector<int>> Map, int n, int x, int y) {
	for (int i = x; i <x+n; i++) {
		for (int j = y; j <y+n; j++) cout << Map[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';

	return;
}

int white_cnt = 0;
int blue_cnt = 0;

void check(int x, int y, int n, vector<vector<int>> Map) {
	int white_fill = 1; // 1: Complete
	int blue_fill = 1;// 1: Complete

	/*printVec(Map, n, x, y);*/

	if (Map[x][y] == 0) // Èò »ö check 
	{
		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				if (Map[i][j] != 0) {
					white_fill = 0;
					break;
				}
			}
		}
	}
	else if(Map[x][y] == 1) // ÆÄ¶õ »ö check
	{
		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				if (Map[i][j] != 1) {
					blue_fill = 0;
					break;
				}
			}
		}
	}

	if (Map[x][y] == 0) // Èò »ö check 
	{
		if (white_fill == 1) {
			white_cnt++;
			return;
		}
		else {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					check(x+(n>>1)*i, y+(n>>1)*j, n>>1, Map);
				}
			}
		}
	}
	else if (Map[x][y] == 1) // ÆÄ¶õ »ö check
	{
		if (blue_fill == 1) 
		{
			blue_cnt++;
			return;
		}
		else {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					check(x + (n>>1) * i, y + (n>>1) * j, n>>1, Map);
				}
			}
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	int num;
	vector<vector<int>> Map;
	vector<int> row;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			row.push_back(num);
		}
		Map.push_back(row);
		row.clear();
	}

	check(0, 0, n, Map);

	cout << white_cnt << '\n';
	cout << blue_cnt << '\n';

	return 0;
}