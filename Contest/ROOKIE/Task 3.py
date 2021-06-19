def solution(U, L, C):
    if U + L != sum(C):
        return "IMPOSSIBLE"

    # matrix complete flag
    END_FLAG = False

    # matrix dp
    DP = [[0 for i in range(len(C))] for j in range(2)]

    for idx, c in enumerate(C):
        if c == 0:
            continue
        if c == 1:
            if U > 0:
                DP[0][idx] = 1
                U -= 1
            else:
                DP[1][idx] = 1
                L -= 1
        elif c == 2:
            DP[0][idx], DP[1][idx] = 1, 1
            U -= 1
            L -= 1

    # upper and lower matrix
    upper_matrix, lower_matrix = DP[0], DP[1]

    upper_matrix = [str(u) for u in upper_matrix]
    lower_matrix = [str(l) for l in lower_matrix]

    answer = ''.join(upper_matrix)
    answer += ','
    answer += ''.join(lower_matrix)

    return answer