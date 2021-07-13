from collections import deque

def solution():
    N, K = map(int, input().split(' '))

    # DP Cache: position_cache[pos] -> arriving time
    position_cache = [float('inf') for i in range(100_001)]

    dq = deque()
    dq.append((N, 0))

    min_sec = float('inf')

    while bool(dq):
        pos, sec = dq.popleft()

        if position_cache[pos] > sec:
            position_cache[pos] = sec

        # 늦은 도착시간 없애기
        if min_sec <= sec:
            continue

        # 도착한 경우
        if pos == K:
            min_sec = min(sec, min_sec)
            continue

        # 다음 위치
        next_left = pos - 1
        next_right = pos + 1
        next_jump = pos * 2

        # 좌, 우, 점프 이동
        if next_left >= 0:
            # 왼쪽으로 이동한 경우가 0보다 작은 경우 pass
            if sec < position_cache[next_left]:
                # 다음으로 이동할 위치에 이미 이전 시간에 도달한 경우 pass
                dq.append((next_left, sec + 1))

        if next_right <= 100_000:
            # 오른쪽으로 이동한 경우가 0보다 작은 경우 pass
            if sec < position_cache[next_right]:
                # 다음으로 이동할 위치에 이미 이전 시간에 도달한 경우 pass
                dq.append((next_right, sec + 1))

        if next_jump != 0 and next_jump <= 100_000:
            # 왼쪽으로 이동한 경우가 0보다 작은 경우 pass
            if sec < position_cache[next_jump]:
                # 다음으로 이동할 위치에 이미 이전 시간에 도달한 경우 pass
                dq.append((next_jump, sec + 1))

    # 최소 시간 출력
    print(min_sec)

    # 경로 역 추적
    route = list()

    # traceback second, traceback position
    tb_sec = min_sec - 1
    tb_pos = K

    while True:
        route.append(tb_pos)
        if tb_pos == N:
            break
        
        # 이전 위치
        prev_left = tb_pos - 1
        prev_right = tb_pos + 1
        if tb_pos % 2 != 0:
            prev_jump = -1
        else:
            prev_jump = tb_pos // 2

        if prev_left >= 0:
            if position_cache[prev_left] == tb_sec:
                tb_sec -= 1
                tb_pos = prev_left
                continue

        if prev_right <= 100_000:
            if position_cache[prev_right] == tb_sec:
                tb_sec -= 1
                tb_pos = prev_right
                continue

        if prev_jump != -1:
            if position_cache[prev_jump] == tb_sec:
                tb_sec -= 1
                tb_pos = prev_jump
                continue

    print(*route[::-1])

if __name__=="__main__":
    solution()