from math import floor

if __name__=="__main__":
    N = int(input())

    num_list = list(map(int, input().split(' ')))
    num_list.sort(key=lambda x: x)

    M = int(input())

    targets = list(map(int, input().split(' ')))

    for target in targets:
        left_point = 0
        right_point = len(num_list)

        # left most
        while left_point < right_point:
            middle_point = floor((left_point + right_point) / 2)

            if num_list[middle_point] < target:
                left_point = middle_point + 1
            else:
                right_point = middle_point

        left_most = left_point

        # 처음 left most를 이용해 있는지 확인
        if left_most == len(num_list) or num_list[left_most] != target:
            print(0, end=' ')
            continue

        left_point = 0
        right_point = len(num_list)

        # right most
        while left_point < right_point:
            middle_point = floor((left_point + right_point) / 2)

            if num_list[middle_point] <= target:
                left_point = middle_point + 1
            else:
                right_point = middle_point

        # right most
        right_most = right_point - 1

        # 개수 구하기
        print(right_most - left_most + 1, end=' ')
