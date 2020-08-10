#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int sum = 0;
	char str[100];
	
	scanf("%d", &n);
	scanf("%s", str);
	
	for (int i = 0; i < n; i++) {
		sum += (str[i] - '0');
	}

	printf("%d", sum);
}