#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m;
	int num;
	int left = 0;
	int right = 0;

	deque<int> myDq;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		myDq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> num;

		for (int j = 0; j < (int)myDq.size(); j++) 
		{
			if (num == myDq[j]) 
			{
				if (j < (int)myDq.size() - j) 
				{ // �������� rotate �� pop
					for (int k = 0; k < j; k++) 
					{
						myDq.push_back(myDq.front());
						myDq.pop_front();
						left++;
					}
					myDq.pop_front();
				}
				else 
				{// ���������� rotate �� pop
					for (int k = 0; k < (int)myDq.size() - j; k++) 
					{
						myDq.push_front(myDq.back());
						myDq.pop_back();
						right++;
					}
					myDq.pop_front();
				}
			}
		}
	}

	cout << left + right;

	return 0;
}

/*
	���ĵ� ���¿��� index ���� �ڱ� �տ� �ڱ⺸�� ū (�Ǵ� ���� ���ؿ� ���� ����) ���� ����
*/