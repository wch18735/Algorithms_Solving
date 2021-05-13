if __name__=="__main__":
    N = int(input())

    num_list = [0] + list(map(int, input().split(' ')))

    # DP
    IMPOSSIBLE = 0
    POSSIBLE = 1
    MATRIX = [[IMPOSSIBLE for i in range(N + 1)] for j in range(N + 1)]

    # DP 초기화
    # palindrome size: 1
    for i in range(1, N + 1):
        MATRIX[i][i] = POSSIBLE

    # palindrome size: 2
    for i in range(1, N):
        if num_list[i] == num_list[i+1]:
            MATRIX[i][i+1] = POSSIBLE

    # palindrome size: 3 이상
    for dif in range(2, N):
        for left_point in range(1, N+1):
            if left_point + dif > N:
                break

            # 양 끝이 매칭이고 안쪽이 모두 팰린드롬이면 팰린드롬
            if num_list[left_point] == num_list[left_point + dif] and MATRIX[left_point + 1][left_point + dif - 1]:
                MATRIX[left_point][left_point + dif] = POSSIBLE
            else:
                MATRIX[left_point][left_point + dif] = IMPOSSIBLE

    M = int(input())

    for m in range(M):
        S, E = map(int, input().split(' '))

        # 출력
        print(MATRIX[S][E])