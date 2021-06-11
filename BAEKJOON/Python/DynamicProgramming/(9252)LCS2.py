def track(i, j):
    global DP

    answer = []

    while i != 0 or j != 0:
        # 현재 값이 왼쪽에서 온 것인지 오른쪽에서 온 것인지 확인
        current_val = DP[i][j]

        if DP[i-1][j] == current_val:
            i = i - 1
        elif DP[i][j-1] == current_val:
            j = j - 1
        else:
            # 일치할 때
            answer.append(i)
            i = i - 1
            j = j - 1

    return answer

if __name__ == "__main__":
    UPPER_STR = input()
    DOWN_STR = input()

    DP = [[0 for i in range(len(DOWN_STR) + 1)] for j in range(len(UPPER_STR) + 1)]

    for u_idx in range(1, len(UPPER_STR) + 1):
        for d_idx in range(1, len(DOWN_STR) + 1):
            if UPPER_STR[u_idx - 1] == DOWN_STR[d_idx - 1]:
                # 두 글자가 일치할 때
                # u_idx + 1, d_idx + 1 위치에 현재 값보다 +1
                DP[u_idx][d_idx] = DP[u_idx - 1][d_idx - 1] + 1
            else:
                # 글자가 일치하지 않을 때
                DP[u_idx][d_idx] = max(DP[u_idx][d_idx - 1], DP[u_idx - 1][d_idx])

    answer = track(len(UPPER_STR), len(DOWN_STR))

    for idx in answer[::-1]:
        print(UPPER_STR[idx - 1], end='')