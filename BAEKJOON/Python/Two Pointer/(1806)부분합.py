if __name__=="__main__":
    N, S = map(int, input().split(' '))

    # index error 방지용 [0]
    num_list = list(map(int, input().split(' '))) + [0]

    start_pointer = 0
    end_pointer = 0
    partial_sum = num_list[start_pointer]

    answer = 2 << 31

    while end_pointer < N:
        if partial_sum < S:
            end_pointer += 1
            partial_sum += num_list[end_pointer]
        else:
            answer = min(answer, end_pointer - start_pointer + 1)
            partial_sum -= num_list[start_pointer]
            start_pointer += 1

    if answer == 2 << 31:
        print(0)
    else:
        print(answer)
