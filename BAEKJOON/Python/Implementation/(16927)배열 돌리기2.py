from collections import deque

# 행, 열, 회전
N, M, R = map(int, input().split(' '))

# 입력
MAP = [list(map(int, input().split(' '))) for _ in range(N)]

# 방향 (우, 하, 좌, 상)
direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def print_map():
    for i in range(N):
        for j in range(M):
            print(MAP[i][j], end=' ')
        print()

def main():
    # 상하좌우 경계
    left_limit = 0
    right_limit = M-1
    upper_limit = 0
    down_limit = N-1

    # start_point
    start_y, start_x = upper_limit, left_limit

    # rotate deque
    rotate_que = deque()
    position_que = deque()

    # direction_idx
    dir_idx = 0

    # add position
    while (left_limit < right_limit) and (upper_limit < down_limit):
        if len(rotate_que) > 0 and (start_y == upper_limit and start_x == left_limit):
            # 회전 수 계산
            que_length = len(rotate_que)
            tmpR = R % que_length
            rotate_que.rotate(-tmpR)

            # 좌표에 따라 배치
            for value, point in zip(rotate_que, position_que):
                x = point[1]
                y = point[0]
                MAP[y][x] = value

            # 큐 클리어
            rotate_que.clear()
            position_que.clear()

            # 상하좌우 경계 좁힘
            upper_limit += 1
            left_limit += 1
            right_limit -= 1
            down_limit -= 1

            # 현재 위치를 경계로 변경
            start_y = upper_limit
            start_x = left_limit
            continue

        # 현재 위치 저장
        rotate_que.append(MAP[start_y][start_x])
        position_que.append((start_y, start_x))

        # 다음 위치
        nx = start_x + direction[dir_idx][1]
        ny = start_y + direction[dir_idx][0]

        # 다음 위치가 유효 범위인지 확인
        if not (left_limit <= nx <= right_limit) or not (upper_limit <= ny <= down_limit):
            dir_idx = (dir_idx + 1) % 4
            # 새로운 좌표
            start_x += direction[dir_idx][1]
            start_y += direction[dir_idx][0]
            continue

        # 새 좌표 저장
        start_x = nx
        start_y = ny

    print_map()


if __name__=="__main__":
    main()