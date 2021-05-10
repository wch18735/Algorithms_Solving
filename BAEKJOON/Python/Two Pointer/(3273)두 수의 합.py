if __name__=="__main__":
    N = int(input())

    num_list = list(map(int, input().split(' ')))
    num_list.sort(key=lambda x: x)

    start_pointer = 0
    end_pointer = len(num_list) - 1

    target_num = int(input())

    answer = 0

    while start_pointer < end_pointer:
        # 두 수 쌍 합 구하기
        partial_sum = num_list[start_pointer] + num_list[end_pointer]

        # 판단
        # 서로 다르기 때문에 다음 수가 같은 것인지 판단할 필요 없음
        if partial_sum < target_num:
            start_pointer += 1
        elif partial_sum == target_num:
            answer += 1
            start_pointer += 1
            end_pointer -= 1
        elif partial_sum > target_num:
            end_pointer -= 1

    print(answer)