#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

// 솔루션
void solution(int test_case);

// 배터리 차지
struct BC {
	int x;
	int y;
	int Cover;
	int Power;
};
BC bc_array[9];

// 사용자
struct Point {
	int x = 0;
	int y = 0;

	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};

// 방향 (제자리, 상, 우, 하, 좌)
const int dx[5] = {0,0,1,0,-1};
const int dy[5] = {0,-1,0,1,0};

// BC 범위 안에 A,B 판단: 내부면 True
bool check(Point p, BC bc)
{
	int D = abs(p.x - bc.x) + abs(p.y - bc.y);
	return D <= bc.Cover;
}

// 운동 방향에 따른 새로운 위치
Point next_point(Point p, int n)
{
	int nx = p.x + dx[n];
	int ny = p.y + dy[n];

	return Point(nx, ny);
}

// 이동
int A_move[101];
int B_move[101];

// BC에 포함인지 배열
bool a_in[9];
bool b_in[9];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		solution(test_case);
	}

	return 0;
}

void solution(int test_case)
{
	int M, BC_num;
	cin >> M >> BC_num;

	// A point, B point
	Point a_point = Point(1, 1);
	Point b_point = Point(10, 10);

	// A, B 이동 
	for (int i = 0; i < M; i++) cin >> A_move[i];
	for (int i = 0; i < M; i++) cin >> B_move[i];

	// 배터리 정보
	for (int i = 1; i <= BC_num; i++)
	{
		cin >> bc_array[i].x >> bc_array[i].y >> bc_array[i].Cover >> bc_array[i].Power;
	}

	int Answer = 0;

	// 이동 횟수만큼
	for (int iter = 0; iter <= M; iter++)
	{
		//cout << iter-1 << " " <<"A position: (" << a_point.x << ',' << a_point.y << ")\n";

		// 현재 이동한 상태에서 최대 값
		int sum = 0;

		// 어디 속해있는지
		for (int i = 1; i <= BC_num; i++)
		{
			// A체크
			if (check(a_point, bc_array[i]))
			{
				a_in[i] = true;
			} else a_in[i] = false;

			// B체크
			if (check(b_point, bc_array[i]))
			{
				b_in[i] = true;
			}
			else b_in[i] = false;
		}

		/*cout << "A step" << iter << ": ";
		for (int i = 1; i <= BC_num; i++) cout << a_in[i] << ' ';
		cout << '\n';
		cout << "B step" << iter << ": ";
		for (int i = 1; i <= BC_num; i++) cout << b_in[i] << ' ';
		cout << '\n';*/

		// 속한 것들 중 최대 값 (이중 for문)
		for (int i = 1; i <= BC_num; i++) // A
		{
			for (int j = 1; j <= BC_num; j++) // B
			{
				int charge_a = 0;
				int charge_b = 0;

				// 서로 다른 곳
				if (a_in[i] == true) charge_a = bc_array[i].Power;
				if (b_in[j] == true) charge_b = bc_array[j].Power;

				// 같은 곳
				if (i == j && a_in[i] == true && b_in[j] == true) charge_a = 0;

				sum = max(sum, charge_a + charge_b);
			}
		}

		//cout << "time_step: " << iter << ", sum: " << sum << '\n';

		// 해당 스텝의 최대
		Answer += sum;

		// 다음 좌표따라 이동
		a_point = next_point(a_point, A_move[iter]);
		b_point = next_point(b_point, B_move[iter]);
	}

	// 답
	cout << '#' << test_case << ' ' << Answer << '\n';
}