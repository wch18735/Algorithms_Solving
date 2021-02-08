#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;


/* ============ �ڷ��� ���� ================= */
struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {} // ������

	bool operator < (const Point& v) const // ��ü sort ���� ����
	{
		if (y == v.y) return x < v.x;
		else return y < v.y;
	}
};

/* ============ �Լ� ============= */
int dist(Point a, Point b) // �� ����Ʈ�� �־����� �Ÿ� ������ ��ȯ�ϴ� �Լ�
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void solution(); // ���� Ǫ�� �ַ��
bool compare(Point a, Point b) // sort ����
{
	// x ��ǥ �������� ����
	return a.x < b.x;
}

int main(void)
{
	solution();

	return 0;
}

void solution()
{
	int n;
	cin >> n;

	// �Է� ����
	vector<Point> pointArray(n);
	
	// �Է� ����
	for (int i = 0; i < n; i++) cin >> pointArray[i].x >> pointArray[i].y;

	// pointArray�� x�࿡ ���� ����
	sort(pointArray.begin(), pointArray.end(), compare);

	// Answer �� �ʱ� �Ÿ��� ����
	int Answer = dist(pointArray[0], pointArray[1]);

	// ���� Point ���� x�� �������� �ּҰŸ� d_min, y�� ���Ʒ��� d_min �Ÿ� ���� ����
	// P0, P1 �� �ĺ��� ���� (���� ������ �ڵ� X, ����, �˻�, ���� ��� lonN)
	set<Point> inpoint;
	inpoint.insert({ pointArray[0],pointArray[1] });

	// ���ο� P_n �� ���Ͽ� x�� ���� d_min ���ο� �ִ��� �˻縦 ������ index
	// pointArray �� x�� �������� ���ĵǾ� ������
	// d_min �� ����ؼ� �۾����� ������ start ���� ������ Ž������ �ʾƵ� �ȴ�
	int start = 0;

	// ����ȭ Loop
	for (int i = 2; i < n; i++)
	{
		// �˻� ���� Point
		Point P_n = pointArray[i];

		// P_n �������� x �ຸ�� �� �͵� �ĺ����� ����
		while (start < i)
		{
			// pointArray[start] ����
			auto P_cad = pointArray[start];

			// P_n �� ���� ���� (����)
			int x_dis = P_n.x - P_cad.x;

			// Answer (���� �ּ� �Ÿ�)�� �Ÿ� �� (���� ������ start ���� ������ ���)
			if (x_dis * x_dis <= Answer) break;
			else
			{
				inpoint.erase(P_cad);
				start += 1;
			}
		}
			
		// �ּҰŸ� d_min ����
		int d_min = (int)sqrt(Answer) + 1;

		// ���� Lower ��踦 ��Ÿ��  Point ���� (���� �ϴ�)
		Point lower_point = Point(-100000, P_n.y - d_min);

		// ���� Highier ��踦 ��Ÿ�� Point ���� (���� ���)
		Point upper_point = Point(100000, P_n.y + d_min);

		// x �� ���� ���� ���� �ִ� �͵� �� y �� ������ �����ϴ� �ĺ��� ����
		auto lower_iterator = inpoint.lower_bound(lower_point);
		auto upper_iterator = inpoint.upper_bound(upper_point);

		// �ش� �ĺ����� �̿��� Answer ������Ʈ
		for (auto it = lower_iterator; it != upper_iterator; it++)
		{
			// P_n �� ���� ���� ���� �Ÿ� ����
			int distance = dist(P_n, *it);

			// �� �Ÿ��� Answer ���� ������ Update
			if (distance < Answer) Answer = distance;
		}

		// ������ ������ �ĺ��� P_n �߰�
		inpoint.insert(P_n);
	}
	// �ּ� �Ÿ� ���
	cout << Answer;

	return;
}