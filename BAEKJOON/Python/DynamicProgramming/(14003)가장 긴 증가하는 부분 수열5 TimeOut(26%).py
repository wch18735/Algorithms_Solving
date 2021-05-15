from math import floor
from collections import deque
import sys
input = sys.stdin.readline

def greater_equal(lis_dp, target):
    L = 0
    R = len(lis_dp)

    while L < R:
        M = floor((L + R)/2)

        if lis_dp[M] <= target:
            L = M + 1
        else:
            R = M

    if R == 0:
        return 0
    elif lis_dp[R-1] == target:
        return R - 1
    else:
        return R

if __name__=="__main__":
    N = int(input().strip())

    num_arr = list(map(int, input().split(' ')))

    # longest increasing sequence cache
    lis_dp = []

    # [element, possible index in lis] pair dp
    pair_dp = [[e, float('inf')] for e in num_arr]

    # cache update
    for idx, e in enumerate(num_arr):
        if len(lis_dp) == 0:
            lis_dp.append(e)
            pair_dp[idx][1] = 0
            continue

        if lis_dp[-1] < e:
            lis_dp.append(e)
            pair_dp[idx][1] = len(lis_dp) - 1

        elif lis_dp[-1] == e:
            continue
        else:
            index_in_lis = greater_equal(lis_dp, e)

            # insert possible pos to lis
            lis_dp[index_in_lis] = e

            # pair update
            pair_dp[idx][1] = index_in_lis

    # length of lis
    print(len(lis_dp))

    answer = deque()
    start_idx = len(pair_dp) - 1
    for l in range(len(lis_dp), -1, -1):
        index_offset = 0
        for e, idx in pair_dp[start_idx::-1]:
            if idx + 1 == l:
                answer.appendleft(e)
                index_offset += 1
                break
            index_offset += 1
        start_idx -= index_offset

    print(*answer)