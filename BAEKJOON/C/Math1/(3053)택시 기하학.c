#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

// �ý� �����п��� ������ ��
// ���� (a,b)�� ���� r = |x-a| + |y-b|

int main() {
	float r;
	scanf("%f", &r);

	printf("%0.6f\n", PI*r*r);
	printf("%0.6f\n", 2.0*r*r);
	// 2 (x) -> 2.0 (o): ���������� float �� ���߱� ���ؼ��� �������� constant ������ float�̾�� ��
}