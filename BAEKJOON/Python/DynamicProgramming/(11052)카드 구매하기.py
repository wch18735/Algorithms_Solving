if __name__=="__main__":
    # 개수
    N = int(input())

    # 카드 패키지
    card_p = [0] + list(map(int, input().split(' ')))

    # DP
    dp = [[0 for i in range(N+1)] for j in range(N + 1)]

    for p in range(1, N+1):
        for card_num in range(N+1):
            if card_num - p < 0:
                # 새로운 카드를 사용할 수 없을 때
                dp[p][card_num] = dp[p-1][card_num]
                continue

            # 현재 카드를 버리고 새로운 카드를 넣었을 때
            dp[p][card_num] = max(dp[p-1][card_num], dp[p][card_num - p] + card_p[p])

    # 최대 값
    print(dp[N][N])