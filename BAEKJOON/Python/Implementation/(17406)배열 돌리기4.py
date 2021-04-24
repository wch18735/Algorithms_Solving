from itertools import permutations
from collections import deque
from copy import deepcopy

# N, M, R
N, M, R = map(int, input().split(' '))

# array
MAP = [list(map(int,input().split(' '))) for _ in range(N)]
COPIED_MAP = deepcopy(MAP)

# rcs_list
rcs_list = [list(map(int, input().split(' '))) for _ in range(R)]

# direction (우, 하, 좌, 상)
direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def rotate(r, c, s):
    # copied map
    copied_map = [[0 for i in range(M)] for j in range(N)]

    # 테두리 좌표, 값
    points = deque()
    values = deque()

    # limit
    left_limit = c-s-1
    right_limit = c+s-1
    upper_limit = r-s-1
    down_limit = r+s-1

    # 시작 위치
    start_x = left_limit
    start_y = upper_limit

    # 방향 index
    dir_idx = 0

    while (left_limit <= right_limit) and (upper_limit <= down_limit):
        # (r-1, c-1)에 도달할 때
        if upper_limit == r-1 and left_limit == c-1:
            copied_map[upper_limit][right_limit] = MAP[upper_limit][right_limit]

            # 경계 이동
            left_limit += 1
            right_limit -= 1
            upper_limit += 1
            down_limit -= 1
            continue

        # 현재 위치 추가
        points.append((start_y, start_x))
        values.append(MAP[start_y][start_x])

        # 다음 위치 계산
        dy, dx = direction[dir_idx]

        ny = start_y + dy
        nx = start_x + dx

        if ny == upper_limit and nx == left_limit:
            # 테두리 한 칸 회전
            values.rotate(1)

            # 각 테두리의 좌표 값에 회전된 값들 배치
            for point, value in zip(points, values):
                copied_map[point[0]][point[1]] = value

            # 경계 이동
            left_limit += 1
            right_limit -= 1
            upper_limit += 1
            down_limit -= 1

            # 시작 좌표 변경
            start_x = left_limit
            start_y = upper_limit

            # 좌표, 값 클리어
            values.clear()
            points.clear()
            continue

        # 다음 위치가 유효 범위인지 확인
        if not ((left_limit <= nx <= right_limit) and (upper_limit <= ny <= down_limit)):
            dir_idx = (dir_idx + 1) % 4
            # 다음 위치 다시 계산
            dy, dx = direction[dir_idx]
            ny = start_y + dy
            nx = start_x + dx

        start_y = ny
        start_x = nx

    # 모든 회전이 끝난 뒤
    for y in range(r-s-1, r+s):
        for x in range(c-s-1, c+s):
            MAP[y][x] = copied_map[y][x]

answer = 123456789

def main():
    global MAP, COPIED_MAP, answer
    for order in permutations(range(len(rcs_list)), len(rcs_list)):
        for rcs_idx in order:
            r,c,s = rcs_list[rcs_idx]
            rotate(r, c, s)

        # 배열 최소 값 계산
        for m in MAP:
            answer = min(sum(m), answer)

        # # 배열 확인
        # for e in MAP:
        #     print(*e)
        # print()

        # 배열 MAP 초기화
        MAP = deepcopy(COPIED_MAP)

    print(answer)

if __name__=="__main__":
    main()
    
# 테두리를 rotate 도는 방법
# 1. 테두리의 경계를 설정한다
# 2. point와 value를 저장한다
# 3. 경계를 넘어갈 때마다 방향을 전환한다
# 4. 다음 좌표가 경계의 시작일 때, value를 한 바퀴 회전시키고 이를 point 순서대로 저장한다
# 5. 경계를 이동시킨다