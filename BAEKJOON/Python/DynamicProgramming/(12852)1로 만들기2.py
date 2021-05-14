if __name__=="__main__":
    N = int(input())

    # dp 초기화
    dp = [float('inf') for _ in range(N+1)]
    dp_path = [[] for _ in range(N+1)]
    dp[1] = 0
    dp_path[1] = [1]

    for i in range(1, N+1):
        if i + 1 <= N and dp[i] + 1 < dp[i + 1]:
            dp[i + 1] = dp[i] + 1
            dp_path[i + 1] = dp_path[i] + [i + 1]

        if i * 2 <= N and dp[i] + 1 < dp[i * 2]:
            dp[i * 2] = dp[i] + 1
            dp_path[i * 2] = dp_path[i] + [i * 2]

        if i * 3 <= N and dp[i] + 1 < dp[i * 3]:
            dp[i * 3] = dp[i] + 1
            dp_path[i * 3] = dp_path[i] + [i * 3]

    print(len(dp_path[N]) - 1)
    dp_path[N].sort(key=lambda x:-x)
    print(*dp_path[N])
