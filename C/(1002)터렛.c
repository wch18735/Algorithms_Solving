#include <stdio.h>
#include <math.h>

int main() {
	int T;
	scanf("%d",&T);

	for (int i = 0; i < T; i++) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		float dist1 = sqrt((x1 - x2)*(x1 - x2) + (y1-y2)*(y1 - y2));
		float dist2 = r1 + r2;
		float min_r = fmin(r1, r2);
		float max_r = fmax(r1, r2);

		// dist1: 두 원점 사이 거리
		// dist2: 반지름의 합
		// 교점 개수 => 삼각형 형성 조건으로 판별

		if (x1 == x2 && y1 == y2 && r1 == r2) { // 중심 일치
			printf("%d\n", -1);
		}
		else {
			// 교점 0
			if (dist1 > dist2 || min_r + dist1 < max_r) printf("%d\n", 0);

			// 교점 1
			if (dist1 == dist2 || min_r + dist1 == max_r) printf("%d\n", 1);

			// 교점 2		
			if (dist1 < dist2 && min_r + dist1 > max_r) printf("%d\n", 2);
		}
	}
	return 0;
}