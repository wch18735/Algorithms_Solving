#include <iostream>

using namespace std;

int main(void) {
	int A, B, C;
	
	cin >> A >> B >> C;
	printf("%d\n%d\n%d\n%d", (A + B) % C, ((A % C) + (B % C)) % C, (A * B) % C, ((A % C) * (B % C)) % C);

	return 0;
}