#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

// 택시 기하학에서 반지름 식
// 원점 (a,b)에 대해 r = |x-a| + |y-b|

int main() {
	float r;
	scanf("%f", &r);

	printf("%0.6f\n", PI*r*r);
	printf("%0.6f\n", 2.0*r*r);
	// 2 (x) -> 2.0 (o): 형식지정자 float 에 맞추기 위해서는 곱해지는 constant 형식은 float이어야 함
}