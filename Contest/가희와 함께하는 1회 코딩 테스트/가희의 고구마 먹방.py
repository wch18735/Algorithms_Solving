from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def dfs(y_idx, x_idx):
    global MAP, CHK, T, SP, TURN, answer, R, C

    if TURN == T:
        answer = max(SP, answer)
        return

    # search
    for i in range(4):
        nx = x_idx + dx[i]
        ny = y_idx + dy[i]

        # new x range check
        if not (0 <= nx < C):
            continue

        # new y range check
        if not (0 <= ny < R):
            continue

        # block check
        if MAP[ny][nx] == '#':
            continue

        if MAP[ny][nx] == 'S':
            # not a optimized path
            if SP + 1 < CHK[TURN + 1][ny][nx]:
                continue
            else:
                # increase sweet potato and turn
                SP += 1
                TURN += 1
                MAP[ny][nx] = '.'

                # do search
                CHK[TURN][ny][nx] = SP
                dfs(ny, nx)

                # return SP and TURN to original
                TURN -= 1
                SP -= 1
                MAP[ny][nx] = 'S'
        else:
            # not a optimized path
            if SP < CHK[TURN + 1][ny][nx]:
                continue
            else:
                # SP == CHK[TURN + 1][ny][nx] is dfs execution condition
                # increase sweet potato and turn
                TURN += 1

                # do search
                dfs(ny, nx)

                # return TURN to original
                TURN -= 1

def print_chk():
    global CHK, R, C, T

    for t in range(T+1):
        for i in range(R):
            print(*CHK[t][i])
        print()

if __name__=="__main__":
    R, C, T = map(int, input().split(' '))

    MAP = [list(input().strip()) for _ in range(R)]
    CHK = [[[0 for j in range(C)] for i in range(R)] for t in range(T + 1)]

    answer = 0

    for i in range(R):
        for j in range(C):
            if MAP[i][j] == 'G':
                SP, TURN = 0, 0
                dfs(i, j)
                break

    print(answer)