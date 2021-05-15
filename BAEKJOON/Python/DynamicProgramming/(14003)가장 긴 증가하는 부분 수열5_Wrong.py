from math import floor
from collections import deque

def right_greater_equal(arr, t):
    L = 0
    R = len(arr)

    while L < R:
        M = floor((L + R) / 2)
        
        # left가 움직이는 경우 -> arr[M] < t 일 때
        if arr[M] <= t:
            L = M+1
        else:
            R = M

    if R == 0:
        # target 이 가장 작은 상황일 때
        return 0

    elif arr[R-1] == t:
        # target 값과 같은 원소가 배열에 존재할 때
        return R - 1
    else:
        # target 값이 존재하지 않을 때
        # target 보다 큰 가장 작은 정수 위치 반환
        return R

if __name__=="__main__":
    N = int(input())

    num_arr = [-float('inf')] + list(map(int, input().split(' ')))

    # position
    dp_pos =[[a, 0] for a in num_arr]
    dp = [num_arr[1]]
    dp_pos[1][1] = 1

    for i in range(2, N+1):
        if dp[-1] < num_arr[i]:
            # 가장 끝에 배열 저장
            dp.append(num_arr[i])

            # 현재 원소가 수열에서 위치할 수 있는 위치
            dp_pos[i][1] = len(dp)
        elif dp[-1] == num_arr[i]:
            continue
        else:
            # dp 배열에서 위치할 수 있는 인덱스
            idx = right_greater_equal(dp, num_arr[i])

            dp[idx] = num_arr[i]
            dp_pos[i][1] = idx

        print(dp)

    # 최장 수열의 길이
    print(len(dp))

    # 실제 최장 증가 길이 부분 수열
    answer = deque()

    print(dp_pos)

    # 오른쪽 경계
    limit_idx = len(dp_pos)
    for seq_len in range(len(dp), 0, -1):
        i = 0
        for v, idx in dp_pos[limit_idx::-1]:
            if idx == seq_len:
                answer.appendleft(v)
                break
            else:
                i += 1
        limit_idx -= i

    # 구해진 최장 수열
    print(*answer)
