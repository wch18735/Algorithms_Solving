#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <math.h>

using namespace std;

void solution(int test_case);

int main(void)
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		solution(i);
	}

	return 0;
}

void solution(int test_case)
{
	// N, K �Է�
	int N, K;
	cin >> N >> K;

	// slide_size
	int slide_size = (int)N / 4;

	// input char vector
	deque<char> inputChar;
	char ch;
	for (int i = 0; i < N; i++)
	{
		cin >> ch;
		inputChar.push_back(ch);
	}

	// vector<string> keySet
	vector<string> keySet;

	for (int Rotate = 0; Rotate < slide_size; Rotate++)
	{
		for (int i = 0; i < 4; i++)
		{
			string s;
			int start_idx = i * slide_size;
			int end_idx = (i + 1) * slide_size;

			for (int j = start_idx; j < end_idx; j++)
			{
				s.push_back(inputChar[j]);
			}
			keySet.push_back(s);
		}
		inputChar.push_front(inputChar.back());
		inputChar.pop_back();
	}

	// sorting
	sort(keySet.begin(), keySet.end(), greater<string>());

	// �ߺ� ����
	keySet.erase(unique(keySet.begin(), keySet.end()), keySet.end());

	// K��° string
	string answer = keySet[K - 1];

	// power
	int power = 0;
	int sum = 0;
	while (!answer.empty())
	{
		char ch = answer.back();
		answer.pop_back();

		if ('A' <= ch && ch <= 'F')
		{
			int n = (int)ch - (int)'A' + 10;
			sum += (int)n*pow(16, power);
			power += 1;
		}
		else
		{
			int n = (int)ch - (int)'0';
			sum += (int)n * pow(16, power);
			power += 1;
		}
	}

	cout << '#' << test_case << ' ' << sum << '\n';

	return;
}

/* ��� �� */
// string �� sort �ϸ� �� ���ھ� ���ϸ鼭 ASCII �� ������� ����
// vector.erase(unique(vector.begin(), vector.end()), vector.end()) �� sort �� vector�� ���� �� �ִٴ� ��
// string �� Ŭ������ push_back, erase, find ���� ������
// vector<char> input, �� ���� ��, string s(input.begin(), input.end()) �� string ���� ����