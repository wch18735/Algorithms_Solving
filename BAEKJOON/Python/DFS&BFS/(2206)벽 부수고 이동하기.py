from collections import deque

# N, M
N, M = map(int, input().split())

# bricks map
bricks = [[int(ch) for ch in input()] for _ in range(N)]
chk = [[[0, 0] for i in range(M)] for j in range(N)]

# directions
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# def
def bfs():
    # 이동 위치 기록 deque
    positions = deque()

    # target postition
    t_x, t_y = (N - 1, M - 1)

    # initial x, y, state, step
    c_x, c_y = (0, 0)
    step = 1
    state = 1

    # init append
    positions.append((c_x, c_y, state, step))
    chk[c_x][c_y][state] = 1

    # answer
    answer = 1_000_000_000

    # bfs
    while bool(positions):
        c_x, c_y, state, step = positions.popleft()

        # 현재 위치가 목적지인 경우
        if c_x == t_x and c_y == t_y:
            answer = min(answer, step)
            continue

        # 현재 위치가 목적지가 아닌 경우 탐색
        for i in range(4):
            nx = c_x + dx[i]
            ny = c_y + dy[i]

            # x 허용 범위에 해당하지 않는 경우
            if nx < 0 or nx >= N:
                continue
            # y 허용 범위에 해당하지 않는 경우
            if ny < 0 or ny >= M:
                continue
            # 벽이며 뚫을 수 없는 경우
            if bricks[nx][ny] == 1 and state < 1:
                continue
            # 이미 지나온 길이며, 최소 경로가 이미 지나간 경우
            # state 를 이용해 벽을 뚫은 상태인지 판단
            if chk[nx][ny][state] != 0:
                continue

            # 벽인 경우 남은 state로 뚫음
            if bricks[nx][ny] == 1 and state == 1:
                positions.append((nx, ny, state - 1, step + 1))
                chk[nx][ny][state] = 1

            # 벽이 아닌 경우 이동
            else:
                positions.append((nx, ny, state, step + 1))
                chk[nx][ny][state] = 1

    if answer == 1_000_000_000:
        return -1
    return answer

def main():
    print(bfs())

if __name__=="__main__":
    main()