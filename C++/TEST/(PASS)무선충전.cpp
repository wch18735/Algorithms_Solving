#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

// �ַ��
void solution(int test_case);

// ���͸� ����
struct BC {
	int x;
	int y;
	int Cover;
	int Power;
};
BC bc_array[9];

// �����
struct Point {
	int x = 0;
	int y = 0;

	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};

// ���� (���ڸ�, ��, ��, ��, ��)
const int dx[5] = {0,0,1,0,-1};
const int dy[5] = {0,-1,0,1,0};

// BC ���� �ȿ� A,B �Ǵ�: ���θ� True
bool check(Point p, BC bc)
{
	int D = abs(p.x - bc.x) + abs(p.y - bc.y);
	return D <= bc.Cover;
}

// � ���⿡ ���� ���ο� ��ġ
Point next_point(Point p, int n)
{
	int nx = p.x + dx[n];
	int ny = p.y + dy[n];

	return Point(nx, ny);
}

// �̵�
int A_move[101];
int B_move[101];

// BC�� �������� �迭
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

	// A, B �̵� 
	for (int i = 0; i < M; i++) cin >> A_move[i];
	for (int i = 0; i < M; i++) cin >> B_move[i];

	// ���͸� ����
	for (int i = 1; i <= BC_num; i++)
	{
		cin >> bc_array[i].x >> bc_array[i].y >> bc_array[i].Cover >> bc_array[i].Power;
	}

	int Answer = 0;

	// �̵� Ƚ����ŭ
	for (int iter = 0; iter <= M; iter++)
	{
		//cout << iter-1 << " " <<"A position: (" << a_point.x << ',' << a_point.y << ")\n";

		// ���� �̵��� ���¿��� �ִ� ��
		int sum = 0;

		// ��� �����ִ���
		for (int i = 1; i <= BC_num; i++)
		{
			// Aüũ
			if (check(a_point, bc_array[i]))
			{
				a_in[i] = true;
			} else a_in[i] = false;

			// Büũ
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

		// ���� �͵� �� �ִ� �� (���� for��)
		for (int i = 1; i <= BC_num; i++) // A
		{
			for (int j = 1; j <= BC_num; j++) // B
			{
				int charge_a = 0;
				int charge_b = 0;

				// ���� �ٸ� ��
				if (a_in[i] == true) charge_a = bc_array[i].Power;
				if (b_in[j] == true) charge_b = bc_array[j].Power;

				// ���� ��
				if (i == j && a_in[i] == true && b_in[j] == true) charge_a = 0;

				sum = max(sum, charge_a + charge_b);
			}
		}

		//cout << "time_step: " << iter << ", sum: " << sum << '\n';

		// �ش� ������ �ִ�
		Answer += sum;

		// ���� ��ǥ���� �̵�
		a_point = next_point(a_point, A_move[iter]);
		b_point = next_point(b_point, B_move[iter]);
	}

	// ��
	cout << '#' << test_case << ' ' << Answer << '\n';
}