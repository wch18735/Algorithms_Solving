#include<stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		char score[80] = {'\0',};
		scanf("%s", score);
		int j = 0;
		int count = 0;
		int sum = 0;

		while (true) {
			if (score[j] == 'O') {
				count++;
			}
			else if (score[j] == 'X') {
				sum += count * (count + 1) / 2;
				count = 0;
			}
			else if (score[j] != '\0') {
				sum += count * (count + 1) / 2;
				break;
			}

			j++;
		}

		printf("%d\n", sum);
	}
}