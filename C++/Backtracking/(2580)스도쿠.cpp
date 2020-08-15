#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int end_signal = false;

bool check(pair<int, int> p, int sudoku[9][9]) {
	int x = p.first;
	int y = p.second;
	int tmp_x = (x / 3) * 3;
	int tmp_y = (y / 3) * 3;

	// row and column check
	for (int i = 0; i < 9; i++) {
		// row compare
		if (sudoku[x][y] == sudoku[x][i] && y != i) return false;
		
		// column compare
		if (sudoku[x][y] == sudoku[i][y] && x != i) return false;
	}

	// square check
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sudoku[tmp_x + i][tmp_y + j] == sudoku[x][y] && x != tmp_x + i && y != tmp_y + j)  return false;
		}
	}

	return true;
}

void backtrack(int count, int zero_num, vector<pair<int, int>> location, int sudoku[9][9]) {
	if (count == zero_num) { // Leaf node
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		end_signal = true;
		return;
	}

	// not end (start: location[count] => location[0]
	int point_x = location[count].first;
	int point_y = location[count].second;

	for (int i = 1; i <= 9; i++) {
		sudoku[point_x][point_y] = i;
		if (check(pair<int, int>(point_x, point_y), sudoku)) backtrack(count + 1, zero_num, location, sudoku);
		sudoku[point_x][point_y] = 0;

		if (end_signal) return;
	}
}

int main(void) {
	vector<pair<int, int>> location;
	int sudoku[9][9];
	int zero_num = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int num;
			scanf("%d", &num); 

			if (num == 0) {
				zero_num++;
				location.push_back(pair<int, int>(i, j));
			}

			sudoku[i][j] = num;
		}
	}
	
	backtrack(0, zero_num, location, sudoku);

	return 0;
}

/*
	이번 스도쿠 문제에서 발상을 전환하여
	1) 검색 순서를 i,j 로 접근하는 것이 아닌 vector 를 이용해 좌표 형태로 저장하고
	2) 해당 좌표에대해 가능한 1~9 값을 저장
	3) 각 경우마다 분기함 -> 이를 재귀함수를 이용한다
	4) 돌아올 때, 메모리 효율 및 오류 방지를 위해 다시 0으로 바꿔줌
	
	※ 가로, 세로, 스퀘어를 검색
*/