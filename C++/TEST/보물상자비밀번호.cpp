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
	// N, K 입력
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

	// 중복 제거
	keySet.erase(unique(keySet.begin(), keySet.end()), keySet.end());

	// K번째 string
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

/* 배운 것 */
// string 을 sort 하면 한 글자씩 비교하면서 ASCII 값 순서대로 진행
// vector.erase(unique(vector.begin(), vector.end()), vector.end()) 로 sort 된 vector를 지울 수 있다는 것
// string 은 클래스로 push_back, erase, find 등이 가능함
// vector<char> input, 이 있을 때, string s(input.begin(), input.end()) 로 string 생성 가능