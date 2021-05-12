if __name__=="__main__":
    N = int(input())

    num_list = [0] + list(map(int, input().split(' ')))

    # 펠린드롬 행렬
    NOT_VISIT = -1
    POSSIBLE = 1
    IMPOSSIBLE = 0
    p_matrix = [[NOT_VISIT for i in range(N + 1)] for j in range(N+1)]

    for p_len in range(len(num_list)):
        # 가장 왼쪽 index
        left_limit = 1
        right_limit = left_limit + p_len

        # index 증가
        while right_limit <= len(num_list) - 1:
            p_flag = True

            # 펠린드롬인지 확인
            a = left_limit
            b = right_limit

            while a <= b:
                if p_matrix[a][b] == IMPOSSIBLE:
                    p_flag = False
                    break
                elif p_matrix[a][b] == POSSIBLE:
                    break

                if num_list[a] == num_list[b]:
                    a += 1
                    b -= 1
                else:
                    p_flag = False
                    break

            if p_flag:
                p_matrix[left_limit][right_limit] = POSSIBLE
            else:
                p_matrix[left_limit][right_limit] = IMPOSSIBLE

            # 한 칸 옆으로 슬라이드
            left_limit += 1
            right_limit = left_limit + p_len

    M = int(input())

    for m in range(M):
        start_point, end_point = map(int, input().split(' '))

        # 출력
        print(p_matrix[start_point][end_point])
