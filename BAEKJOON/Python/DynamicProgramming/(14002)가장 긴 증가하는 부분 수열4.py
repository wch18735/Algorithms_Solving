if __name__=="__main__":
    N = int(input())

    num_arr = list(map(int, input().split(' ')))

    # 경로 갱신 -> 업데이트 후 자기 위치 추가
    dp = [1 for _ in range(N)]
    dp_path = [[num_arr[i]] for i in range(N)]

    for i in range(1, N):
        for k in range(0, i):
            # arr[k]보다 크고 dp[i] < dp[k] + 1일 때 업데이트
            if num_arr[k] < num_arr[i] and dp[i] < dp[k] + 1:
                # dp 부분 최대 값 업데이트
                dp[i] = dp[k] + 1

                # 경로 추적
                dp_path[i] = dp_path[k] + [num_arr[i]]

    max_val = max(dp)
    print(max_val)

    max_idx = dp.index(max_val)
    print(*dp_path[max_idx])