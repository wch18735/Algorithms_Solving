if __name__=="__main__":
    N = int(input())

    # 수열 (index: 1 ~ N)
    num_list = [0] + list(map(int, input().split(' ')))

    # DP
    NOT_VISIT = -1
    POSSIBLE = 1
    IMPOSSIBLE = 0
    dp = [[NOT_VISIT for i in range(N + 1)] for j in range(N + 1)]

    M = int(input())

    for m in range(M):
        s, e = map(int, input().split(' '))

        left_p = s
        right_p = e

        p_flag = True
        while left_p <= right_p:
            if dp[left_p][right_p] == POSSIBLE:
                break
            elif dp[left_p][right_p] == IMPOSSIBLE:
                p_flag = False
                break
            elif dp[left_p][right_p] == NOT_VISIT:
                if num_list[left_p] == num_list[right_p]:
                    left_p += 1
                    right_p -= 1
                    continue
                else:
                    dp[left_p][right_p] = IMPOSSIBLE
                    p_flag = False
                    break

        if p_flag:
            dp[left_p][right_p] = POSSIBLE
            print(POSSIBLE)
        else:
            print(IMPOSSIBLE)
