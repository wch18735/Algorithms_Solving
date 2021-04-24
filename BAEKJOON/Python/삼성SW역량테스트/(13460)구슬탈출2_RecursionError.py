# 두 구슬이 상호작용함
# 빨간 구슬의 움직임이 끝날 때마다 두 공의 success check
# 각 공은 서로의 다음 위치에는 존재할 수 없다
# 시작: 가능한 방향으로 모두 진행
# 진행: 한 방향으로 진행하다가 벽 or 파란 구슬을 만나면 방향 탐색 후 전환
# red success true & blue success false 인 경우만 통과

# 입력
N, M = map(int, input().split(' '))

# MAP
MAP = [list(input()) for _ in range(N)]

for y in range(N):
    for x in range(M):
        if MAP[y][x] == 'B':
            bluePoint = (y, x)
        if MAP[y][x] == 'R':
            redPoint = (y, x)
        if MAP[y][x] == 'O':
            holePoint = (y, x)

# 방향 (상, 하, 좌, 우)
direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# 답
answer = float('inf')

# success (Red, Blue)
hole_success = False

# red stop point
stop_point = set([redPoint])

def dfs(dir_idx, current_red, current_blue, turn_number):
    global answer, hole_success, stop_point

    # 최소 값보다 많이 체크하면 끝
    if answer != float('inf') and answer <= turn_number:
        return

    if len(stop_point) > 1 and current_red in redPoint:
        return

    # 현재 방향으로 이동 중 Hole 만났는지 체크
    if current_red == holePoint:
        hole_success = True
    if current_blue == holePoint:
        hole_success = False
        return

    # 현재 진행방향으로 움직임
    # RED
    red_ny = current_red[0] + direction[dir_idx][0]
    red_nx = current_red[1] + direction[dir_idx][1]

    # BLUE
    blue_ny = current_blue[0] + direction[dir_idx][0]
    blue_nx = current_blue[1] + direction[dir_idx][1]

    # 이동할 수 있는지 검사
    # 다음 위치가 벽인지 검사
    if MAP[red_ny][red_nx] == '#':
        red_ny = current_red[0]
        red_nx = current_red[1]
    if MAP[blue_ny][blue_nx] == '#':
        blue_ny = current_blue[0]
        blue_nx = current_blue[1]

    # 다음 위치에서 구슬끼리 만나는지 검사
    if red_nx == blue_nx and red_ny == blue_ny:
        red_ny = current_red[0]
        red_nx = current_red[1]
        blue_ny = current_blue[0]
        blue_nx = current_blue[1]

    # red 현재 위치와 다음 위치가 동일한 경우 방향 전환
    # 방향 전환 시 Hole 만난 여부 체크
    # 더 이상 구슬이 움직이지 않을 때
    if current_red == (red_ny, red_nx) and current_blue == (blue_ny, blue_nx):
        stop_point.add(current_red)
        # for i in range(N):
        #     for j in range(M):
        #         if not (i == red_ny and j == red_nx):
        #             print('.', end=' ')
        #         else:
        #             print('R', end=' ')
        #     print()

        if hole_success:
            answer = min(answer, turn_number)
            hole_success = False
            return

        if dir_idx < 2:
            # 상하 움직임 -> 좌우로 움직임
            for i in [2, 3]:
                # 좌우 방향 중 가능한 방향만 진행
                # RED
                red_ny = current_red[0] + direction[i][0]
                red_nx = current_red[1] + direction[i][1]

                # BLUE
                blue_ny = current_blue[0] + direction[i][0]
                blue_nx = current_blue[1] + direction[i][1]

                # 다음 위치가 벽인지 검사
                if MAP[red_ny][red_nx] == '#':
                    continue
                if MAP[blue_ny][blue_nx] == '#':
                    blue_ny = current_blue[0]
                    blue_nx = current_blue[1]

                # 다음 위치에서 구슬끼리 만나는지 검사
                if red_nx == blue_nx and red_ny == blue_ny:
                    continue

                dfs(i, current_red, current_blue, turn_number + 1)
        else:
            # 좌우 움직임 -> 상하로 움직임
            for i in [0, 1]:
                # 상하 방향 중 가능한 방향만 진행
                # RED
                red_ny = current_red[0] + direction[i][0]
                red_nx = current_red[1] + direction[i][1]

                # BLUE
                blue_ny = current_blue[0] + direction[i][0]
                blue_nx = current_blue[1] + direction[i][1]

                # 다음 위치가 벽인지 검사
                if MAP[red_ny][red_nx] == '#':
                    continue
                if MAP[blue_ny][blue_nx] == '#':
                    blue_ny = current_blue[0]
                    blue_nx = current_blue[1]

                # 다음 위치에서 구슬끼리 만나는지 검사
                if red_nx == blue_nx and red_ny == blue_ny:
                    continue

                dfs(i, current_red, current_blue, turn_number + 1)
    else:
        # 계속해서 진행할 수 있는 경우 진행
        dfs(dir_idx, (red_ny, red_nx), (blue_ny, blue_nx), turn_number)



def main():
    # 네 방향으로 모두 탐색
    for dir_idx in range(4):
        dfs(dir_idx, redPoint, bluePoint, 1)

    # 답 출력
    if answer == float('inf'):
        print(-1)
    else:
        print(answer)

if __name__=="__main__":
    main()