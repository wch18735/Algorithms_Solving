#include<iostream>
#include<algorithm>

using namespace std;

int cards[52];

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	// total card numbers
	int card_num[12];

	// initialized target
	fill(card_num, card_num+12, 4);
	card_num[10] = 16;
	int card_sum = 0;
	int LOSE = 0;
	int WIN = 0;
	
	int N;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		// inputs
		cin >> N;
		
		for (int i = 0; i < N; i++)
		{
			cin >> cards[i];
			card_sum += cards[i];
			card_num[cards[i]] -= 1;
		}

		// check
		for (int i = 2; i <= 11; i++)
		{
			if (card_sum + i > 21) LOSE += card_num[i];
			else WIN += card_num[i];
		}

		if (LOSE >= WIN) cout << "#" << test_case << " STOP\n";
		else cout << "#" << test_case << " GAZUA\n";

		// initialize
		fill(card_num, card_num + 12, 4);
		card_num[10] = 16;
		card_sum = 0;
		LOSE = 0;
		WIN = 0;
	}

	return 0;
}