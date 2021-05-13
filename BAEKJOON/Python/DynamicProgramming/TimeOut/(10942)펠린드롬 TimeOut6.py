def palindrome(S, E):
    global MATRIX, num_list

    # 이전 결과값 이용
    if MATRIX[S][E] is not NOT_VISIT:
        return MATRIX[S][E]

    # 종료 조건
    if S == E:
        MATRIX[S][E] = POSSIBLE
        return POSSIBLE
    elif E == S + 1:
        # 짝수 판별
        if num_list[S] == num_list[E]:
            MATRIX[S][E] = POSSIBLE
            return POSSIBLE
        else:
            MATRIX[S][E] = IMPOSSIBLE
            return IMPOSSIBLE

    # 연산
    if num_list[S] == num_list[E] and palindrome(S + 1, E - 1) == POSSIBLE:
        MATRIX[S][E] = POSSIBLE
        return POSSIBLE
    else:
        MATRIX[S][E] = IMPOSSIBLE
        return IMPOSSIBLE


if __name__=="__main__":
    N = int(input())

    num_list = [0] + list(map(int, input().split(' ')))

    # DP
    IMPOSSIBLE = 0
    POSSIBLE = 1
    NOT_VISIT = -1
    MATRIX = [[NOT_VISIT for i in range(N + 1)] for j in range(N + 1)]

    M = int(input())

    for m in range(M):
        a, b = map(int, input().split(' '))

        if a == b:
            print(1)
        elif b == a + 1:
            if num_list[a] == num_list[b]:
                print(1)
            else:
                print(0)
        else:
            print(palindrome(a, b))