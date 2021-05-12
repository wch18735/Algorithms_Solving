from math import floor

if __name__=="__main__":
    N = int(input())

    # number list
    num_list = list(map(int, input().split(' ')))
    num_list.sort(key=lambda x: x)

    # 타겟 개수
    M = int(input())

    # 타겟 리스트
    target_list = list(map(int, input().split(' ')))

    # Left Most 구하는 방식
    for target_number in target_list:

        left_point = 0
        right_point = len(num_list)

        while left_point < right_point:
            # 항상 floor로 짝수일 때 왼쪽을 가리키게 함
            # L <- M + 1
            # R <- M
            middle_point = floor((left_point + right_point) / 2)

            # 가장 기초적인 상황에서 Left Most 이기 때문에 R이 움직이도록 설정
            if num_list[middle_point] < target_number:
                left_point = middle_point + 1
            else:
                right_point = middle_point


        if left_point == len(num_list):
            # 타깃 값이 매우 커서 없을 때
            print(0)
        else:
            if num_list[left_point] == target_number:
                print(1)
            else:
                print(0)