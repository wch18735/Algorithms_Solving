#include<iostream>
#include<algorithm>	// �⺻!! (sorting, permutation, combination)
#include<memory.h>	// memset ����
#include<random>
#include<set>		// ���� Set ���
#include<map>		// �� (Key, Value) ���
#include<vector>	// ���� (List) ���
#include<deque>		// �� (Deque) ���
#include<queue>		// ť (Queue) ���
#include<string>	// ��Ʈ�� ���� (String)

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

/* �޸� ���� ����*/
void memset_practice()
{
	int arr[10][20];
	memset(arr, -1, sizeof(arr));
	
	// memset �̿��� 2d �迭 �ʱ�ȭ (0 or -1 �� ����)
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++) cout << arr[i][j] << ' ';
		cout << '\n';
	}

	// �ٸ� ������ �ʱ�ȭ
	fill(&arr[0][0], &arr[9][20], 3);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++) cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

/* ���� ���� */
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
	// ���� �߻���
	random_device rd;
	mt19937 gen(rd()); // �޸��� Ʈ������ ���
	uniform_int_distribution<int> dist(0, 99);
	// normal_distribution<double> dist(���, ǥ������) ����

	// 1���� �迭 ���� �Է�
	cout << "�ʱ� �迭 ����\n";
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = dist(gen);
		cout << arr[i] << ' ';
	} cout << '\n';

	// Greater �켱 => �������� ����
	cout << "�������� ����\n";
	sort(arr, arr + 10, greater<int>());
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	} cout << '\n';

	// Less �켱 => �������� ����
	cout << "�������� ����\n";
	sort(arr, arr + 10, less<int>());
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	} cout << '\n';

	// ��ǥ �����Է�
	cout << "���� ��\n";
	point ARR[10];
	for (int i = 0; i < 10; i++)
	{
		int x = dist(gen);
		int y = dist(gen);

		cout << x << ' ' << y << '\n';
		ARR[i].x = x; ARR[i].y = y;
	}cout << "���� ��\n";

	// X��ǥ�� �켱������ �۰�, ���� ���¶�� Y��ǥ�� ���� ������ ����
	sort(&ARR[0], &ARR[10], compare);
	for (int i = 0; i < 10; i++)
	{
		cout << ARR[i].x << ' ' << ARR[i].y << '\n';
	}
}

/* Set ��� ���� (����) */
void set_practice()
{
	// ����
	set<int, greater<int>> example_set; // greater struct �� �ִ� ��

	// ���� ����
	example_set.insert(5);
	example_set.insert(4);
	example_set.insert(3);
	example_set.insert(6);
	example_set.insert(2);

	// �ߺ��Ǵ� �� ����
	example_set.insert(5);
	example_set.insert(2);

	// �� Ȯ��
	cout << "���� ���� Ȯ��\n";
	for (auto iter = example_set.begin(); iter != example_set.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << '\n';

	// 5��� ���� �ִ��� Ȯ���� �� �����
	cout << "���� 5 Ȯ���ϰ� �����\n";
	if (example_set.find(5) != example_set.end()) example_set.erase(5);
	for (auto& elem : example_set) cout << elem << ' ';
	cout << '\n';

	// ���� ���� ��ȯ�ϱ�
	cout << "���� 6 ���� ��ȯ�ϱ�\n";
	cout << example_set.count(6) << '\n';
}

/* Map ��� ���� (Map, Dictionary) */
void map_practice()
{
	// MAP ���� (Key, Value)
	map<int, int> m;

	// MAP�� �� ���� (3, 5), (6, 12), (11, 2), (10, 5)
	pair<int, int> p(10, 5);

	m.insert(p);
	m[3] = 5;
	m[6] = 12;
	m[11] = 2;

	// ���
	cout << "�ʱ� Key-Value ��\n";
	for (auto& m_p : m) cout << m_p.first << ' ' << m_p.second << '\n';
	cout << '\n';

	// Key ���� 4�� ��� ã�� (����)
	if (m.find(4) == m.end()) cout << "Key ���� �����ϴ�\n";

	// Key ���� 3�� �� Value�� 10���� ����
	if (m.find(3) != m.end()) m.at(3) = 10;
	cout << "<3, 5> �� <3, 10> ���� ����\n";
	for (auto& m_p : m) cout << m_p.first << ' ' << m_p.second << '\n';
	cout << '\n';

	// Ű ���� 10�� �� �����
	cout << "Ű ���� 10�� ��� �����\n";
	if (m.find(10) != m.end()) m.erase(10);
	for (auto& m_p : m) cout << m_p.first << ' ' << m_p.second << '\n';
}

/* Vector ��� ���� (Vector, List) */
void vector_practice()
{
	// ���� ����
	// vector<int> arr(10, 5) : 10���� 5�� ä��
	vector<int> arr;

	// ���� ����
	for (int i = 0; i < 10; i++) arr.push_back(i);
	
	// ���� ���
	for (int i = 0; i < int(arr.size()); i++) cout << arr[i] << ' ';
}

/* Deque ��� ���� */
/* Queue ��� ���� */
/* Permutation, Combination ��� ���� */
void permutation_practice()
{
	int example_arr[5] = { 5, 2, 4, 3, 1 };

	// ���ĵǾ����� ������ ��� ��츦 Ž������ �� ��
	// ���� ��� �� ���� �ʼ�
	// ���� next_permutation ���ڷ� greater, less ���� Ȱ���� �� ����
	do {
		for (int i = 0; i < 5; i++) cout << example_arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(example_arr, example_arr + 5));

	// Combination
	// Combination(4, 2)�� 1 2��, 0 2�� �� �迭�� Permutation ������ 1�� ��ġ�� Index���� �������� �ȴ�
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

/* String ��� ���� */
void string_practice()
{
	string str = "Hello Wolrd Everybody!!";

	// substr(���� ��ġ, ��ġ�� ���� �� ��)
	cout << str.substr(0, 4) << '\n'; // [0, 4)
	
	// strip ����
	int from = 0;
	int to = 0;
	while (to != -1)
	{
		to = str.find(' ', from);
		cout << str.substr(from, to - from) << '\n';
		from = to + 1;
	}

	// string ���ϱ�
	string str1 = "Won";
	string str2 = "Cheol";
	cout << str1 + str2 << '\n';

	// "some word" in string
	string target1 = "body";
	string target2 = "Body";
	cout << str.find(target1) << '\n';
	if (str.find(target2) == string::npos) cout << "ã�� �ܾ� ����!!\n";

	// compare (�� ������)
	target1 = "body";
	target2 = "body";
	cout << target1 << " == " << target2 << ':' << bool(target1 == target2) << '\n';		// �����ڴ� ASCII �ڵ� ������ ��!!
	cout << target1 << " compare " << target2 << ':' << target1.compare(target2) << '\n';	// 0�̸� ����, -1�̸� �ռ� ��, 1�̸� �ڷ�

	// append(str, ����, ��), append(�� ��, �߰� �� char)
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
