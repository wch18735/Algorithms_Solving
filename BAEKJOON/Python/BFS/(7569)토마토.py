from collections import deque

# M: 가로, N: 세로, H: 층
M, N, H = map(int, input().split())

# INPUT
tomatos = [[list(map(int, input().split())) for i in range(N)] for j in range(H)]
chk = [[[0 for i in range(M)] for j in range(N)] for k in range(H)]

# direction
# 우 좌 하 상 위 아래
dx = [1, 0, -1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]


# position (x, y, z)
def bfs(answer):
    # bfs 를 통해 가능한 모든 경우 조사
    # empty 일 때 하나라도 익지 않은 토마토가 있으면 -1
    # 하나도 없으면 days 출력

    # deque 선언
    positions = deque()

    # 최초 익은 토마토 위치
    for pos in init_deque(M, N, H, tomatos):
        positions.append(pos)

    # 당일 익은 토마토 개수
    day_tomato_amount = len(positions)

    # 탐색
    while bool(positions):
        z, y, x = positions.popleft()
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]

            # x 범위를 넘어가는 경우
            if nx < 0 or nx >= M:
                continue
            # y 범위를 넘어가는 경우
            if ny < 0 or ny >= N:
                continue
            # z 범위를 넘어가는 경우
            if nz < 0 or nz >= H:
                continue
            # 탐색하려는 위치가 이미 탐색한 경우
            if chk[nz][ny][nx] == 1:
                continue
            # 탐색하려는 위치에 토마토가 없는 경우
            if tomatos[nz][ny][nx] == -1:
                continue

            # 나머지 경우 추가
            positions.append((nz, ny, nx))

            # 해당 부분을 방문하는 것으로 바꿔줌
            chk[nz][ny][nx] = 1

            # 원래 위치에 1로 바꿈
            tomatos[nz][ny][nx] = 1

        # 당일 익은 토마토 하나를 처리
        day_tomato_amount -= 1

        # 당일 익은 토마토를 모두 처리한 경우
        if day_tomato_amount == 0:
            day_tomato_amount = len(positions)
            answer += 1

    # 토마토가 익지 않은 것이 하나라도 있는지 확인
    for i in range(H):
        for j in range(N):
            for k in range(M):
                if tomatos[i][j][k] == 0:
                    return -1

    # 토마토가 익지 않은 경우가 없을 때
    return answer - 1


# 초기 list를 반환
def init_deque(m, n, h, tomato_map):
    init_list = list()
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if tomato_map[i][j][k] == 1:
                    init_list.append((i, j, k))
                    # 초기 익은 위치를 1로 바꿔줌
                    chk[i][j][k] = 1
    return init_list


def main():
    print(bfs(0))


if __name__ == "__main__":
    main()