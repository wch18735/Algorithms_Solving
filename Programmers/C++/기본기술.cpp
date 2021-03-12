#include<iostream>
#include<algorithm>	// 기본!! (sorting, permutation, combination)
#include<memory.h>	// memset 위함
#include<random>
#include<set>		// 집합 Set 사용
#include<map>		// 맵 (Key, Value) 사용
#include<vector>	// 벡터 (List) 사용
#include<deque>		// 덱 (Deque) 사용
#include<queue>		// 큐 (Queue) 사용
#include<string>	// 스트링 편집 (String)

using namespace std;

void memset_practice();
void sort_practice();
void set_practice();
void map_practice();
void vector_practice();
void permutation_practice();
void string_practice();

int main(void)
{
	// memset_practice();
	// sort_practice();
	// set_practice();
	// map_practice();
	// vector_practice();
	// permutation_practice();
	// string_practice();
	return 0;
}

/* 메모리 세팅 연습*/
void memset_practice()
{
	int arr[10][20];
	memset(arr, -1, sizeof(arr));
	
	// memset 이용해 2d 배열 초기화 (0 or -1 만 가능)
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++) cout << arr[i][j] << ' ';
		cout << '\n';
	}

	// 다른 값으로 초기화
	fill(&arr[0][0], &arr[9][20], 3);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++) cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

/* 정렬 연습 */
struct point {
	int x;
	int y;
};

bool compare(point a, point b)
{
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

void sort_practice()
{
	// 난수 발생기
	random_device rd;
	mt19937 gen(rd()); // 메르센 트위스터 방식
	uniform_int_distribution<int> dist(0, 99);
	// normal_distribution<double> dist(평균, 표준편차) 가능

	// 1차원 배열 난수 입력
	cout << "초기 배열 상태\n";
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = dist(gen);
		cout << arr[i] << ' ';
	} cout << '\n';

	// Greater 우선 => 내림차순 정렬
	cout << "내림차순 정렬\n";
	sort(arr, arr + 10, greater<int>());
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	} cout << '\n';

	// Less 우선 => 오름차순 정렬
	cout << "오름차순 정렬\n";
	sort(arr, arr + 10, less<int>());
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	} cout << '\n';

	// 좌표 난수입력
	cout << "정렬 전\n";
	point ARR[10];
	for (int i = 0; i < 10; i++)
	{
		int x = dist(gen);
		int y = dist(gen);

		cout << x << ' ' << y << '\n';
		ARR[i].x = x; ARR[i].y = y;
	}cout << "정렬 후\n";

	// X좌표가 우선적으로 작고, 같은 상태라면 Y좌표가 작은 순서로 정렬
	sort(&ARR[0], &ARR[10], compare);
	for (int i = 0; i < 10; i++)
	{
		cout << ARR[i].x << ' ' << ARR[i].y << '\n';
	}
}

/* Set 사용 연습 (집합) */
void set_practice()
{
	// 선언
	set<int, greater<int>> example_set; // greater struct 를 넣는 것

	// 원소 삽입
	example_set.insert(5);
	example_set.insert(4);
	example_set.insert(3);
	example_set.insert(6);
	example_set.insert(2);

	// 중복되는 값 삽입
	example_set.insert(5);
	example_set.insert(2);

	// 값 확인
	cout << "집합 원소 확인\n";
	for (auto iter = example_set.begin(); iter != example_set.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << '\n';

	// 5라는 값이 있는지 확인한 후 지우기
	cout << "원소 5 확인하고 지우기\n";
	if (example_set.find(5) != example_set.end()) example_set.erase(5);
	for (auto& elem : example_set) cout << elem << ' ';
	cout << '\n';

	// 원소 개수 반환하기
	cout << "원소 6 개수 반환하기\n";
	cout << example_set.count(6) << '\n';
}

/* Map 사용 연습 (Map, Dictionary) */
void map_practice()
{
	// MAP 선언 (Key, Value)
	map<int, int> m;

	// MAP에 쌍 삽입 (3, 5), (6, 12), (11, 2), (10, 5)
	pair<int, int> p(10, 5);

	m.insert(p);
	m[3] = 5;
	m[6] = 12;
	m[11] = 2;

	// 출력
	cout << "초기 Key-Value 쌍\n";
	for (auto& m_p : m) cout << m_p.first << ' ' << m_p.second << '\n';
	cout << '\n';

	// Key 값이 4인 경우 찾기 (없음)
	if (m.find(4) == m.end()) cout << "Key 값이 없습니다\n";

	// Key 값이 3인 값 Value를 10으로 수정
	if (m.find(3) != m.end()) m.at(3) = 10;
	cout << "<3, 5> 를 <3, 10> 으로 수정\n";
	for (auto& m_p : m) cout << m_p.first << ' ' << m_p.second << '\n';
	cout << '\n';

	// 키 값이 10인 것 지우기
	cout << "키 값이 10인 경우 지우기\n";
	if (m.find(10) != m.end()) m.erase(10);
	for (auto& m_p : m) cout << m_p.first << ' ' << m_p.second << '\n';
}

/* Vector 사용 연습 (Vector, List) */
void vector_practice()
{
	// 벡터 선언
	// vector<int> arr(10, 5) : 10개를 5로 채움
	vector<int> arr;

	// 벡터 삽입
	for (int i = 0; i < 10; i++) arr.push_back(i);
	
	// 벡터 출력
	for (int i = 0; i < int(arr.size()); i++) cout << arr[i] << ' ';
}

/* Deque 사용 연습 */
/* Queue 사용 연습 */
/* Permutation, Combination 사용 연습 */
void permutation_practice()
{
	int example_arr[5] = { 5, 2, 4, 3, 1 };

	// 정렬되어있지 않으면 모든 경우를 탐색하지 못 함
	// 따라서 사용 전 정렬 필수
	// 또한 next_permutation 인자로 greater, less 등을 활용할 수 있음
	do {
		for (int i = 0; i < 5; i++) cout << example_arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(example_arr, example_arr + 5));

	// Combination
	// Combination(4, 2)는 1 2개, 0 2개 인 배열의 Permutation 값에서 1의 위치한 Index만을 가져오면 된다
	cout << '\n';
	int arr[5];
	fill(arr, arr + 2, 0); fill(arr + 2, arr + 5, 1);
	do {
		for (int i = 0; i < 5; i++)
		{
			if (arr[i] == 1) cout << example_arr[i] << ' ';
		} cout << '\n';
	} while (next_permutation(arr, arr + 5));
}

/* String 사용 연습 */
void string_practice()
{
	string str = "Hello Wolrd Everybody!!";

	// substr(시작 위치, 위치로 부터 몇 개)
	cout << str.substr(0, 4) << '\n'; // [0, 4)
	
	// strip 구현
	int from = 0;
	int to = 0;
	while (to != -1)
	{
		to = str.find(' ', from);
		cout << str.substr(from, to - from) << '\n';
		from = to + 1;
	}

	// string 더하기
	string str1 = "Won";
	string str2 = "Cheol";
	cout << str1 + str2 << '\n';

	// "some word" in string
	string target1 = "body";
	string target2 = "Body";
	cout << str.find(target1) << '\n';
	if (str.find(target2) == string::npos) cout << "찾는 단어 없음!!\n";

	// compare (비교 연산자)
	target1 = "body";
	target2 = "body";
	cout << target1 << " == " << target2 << ':' << bool(target1 == target2) << '\n';		// 연산자는 ASCII 코드 순서로 비교!!
	cout << target1 << " compare " << target2 << ':' << target1.compare(target2) << '\n';	// 0이면 같음, -1이면 앞선 것, 1이면 뒤로

	// append(str, 시작, 끝), append(몇 개, 추가 할 char)
	char delimeter = '!';
	target1.append(5, delimeter);
	cout << target1 << '\n';

	// replace
	string target_str = "This is test string!! It's test.";
	string subtext = "a real";
	from = 0;
	cout << target_str << '\n';
	while (true)
	{
		from = target_str.find("test");
		if (from == string::npos) break;
		target_str.replace(from, 4, subtext);
	}
	cout << target_str << '\n';
}
