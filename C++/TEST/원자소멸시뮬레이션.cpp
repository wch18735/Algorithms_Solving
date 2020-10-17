#include<iostream>
#include<map>
#include<vector>

using namespace std;

// 솔루션
void solution(int test_case);

// Type
typedef pair<double, double> Point;
typedef int Direction;
typedef int Energy;
typedef pair<Direction, Energy> Atom_info;
typedef pair<Point, Atom_info> Atom;

// 함수
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
	// Atom 개수
	int A_num;
	cin >> A_num;

	// 원자 맵
	multimap<Point, Atom_info> atom_map;

	// 임시 Point
	Point point;

	// 입시 원자 정보 (Direction, Energy)
	Atom_info ainfo;

	// 원자 삽입
	for (int i = 0; i < A_num; i++)
	{
		// 입력
		cin >> point.first >> point.second >> ainfo.first >> ainfo.second;

		// 원자 맵에 삽입
		atom_map.insert({ point, ainfo });
	}

	// 좌표 맵
	map<Point, int> pos_map;

	// 방출되는 에너지 총량
	Energy energy = 0;

	// 확인
	for (int i = 0; i < 4010; i++)
	{
		multimap<Point, Atom_info> temp_map;

		// 각 맵을 돌며 좌표 값 변경
		for (auto it = atom_map.begin(); it != atom_map.end();)
		{
			// 뽑음
			Point p = it->first;
			Atom_info info = it->second;

			// 새로 업데이트
			p = change_position(p, info.first);

			// 기존 키 값 변경 (삭제 후 새로운 값 삽입)
			atom_map.erase(it++);

			// 임시 포인터에 저장
			temp_map.insert({ p, info });

			// pos_map 에 좌표 값만 추가
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

		// 두 포인터 바꿈 (atom_map이 다시 업데이트 되었음)
		swap(atom_map, temp_map);

		// pos_map 에서 값이 1이 넘는 것들 모두 삭제하면서 energy에 대입
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
					// 에너지 더함
					energy += it->second.second;
				}

				atom_map.erase(atom_map.lower_bound(target_p), atom_map.upper_bound(target_p));
			}
		}

		// 개수가 하나이면 break
		if ((int)atom_map.size() <= 1) break;

		// 위치 맵을 비우며 초기화 
		pos_map.clear();
	}

	cout << '#'<< test_case << ' ' << energy << '\n';
}

Point change_position(Point p, Direction d)
{
	if (d == 0) //상
	{
		return Point(p.first, double(p.second + 0.5));
	}
	else if (d == 1) // 하
	{
		return Point(p.first, p.second - 0.5);
	}
	else if (d == 2) // 좌
	{
		return Point(p.first - 0.5, p.second);
	}
	else // 우
	{
		return Point(double(p.first + 0.5), p.second);
	}
}

// 배운 것
// unordered_map, unordered_set -> 자료구조상 hash를 사용하여 O(1) 에 동작하도록 만든 set 과 map
// find() 를 이용해 찾을 수 있다. 만약 존재하면 m.find() != m.end() 이다.
// auto it = m.find() 후 it->second 를 이용해 얻을 수 있다.
// iterator 를 erase 하면서 증가시키려면 m.erase(it++) 를 사용
// iterator 를 2 개씩 건너 뛰려면 next(it,2) 또는 advance(it, 2) 사용
// swap(pointer, pointer) 를 통해 한 번에 처리