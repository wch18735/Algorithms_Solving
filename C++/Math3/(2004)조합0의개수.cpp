#include <iostream>
#include <algorithm>

using namespace std;

int twoCount(int num) { // factorial 안의 2의 개수
	int cnt = 0;
	for (long int i = 2; num / i >= 1; i *= 2) {
		cnt += num / i;
	}

	return cnt;
}

int fiveCount(int num) { // factorial 안의 5의 개수
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

	1. factorial 안의 2 개수를 셀 때는 위와 같은 방법
	: 
	2		<- 8
	2 2		<- 4
	2 2 2	<- 2
	------
	8 4 2   
	
	10/2 -> 2가 하나만 있는 것들의 개수 5
	10/4 -> 2^2 이 있는 것들의 개수 2
	이때, 나누는 수가 2^2 지만 그 안에 포함된 2 하나는 이전 10/2 에서 계산했기 때문에 몫이 곧 2의 수로 체크해도 된다.
	이와 같은 방식으로 2를 계속 곱하며 이동

	2. for 문 안의 index 를 long int 로
	나누는 수의 최대가 2^31 이 되기 때문에 이는 unsigned int 또는 long 으로 표현해야 한다.
*/