#include <stdio.h>

int main() {
	int scale[8];

	scanf("%d %d %d %d %d %d %d %d", &scale[0], &scale[1], &scale[2], &scale[3], &scale[4], &scale[5], &scale[6], &scale[7]);
	
	int ascFlag = 1;
	int desFlag = 1;

	for (int i = 0; i < 7; i++) {
		if (scale[i] - scale[i + 1] != -1) ascFlag = 0;
		if (scale[i] - scale[i + 1] != 1) desFlag = 0;
	}

	if (ascFlag == 1) printf("ascending");
	else if (desFlag == 1) printf("descending");
	else printf("mixed");

	return 0;
}