if __name__=="__main__":
    N = int(input())

    arr = list(map(int, input().split(' ')))

    # dp
    dp = [1 for i in range(N)]
    dp[0] = 1

    # 오른쪽 최대 값
    for i in range(1, N):
        for k in range(0, i):
            # 현재 값이 arr[k]보다 크고
            # dp[i] < dp[k] + 1
            if arr[k] < arr[i] and dp[i] < dp[k] + 1:
                dp[i] = dp[k] + 1

    # 최대 값
    print(max(dp))