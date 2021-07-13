from collections import deque

def solution():
    N, K = map(int, input().split(' '))

    position_cache = [float('inf') for i in range(100_001)]

    dq = deque()
    dq.append((N, 0))   # position, second

    min_sec = float('inf')
    while bool(dq):
        pos, sec = dq.popleft()
        
        # 현재 위치에 대한 값 넣기
        position_cache[pos] = sec

        # 최소 시간보다 길 경우
        if min_sec <= sec:
            continue

        if pos == K:
            min_sec = min(min_sec, sec)
            continue

        # 다음 위치
        next_pos_right = pos + 1
        next_pos_left = pos - 1
        next_pos_jump = pos * 2

        # 다음 위치 탐색에 추가
        if next_pos_left >= 0:
            if sec < position_cache[next_pos_left]:
                dq.append((next_pos_left, sec + 1))

        if next_pos_right <= 100_000:
            if sec < position_cache[next_pos_right]:
                dq.append((next_pos_right, sec + 1))

        if next_pos_jump != 0 and next_pos_jump <= 100_000:
            if sec < position_cache[next_pos_jump]:
                dq.append((next_pos_jump, sec))

    print(min_sec)

if __name__=="__main__":
    solution()