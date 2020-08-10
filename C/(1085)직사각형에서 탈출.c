#include <stdio.h>
#include <math.h>

// 주어진 예시가 한 가지 경우

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int horizen = abs(w - x);
	int verti = abs(h - y);

	int distance[4] = { x,y,horizen,verti };
	int temp = distance[0];

	// Shortest path != min(horizen, verti)
	// check other state: x, y are closer to end
	for (int i = 0; i < 4; i++) {
		if (temp > distance[i]) temp = distance[i];
	}

	printf("%d", temp);
}