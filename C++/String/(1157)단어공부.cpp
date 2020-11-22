#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;

	int alpha_arr[26];
	fill(alpha_arr, alpha_arr + 26, 0);

	for (int i = 0; i < (int)str.size(); i++)
	{
		char alpha = str[i];

		// 대문자
		if ('A' <= alpha && alpha <= 'Z') alpha_arr[alpha - 'A'] += 1;
		
		// 소문자
		else if ('a' <= alpha && alpha <= 'z') alpha_arr[alpha - 'a'] += 1;
	}

	// 판단
	int max_value = 0;
	int cnt = 1;
	int max_idx = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alpha_arr[i] > max_value)
		{
			max_value = alpha_arr[i];
			cnt = 1;
			max_idx = i;
		}
		else if (alpha_arr[i] == max_value)
		{
			cnt += 1;
		}
	}

	if (cnt > 1) cout << '?';
	else cout << char('A' + max_idx);

	return 0;
}