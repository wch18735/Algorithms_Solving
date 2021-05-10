if __name__=="__main__":
    N, C = map(int, input().split(' '))

    # 무게 (index error 방지용 float('inf')
    weight_list = list(map(int, input().split(' ')))
    weight_list.sort(key=lambda x: x)
    weight_list = weight_list + [float('inf')]

    # 답 (경우의 수)
    answer = 1

    # 투 포인터
    left_pointer = 0
    right_pointer = 0
    napsack = weight_list[right_pointer]

    while right_pointer < N:
        if napsack <= C:
            answer += 1
            right_pointer += 1
            napsack += weight_list[right_pointer]
        else:
            napsack -= weight_list[left_pointer]
            left_pointer += 1

    print(answer)
