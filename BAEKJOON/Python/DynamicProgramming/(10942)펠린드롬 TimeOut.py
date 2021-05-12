def dfs(a, b):
    global dp, num_list
    # 후위 탐색 (맨 마지막 결과를 계속해서 Return 받아서 DP에 기록)

    if a == b:
        dp[a][b] = 1
        return True

    if b < a:
        if num_list[b] == num_list[a]:
            dp[b][a] = 1
            return True
        else:
            dp[b][a] = 0
            return False

    if dp[a][b] == -1:
        # 아직 펠린드롬 결과 모를 때
        if num_list[a] == num_list[b]:
            # 현재 끝 가장자리가 맞으면 안쪽 검사
            if dfs(a+1, b-1):
                dp[a][b] = 1
                return True
            else:
                dp[a][b] = 0
                return False
        else:
            dp[a][b] = 0
            return False
    elif dp[a][b] == 1:
        return True
    else:
        return False

if __name__=="__main__":
    # 수열 길이
    N = int(input())

    # DP
    # -1: don't know
    # 0: false
    # 1: true
    dp = [[-1 for i in range(N + 1)] for j in range(N + 1)]

    # 수열 (INDEX 1 ~ N)
    num_list = [0] + list(map(int, input().split(' ')))

    # S, E
    M = int(input())

    for t in range(1, M+1):
        a, b = map(int, input().split(' '))

        if dfs(a, b):
            print(1)
        else:
            print(0)