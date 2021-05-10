from itertools import combinations
from math import floor, ceil

if __name__=="__main__":
    N, C = map(int, input().split(' '))

    weights = list(map(int, input().split(' ')))

    list_A = weights[:ceil(N/2)]
    list_B = weights[ceil(N/2):]

    # 리스트 길이 (원소 개수)
    len_A = len(list_A)
    len_B = len(list_B)

    # 부분 집합 합
    subset_a = []
    subset_b = []

    for num in range(len_A + 1):
        for sub_set in combinations(list_A, num):
            subset_a.append(sum(sub_set))

    for num in range(len_B + 1):
        for sub_set in combinations(list_B, num):
            subset_b.append(sum(sub_set))

    # list_A 오름차순 정렬
    subset_a.sort(key=lambda x: x)

    # 답
    answer = 0

    # 정렬된 요소에 이분탐색 시행
    for element_b in subset_b:
        # 용량보다 큰 경우
        if element_b > C:
            continue

        # 이분 탐색
        left_idx = 0
        right_idx = len(subset_a)

        # 값을 만족하는 rightmost
        while left_idx < right_idx:
            mid = floor((left_idx + right_idx) / 2)
            if element_b + subset_a[mid] > C:
                right_idx = mid
            else:
                left_idx = mid + 1

        # right_idx -> 개수
        answer += right_idx


    # 총 경우의 수
    print(answer)
