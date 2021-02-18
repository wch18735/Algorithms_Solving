#include<iostream>

using namespace std;

void solution(int test_case);

int hour;
int minute;
int i_hour;
int i_minute;

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
	cin >> hour >> minute >> i_hour >> i_minute;

	if (minute + i_minute > 59)
	{
		minute = minute + i_minute - 60;
		hour += 1;
	}
	else
	{
		minute += i_minute;
	}

	if (hour + i_hour > 12)
	{
		hour = hour + i_hour - 12;
	}
	else
	{
		hour += i_hour;
	}

	cout << '#' << test_case << ' ' << hour << ' ' << minute << '\n';
}