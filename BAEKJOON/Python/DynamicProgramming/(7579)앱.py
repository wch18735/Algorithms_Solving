def main():
    N, M = map(int, input().split())
    app_mem = list(map(int, input().split()))
    cost = list(map(int, input().split()))

    cost_sum = sum(cost)

    dp = [[0 for col in range(cost_sum)] for row in range(N)]
    res = sum(cost)
    for cost_limit in range(cost_sum):
        for app_idx in range(len(app_mem)):
            if app_idx == 0:
                if cost_limit < cost[app_idx]:
                    pass
                else:
                    dp[app_idx][cost_limit] = app_mem[app_idx]
            else:
                if cost_limit < cost[app_idx]:
                    dp[app_idx][cost_limit] = dp[app_idx - 1][cost_limit]
                else:
                    dp[app_idx][cost_limit] = max(dp[app_idx - 1][cost_limit - cost[app_idx]] + app_mem[app_idx],
                                                  dp[app_idx - 1][cost_limit])

            if dp[app_idx][cost_limit] >= M:
                res = min(res, cost_limit)

    print(res)


if __name__=="__main__":
    main()