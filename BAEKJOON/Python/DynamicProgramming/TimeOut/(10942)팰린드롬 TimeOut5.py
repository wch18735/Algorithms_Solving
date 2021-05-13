if __name__=="__main__":
    N = int(input())

    num_list = [0] + list(map(int, input().split(' ')))

    # DP
    IMPOSSIBLE = 0
    POSSIBLE = 1
    NOT_VISIT = -1
    p_matrix = [[NOT_VISIT for i in range(N + 1)] for j in range(N + 1)]

    for length in range(N+1):
        for left in range(1, N+1):
            # 최대 조건
            if left + length > N:
                break

            # 오른쪽
            right = left + length

            # 펠린드롬 길이가 1인 경우
            if left == right:
                p_matrix[left][right] = POSSIBLE
            # 펠린드롬 길이가 2인 경우
            elif right == left + 1:
                if num_list[left] == num_list[right]:
                    p_matrix[left][right] = POSSIBLE
                else:
                    p_matrix[left][right] = IMPOSSIBLE
            # 펠린드롬 길이가 2 이상인 경우
            else:
                if num_list[left] == num_list[right] and p_matrix[left + 1][right - 1] == POSSIBLE:
                    p_matrix[left][right] = POSSIBLE
                else:
                    p_matrix[left][right] = IMPOSSIBLE

    M = int(input())

    for m in range(M):
        a, b = map(int, input().split(' '))

        print(p_matrix[a][b])