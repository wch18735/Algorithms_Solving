if __name__=="__main__":
    N = int(input())

    num_list = [0] + list(input().split(' '))

    # dp
    NOT_VISIT = -1
    POSSIBLE = 1
    IMPOSSIBLE = 0
    p_matrix = [[NOT_VISIT for i in range(N + 1)] for j in range(N + 1)]

    for l in range(N):
        # 펠린드롬 길이: +0 ~ +(N-1)
        for S in range(1, N+1-l):
            E = S + l

            if S == E:
                p_matrix[S][E] = POSSIBLE
            else:
                if p_matrix[S][E] == IMPOSSIBLE:
                    continue

                # Not Visit (visit yet)
                if num_list[S] == num_list[E]:
                    p_matrix[S][E] = POSSIBLE
                else:
                    left_point = S
                    right_point = E

                    # 더 이상 볼 필요 없는 것들
                    while 0 < S and E <= N:
                        p_matrix[S][E] = IMPOSSIBLE
                        S -= 1
                        E += 1

    M = int(input())

    for m in range(M):
        a, b = map(int, input().split(' '))

        print(p_matrix[a][b])