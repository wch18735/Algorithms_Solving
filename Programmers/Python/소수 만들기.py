from math import sqrt
from itertools import combinations


def solution(nums):
    answer = 0

    # 소수 최대 값 계산
    nums.sort(key=lambda x: x)
    max_num = sum(nums[-3:])

    # 에라토스테네스 체 만들기
    era = [True for _ in range(max_num + 1)]
    era[0], era[1] = False, False

    for idx in range(2, int(sqrt(max_num + 1)) + 1):
        if era[idx] is False:
            continue

        step = 2
        while idx * step <= max_num:
            era[idx * step] = False
            step += 1

    for t in list(combinations(nums, 3)):
        if era[sum(t)] == True:
            answer += 1

    return answer