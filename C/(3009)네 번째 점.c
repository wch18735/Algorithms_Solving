#include <stdio.h>

int main() {
	int x[3], y[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	int x_t, y_t;

	if (x[0] == x[1]) x_t = x[2];
	else if (x[0] != x[1]) {
		if (x[0] != x[2]) x_t = x[0];
		else x_t = x[1];
	}

	if (y[0] == y[1]) y_t = y[2];
	else if (y[0] != y[1]) {
		if (y[0] != y[2]) y_t = y[0];
		else y_t = y[1];
	}

	printf("%d %d", x_t, y_t);
}