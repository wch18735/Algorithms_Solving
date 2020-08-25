#include <iostream>

using namespace std;

int CNT = 0;
int finish_flag = 0;

// x,y 기준 좌표
// target_x, target_y: 목표
// size: 가장 작은 사각형일 때 Leaf
void find_position(int x, int y,int target_x, int target_y, int size) {
	// 다른 재귀 함수가 찾으면
	if (finish_flag) return;
	
	// Leaf
	if (size == 2) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (x + i == target_x && y + j == target_y) {
					finish_flag = 1;
					return;
				}
				CNT++;
			}
		}
		// 답이 없을 때
		return;
	}

	// Not Leaf
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			find_position( x + (size >> 1) * i, y + (size >> 1) * j, target_x, target_y, (size >> 1));
		}
	}
}

int main(void) {
	int n, r, c;

	cin >> n >> r >> c;

	find_position(0, 0, r, c, (1 << n));

	cout << CNT;

	return 0;
}