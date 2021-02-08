#include <iostream>

using namespace std;

// 솔루션
void solution(int test_case);

// 필름
int film[21][21];
int origin[21][21];

// 세로, 가로, 합격기준
int D, W, K;

// 솔루션
void solution(int test_case);

// 검사
bool check_film();

// 투약 상태
int inject_state[21];

// 최소 투약 횟수
int min_cnt = 20;

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		solution(test_case);
	}

	return 0;
}

void inject_film(int film_idx, int cnt)
{
	// 주입 완료
	if (film_idx == D + 1)
	{
		if (check_film())
		{
			if (min_cnt > cnt) min_cnt = cnt;
		}
		return;
	}

	// film_idx 에 주입하는 것인지 확인
	if (inject_state[film_idx] == 1) 
	{
		// A를 주입 film_idx 에 주입
		for (int i = 1; i <= W; i++) film[film_idx][i] = 0;
		inject_film(film_idx + 1, cnt);
		
		// B를 주입
		for (int i = 1; i <= W; i++) film[film_idx][i] = 1;
		inject_film(film_idx + 1, cnt);

		// film_idx 다시 원상 복구
		for (int i = 1; i <= W; i++) film[film_idx][i] = origin[film_idx][i];
	}
	else
	{
		inject_film(film_idx + 1, cnt);
	}

	return;
}

void update_inject(int film_idx, int cnt)
{
	// 가지치기
	if (cnt >= min_cnt) return; // 더 많은 경우는 볼 필요 없음
	
	if (cnt > K) return;

	// 투약 상태 업데이트 완료
	if (film_idx == D + 1)
	{
		// 만들어진 상태를 이용해 투약 후 검사
		inject_film(1, cnt);

		return;
	}


	for (int i = 0; i < 2; i++)
	{
		inject_state[film_idx] = i;
		
		if (i == 0) update_inject(film_idx + 1, cnt);
		else update_inject(film_idx + 1, cnt + 1);
	}

}

void solution(int test_case)
{
	// 세로, 가로, 합격기준
	cin >> D >> W >> K;

	// 필름입력
	for (int i = 1; i <= D; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> film[i][j];
		}
	}

	// 원본 복사
	for (int i = 1; i <= D; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			origin[i][j] = film[i][j];
		}
	}

	// 초기 합격여부 검사
	if (check_film() || K == 1)
	{
		cout << '#' << test_case << ' ' << 0 << '\n';
		return;
	}

	// 투약 상태 만듬 (재귀)
	update_inject(1, 0);

	// 답안
	cout << '#' << test_case << ' ' << min_cnt << '\n';

	// 초기화
	min_cnt = 20;
}

bool check_film()
{
	for (int i = 1; i <= W; i++)
	{
		bool line_pass = false;
		for (int j = 1; j + K - 1 <= D; j++)
		{
			int start = film[j][i];
			int cnt = 0;
			for (int t = 0; t < K; t++)
			{
				if (film[j + t][i] == start) cnt++;
			}
			if (cnt == K)
			{
				line_pass = true;
			}
		}
		if (line_pass == false) return line_pass;
	}

	return true;
}