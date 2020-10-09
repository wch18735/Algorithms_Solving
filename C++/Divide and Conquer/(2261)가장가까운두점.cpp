#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;


/* ============ 자료형 지정 ================= */
struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {} // 생성자

	bool operator < (const Point& v) const // 자체 sort 기준 정함
	{
		if (y == v.y) return x < v.x;
		else return y < v.y;
	}
};

/* ============ 함수 ============= */
int dist(Point a, Point b) // 두 포인트가 주어지면 거리 제곱을 반환하는 함수
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void solution(); // 문제 푸는 솔루션
bool compare(Point a, Point b) // sort 기준
{
	// x 좌표 오름차순 정렬
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

	// 입력 벡터
	vector<Point> pointArray(n);
	
	// 입력 받음
	for (int i = 0; i < n; i++) cin >> pointArray[i].x >> pointArray[i].y;

	// pointArray를 x축에 따라 정렬
	sort(pointArray.begin(), pointArray.end(), compare);

	// Answer 를 초기 거리로 설정
	int Answer = dist(pointArray[0], pointArray[1]);

	// 현재 Point 기준 x축 좌측으로 최소거리 d_min, y축 위아래로 d_min 거리 내부 점들
	// P0, P1 을 후보에 저장 (같은 점들은 자동 X, 삽입, 검색, 삭제 모두 lonN)
	set<Point> inpoint;
	inpoint.insert({ pointArray[0],pointArray[1] });

	// 새로운 P_n 에 대하여 x축 기준 d_min 내부에 있는지 검사를 시작할 index
	// pointArray 가 x축 기준으로 정렬되어 있으며
	// d_min 은 계속해서 작아지기 때문에 start 보다 이전은 탐색하지 않아도 된다
	int start = 0;

	// 최적화 Loop
	for (int i = 2; i < n; i++)
	{
		// 검색 기준 Point
		Point P_n = pointArray[i];

		// P_n 좌측으로 x 축보다 먼 것들 후보에서 제외
		while (start < i)
		{
			// pointArray[start] 선택
			auto P_cad = pointArray[start];

			// P_n 과 차이 구함 (제곱)
			int x_dis = P_n.x - P_cad.x;

			// Answer (현재 최소 거리)와 거리 비교 (작을 때까지 start 지점 옆으로 당김)
			if (x_dis * x_dis <= Answer) break;
			else
			{
				inpoint.erase(P_cad);
				start += 1;
			}
		}
			
		// 최소거리 d_min 구함
		int d_min = (int)sqrt(Answer) + 1;

		// 가장 Lower 경계를 나타낼  Point 선언 (좌측 하단)
		Point lower_point = Point(-100000, P_n.y - d_min);

		// 가장 Highier 경계를 나타낼 Point 선언 (우측 상단)
		Point upper_point = Point(100000, P_n.y + d_min);

		// x 축 기준 범위 내에 있는 것들 중 y 축 범위도 만족하는 후보들 구함
		auto lower_iterator = inpoint.lower_bound(lower_point);
		auto upper_iterator = inpoint.upper_bound(upper_point);

		// 해당 후보들을 이용해 Answer 업데이트
		for (auto it = lower_iterator; it != upper_iterator; it++)
		{
			// P_n 과 내부 점들 사이 거리 구함
			int distance = dist(P_n, *it);

			// 이 거리가 Answer 보다 가까우면 Update
			if (distance < Answer) Answer = distance;
		}

		// 끝으로 가능한 후보에 P_n 추가
		inpoint.insert(P_n);
	}
	// 최소 거리 출력
	cout << Answer;

	return;
}