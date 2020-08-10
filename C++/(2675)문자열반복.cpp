#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		int R;
		char testCase[20];
		
		scanf("%d %s", &R, testCase);
		int idx = 0;
		while (testCase[idx] != '\0') {
			for (int i = 0; i < R; i++) printf("%c", testCase[idx]);
			idx++;
		}
		printf("\n");
	}

	return 0;
}