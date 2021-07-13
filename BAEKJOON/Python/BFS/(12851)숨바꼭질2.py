from collections import deque

def solution():
    N, K = map(int, input().split(' '))
    
    # 각 위치 값은 도착한 시간
    position_cache = [float('inf') for i in range(100_001)]

    # 최소 시간
    min_sec = float('inf')
    
    # 경우의 수 개수
    answer = 0

    # deque
    dq = deque()
    
    # dq 초기 값 -> (시간, 경우의 수, 수빈 위치)
    dq.append((0, N))
    
    # 탐색
    while bool(dq):
        sec, pos = dq.popleft()
        position_cache[pos] = sec

        if sec > min_sec:
            # 탐색 중인 과정의 시간이 최소 도달시간보다 길 때
            continue
        
        if pos == K:
            # 도달했을 때
            if sec < min_sec:
                # 도착시간이 더 짧을 경우
                min_sec = sec
                answer = 1
                continue
            elif sec == min_sec:
                # 정확한 도착시간일 때
                answer += 1
                continue

        # 다음 위치들
        next_pos_left = pos - 1
        next_pos_right = pos + 1
        next_pos_jump = pos * 2

        if next_pos_left >= 0:
            if position_cache[next_pos_left] > sec:
                dq.append((sec + 1, next_pos_left))

        if next_pos_right <= 100_000:
            if position_cache[next_pos_right] > sec:
                dq.append((sec + 1, next_pos_right))

        if next_pos_jump <= 100_000 and next_pos_right != 0:
            if position_cache[next_pos_jump] > sec:
                dq.append((sec + 1, next_pos_jump))

    print(min_sec)
    print(answer)
        
if __name__=="__main__":
    solution()