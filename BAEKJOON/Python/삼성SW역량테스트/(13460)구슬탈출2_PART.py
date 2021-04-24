# dfs로 R이 Hole 에 도달하는지 확인
# 도달하지 않는다면 -1 (-> initial answer = float('inf'))
# 도달할 때까지 방향전환을 저장
# 저장된 방향순서를 동일하게 적용
# 모든 방향을 다 소모할 때까지 B가 O에 닿지 않으면 asnwer 업데이트

from collections import deque

# 입력
N, M = map(int, input().split(' '))
MAP = [list(input()) for _ in range(N)]

# Red, Blue, hOle point
point_R = (0, 0)
point_B = (0, 0)
point_O = (0, 0)

for y in range(N):
    for x in range(M):
        if MAP[y][x] == 'R':
            point_R = (y, x)
        if MAP[y][x] == 'B':
            point_B = (y, x)
        if MAP[y][x] == 'O':
            point_O = (y, x)

# 방향 (우0, 하1, 좌2, 상3), 방향 큐
direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

# 답
answer = float('inf')

def dfs(point_r, dir_idx, dir_que):
    global answer

    current_y, current_x = point_r

    if len(dir_que) == 0:
        # 처음 진행일 때
        for i in range(4):
            ny = current_y + direction[i][0]
            nx = current_x + direction[i][1]

            if MAP[ny][nx] == '.' or MAP[ny][nx] == 'O':
                dir_que.append(i)
                dfs((ny, nx), i, dir_que)
                dir_que = dir_que[:-1]
        return

    # O에 도달하면
    if point_r == point_O:
        # 저장된 방향으로 진행했을 때, point_B가 O에 도달하는지 확인
        result = len(dir_que)

        # 파란 공 시작 위치
        blue_y = point_B[0]
        blue_x = point_B[1]

        for dir in dir_que:
            # 방향에 따른 파란 공 다음 위치
            blue_ny = blue_y + direction[dir][0]
            blue_nx = blue_x + direction[dir][1]

            # 같은 방향으로 진행
            while MAP[blue_ny][blue_nx] != '#':
                # 진행중 Hole 만나면 게임 끝
                if MAP[blue_ny][blue_nx] == 'O':
                    return

                # 다음 위치로 이동
                blue_y = blue_ny
                blue_x = blue_nx

                # 다음 위치 확인
                blue_ny = blue_y + direction[dir][0]
                blue_nx = blue_x + direction[dir][1]

        # 모든 방향으로 돌렸을 때 O와 만나지 않음
        answer = min(answer, result)

    # 진행방향으로 다음 위치
    ny = current_y + direction[dir_idx][0]
    nx = current_x + direction[dir_idx][1]

    # 진행 방향의 다음 위치가 불가능할 때 방향 전환
    if MAP[ny][nx] == '#':
        # 방향 전환
        if dir_idx % 2 == 0:
            # 좌우로 움직이는 중이면
            for i in [1, 3]:
                # 진행방향으로 다음 위치
                ny = current_y + direction[i][0]
                nx = current_x + direction[i][1]

                if MAP[ny][nx] != '#':
                    dir_que.append(i)
                    dfs((ny, nx), i, dir_que)
                    dir_que = dir_que[:-1]
        else:
            # 상하로 움직이는 중이었으면
            for i in [0, 2]:
                # 진행방향으로 다음 위치
                ny = current_y + direction[i][0]
                nx = current_x + direction[i][1]

                if MAP[ny][nx] != '#':
                    dir_que.append(i)
                    dfs((ny, nx), i, dir_que)
                    dir_que = dir_que[:-1]
    else:
        # 가능하면 진행
        dfs((ny, nx), dir_idx, dir_que)


def main():
    global answer

    dfs(point_R, 0, [])

    if answer == float('inf'):
        print(-1)
    else:
        print(answer)

if __name__=="__main__":
    main()