from collections import deque

# 행, 열, 회전 횟수
N, M, R = map(int, input().split(' '))

# 입력
MAP = [list(map(int, input().split(' '))) for _ in range(N)]
CHK = [[0 for i in range(M)] for j in range(N)]

def print_map(blocks = None):
    if blocks == None:
        for y in range(N):
            for x in range(M):
                print(MAP[y][x], end=' ')
            print()
        print()
    else:
        for y in range(N):
            for x in range(M):
                print(blocks[y][x], end=' ')
            print()
        print()

# direction (우, 하, 좌, 상 => 시계방향)
direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def main():
    # rotate
    # 사각형을 감싸는 선 갯수
    que_num = min(N//2, M//2)

    # 선에 포함되는 큐
    que_list = [deque() for i in range(que_num)]
    value_list = [deque() for i in range(que_num)]

    # 큐에 담기
    start_x, start_y = 0, 0
    dir_idx = 0
    que_idx = 0

    while True:
        value = MAP[start_y][start_x]

        # Initial condition
        if len(que_list[que_idx]) == 0:
            que_list[que_idx].append((start_y, start_x))
            value_list[que_idx].append(value)
            CHK[start_y][start_x] = 1
        else:
            # 마지막 위치와 현재 위치 비교
            last_point = que_list[que_idx].pop()

            # 현재 위치가 이전 위치와 다를 때
            if not last_point == (start_y, start_x):
                # 이전 위치 다시 복구
                que_list[que_idx].append(last_point)
                value_list[que_idx].append(value)

            # 현재 위치 넣기
            que_list[que_idx].append((start_y, start_x))
            # 현재 위치 체크
            CHK[start_y][start_x] = 1

        # 다음 방향 진행 벡터
        dy, dx = direction[dir_idx]

        # 다음 진행할 x + dx 가 유효한 범위인지 확인
        if not (0 <= start_x + dx < M):
            dir_idx = (dir_idx + 1) % 4
            continue
        # 다음 진행할 y + dy 가 유효한 범위인지 확인
        if not (0 <= start_y + dy < N):
            dir_idx = (dir_idx + 1) % 4
            continue
        # 다음 방향이 기존에 밟았던 땅일 때
        if CHK[start_y + dy][start_x + dx] == 1:
            # 현재 방향이 위라면 다음 큐 리스트로 이동
            if dir_idx == 3:
                start_x += 1
                que_idx += 1
                if que_idx == que_num:
                    break
            # 방향만 전환
            dir_idx = (dir_idx + 1) % 4
            continue

        # 모든 조건에 부합하지 않을 때
        start_x += dx
        start_y += dy

    # 회전
    for l in value_list:
        for _ in range(R):
            l.append(l.popleft())

    # 답 프린트
    for que_idx, l in enumerate(que_list):
        for value, point in zip(value_list[que_idx], l):
            y, x = point
            MAP[y][x] = value

    print_map()




if __name__=="__main__":
    main()