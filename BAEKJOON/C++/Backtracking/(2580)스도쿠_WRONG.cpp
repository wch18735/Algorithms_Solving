#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void check_row(int x, int y, int sdocu[9][9]);

void check_col(int x, int y, int sdocu[9][9]);

void check_square(int x, int y, int sdocu[9][9]);

int main(void) {
	int sdocu[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &sdocu[i][j]);
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sdocu[i][j] == 0) check_row(i, j, sdocu);
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", sdocu[i][j]);
		}
		printf("\n");
	}
}

void check_row(int x, int y, int sdocu[9][9]) {
	int sum = 0;
	int count = 0;

	for (int i = 0; i < 9; i++) {
		if (sdocu[x][i] == 0) count++;
		if (count > 1) {
			check_col(x, y, sdocu);
			return;
		}
	}

	for (int i = 0; i < 9; i++) {
		sum += sdocu[x][i];
	}

	sdocu[x][y] = 45 - sum;
}

void check_col(int x, int y, int sdocu[9][9]) {
	int sum = 0;
	int count = 0;

	for (int i = 0; i < 9; i++) {
		if (sdocu[i][y] == 0) count++;
		if (count > 1) {
			check_square(x, y, sdocu);
			return;
		}
	}

	for (int i = 0; i < 9; i++) {
		sum += sdocu[i][y];
	}
	
	sdocu[x][y] = 45 - sum;
}

void check_square(int x, int y, int sdocu[9][9]) {
	int tmp_x = (x / 3) * 3;
	int tmp_y = (y / 3) * 3;

	int sum = 0;
	int count = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sdocu[tmp_x + i][tmp_y + j] == 0) {
				count++;
			}
			if (count > 1) {
				return;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum += sdocu[tmp_x+i][tmp_y+j];
		}
	}

	sdocu[x][y] = 45 - sum;
}