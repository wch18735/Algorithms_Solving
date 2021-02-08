#include<iostream>
#include<map>
#include<vector>

using namespace std;

// �ַ��
void solution(int test_case);

// Type
typedef pair<double, double> Point;
typedef int Direction;
typedef int Energy;
typedef pair<Direction, Energy> Atom_info;
typedef pair<Point, Atom_info> Atom;

// �Լ�
Point change_position(Point p, Direction d);

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
	// Atom ����
	int A_num;
	cin >> A_num;

	// ���� ��
	multimap<Point, Atom_info> atom_map;

	// �ӽ� Point
	Point point;

	// �Խ� ���� ���� (Direction, Energy)
	Atom_info ainfo;

	// ���� ����
	for (int i = 0; i < A_num; i++)
	{
		// �Է�
		cin >> point.first >> point.second >> ainfo.first >> ainfo.second;

		// ���� �ʿ� ����
		atom_map.insert({ point, ainfo });
	}

	// ��ǥ ��
	map<Point, int> pos_map;

	// ����Ǵ� ������ �ѷ�
	Energy energy = 0;

	// Ȯ��
	for (int i = 0; i < 4010; i++)
	{
		multimap<Point, Atom_info> temp_map;

		// �� ���� ���� ��ǥ �� ����
		for (auto it = atom_map.begin(); it != atom_map.end();)
		{
			// ����
			Point p = it->first;
			Atom_info info = it->second;

			// ���� ������Ʈ
			p = change_position(p, info.first);

			// ���� Ű �� ���� (���� �� ���ο� �� ����)
			atom_map.erase(it++);

			// �ӽ� �����Ϳ� ����
			temp_map.insert({ p, info });

			// pos_map �� ��ǥ ���� �߰�
			auto pos = pos_map.find(p);
			if (pos == pos_map.end())
			{
				pos_map.insert({ p,1 });
			}
			else 
			{
				pos->second = pos->second + 1;
			}
		}

		// �� ������ �ٲ� (atom_map�� �ٽ� ������Ʈ �Ǿ���)
		swap(atom_map, temp_map);

		// pos_map ���� ���� 1�� �Ѵ� �͵� ��� �����ϸ鼭 energy�� ����
		for (auto it = pos_map.begin(); it != pos_map.end(); it++)
		{
			if(it->second == 1) continue;
			else
			{
				Point target_p = it->first;
				/*cout << "position size: " << it->second << '\n';
				cout << "atom map size: " << atom_map.size() << '\n';*/

				for (auto it = atom_map.lower_bound(target_p); it != atom_map.upper_bound(target_p); it++)
				{
					// ������ ����
					energy += it->second.second;
				}

				atom_map.erase(atom_map.lower_bound(target_p), atom_map.upper_bound(target_p));
			}
		}

		// ������ �ϳ��̸� break
		if ((int)atom_map.size() <= 1) break;

		// ��ġ ���� ���� �ʱ�ȭ 
		pos_map.clear();
	}

	cout << '#'<< test_case << ' ' << energy << '\n';
}

Point change_position(Point p, Direction d)
{
	if (d == 0) //��
	{
		return Point(p.first, double(p.second + 0.5));
	}
	else if (d == 1) // ��
	{
		return Point(p.first, p.second - 0.5);
	}
	else if (d == 2) // ��
	{
		return Point(p.first - 0.5, p.second);
	}
	else // ��
	{
		return Point(double(p.first + 0.5), p.second);
	}
}

// ��� ��
// unordered_map, unordered_set -> �ڷᱸ���� hash�� ����Ͽ� O(1) �� �����ϵ��� ���� set �� map
// find() �� �̿��� ã�� �� �ִ�. ���� �����ϸ� m.find() != m.end() �̴�.
// auto it = m.find() �� it->second �� �̿��� ���� �� �ִ�.
// iterator �� erase �ϸ鼭 ������Ű���� m.erase(it++) �� ���
// iterator �� 2 ���� �ǳ� �ٷ��� next(it,2) �Ǵ� advance(it, 2) ���
// swap(pointer, pointer) �� ���� �� ���� ó��