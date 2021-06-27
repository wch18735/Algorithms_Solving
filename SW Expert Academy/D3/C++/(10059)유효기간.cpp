#include<iostream>
#include<string>

using namespace std;

bool check_month(string a)
{
	if (a[0] == '1')
	{
		if (a[1] == '0' || a[1] == '1' || a[1] == '2') return true;
		else return false;
	}
	else if (a[0] == '0')
	{
		if (a[1] == '0') return false;
		else return true;
	}
	else return false;
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	string _input, _front, _back;
	bool mmyy = false;
	bool yymm = false;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> _input;

		_front = _input.substr(0, 2);
		_back = _input.substr(2, 2);

		// check MMYY possible
		if (check_month(_front)) mmyy = true;

		// check YYMM possible
		if (check_month(_back)) yymm = true;

		if (mmyy && yymm) cout << "#" << test_case << " " << "AMBIGUOUS\n";
		else if (mmyy && !yymm) cout << "#" << test_case << " " << "MMYY\n";
		else if (!mmyy && yymm) cout << "#" << test_case << " " << "YYMM\n";
		else cout << "#" << test_case << " " << "NA\n";

		// initialize flags
		mmyy = false;
		yymm = false;
	}

	return 0;
}