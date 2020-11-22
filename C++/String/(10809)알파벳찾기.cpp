#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string a;
	cin >> a;

	int arr[26];
	fill(arr, arr + 26, -1);

	for (int i = 0; i < (int)a.size(); i++)
	{
		int idx = a[i] - 'a';
		if (arr[idx] == -1) arr[idx] = i;
	}

	for (int i = 0; i < 26; i++) cout << arr[i] << ' ';
}