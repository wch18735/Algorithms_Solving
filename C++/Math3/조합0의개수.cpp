#include <iostream>
#include <algorithm>

using namespace std;

int twoCount(int num) { // factorial ���� 2�� ����
	int cnt = 0;
	for (long int i = 2; num / i >= 1; i *= 2) {
		cnt += num / i;
	}

	return cnt;
}

int fiveCount(int num) { // factorial ���� 5�� ����
	int cnt = 0;
	for (long int i = 5; num / i >= 1; i *= 5) {
		cnt += num / i;
	}

	return cnt;
}

int main(void) {

	int n, m;
	cin >> n >> m;

	int n_nomi_two = twoCount(n);
	int n_nomi_five = fiveCount(n);
	int m_denomi_two = twoCount(m);
	int m_denomi_five = fiveCount(m);
	int n_m_denomi_two = twoCount(n - m);
	int n_m_denomi_five = fiveCount(n - m);

	cout << min(n_nomi_two - (m_denomi_two + n_m_denomi_two), n_nomi_five - (m_denomi_five + n_m_denomi_five));

	return 0;
}

/*

	1. factorial ���� 2 ������ �� ���� ���� ���� ���
	: 
	2		<- 8
	2 2		<- 4
	2 2 2	<- 2
	------
	8 4 2   
	
	10/2 -> 2�� �ϳ��� �ִ� �͵��� ���� 5
	10/4 -> 2^2 �� �ִ� �͵��� ���� 2
	�̶�, ������ ���� 2^2 ���� �� �ȿ� ���Ե� 2 �ϳ��� ���� 10/2 ���� ����߱� ������ ���� �� 2�� ���� üũ�ص� �ȴ�.
	�̿� ���� ������� 2�� ��� ���ϸ� �̵�

	2. for �� ���� index �� long int ��
	������ ���� �ִ밡 2^31 �� �Ǳ� ������ �̴� unsigned int �Ǵ� long ���� ǥ���ؾ� �Ѵ�.
*/