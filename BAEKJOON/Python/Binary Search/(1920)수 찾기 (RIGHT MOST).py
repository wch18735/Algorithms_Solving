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

    # Right Most 구하는 방식
    for target_number in target_list:

        left_point = 0
        right_point = len(num_list)

        while left_point < right_point:
            # 항상 floor()로 짝수일 때 왼쪽을 가리키게 함
            # L <- M + 1
            # R <- M
            middle_point = floor((left_point + right_point) / 2)

            # 가장 단순한 상황에서 Right Most 이기 때문에 L이 움직이도록 설정
            if num_list[middle_point] <= target_number:
                left_point = middle_point + 1
            else:
                right_point = middle_point

        if num_list[right_point - 1] == target_number:
            print(1)
        else:
            print(0)