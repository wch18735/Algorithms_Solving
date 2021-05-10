if __name__=="__main__":
    N = int(input())

    # 에라토스테네스 체
    era_che = [True for _ in range(N + 1)]
    era_che[0], era_che[1] = False, False

    # 소수 시작
    num = 2

    # 에라토스테네스 체
    while num * num <= N:
        idx = 2
        while num * idx <= N:
            era_che[num * idx] = False
            idx += 1
        num += 1

    # 소수만 모으기 (index error 방지용 float('inf'))
    era_che = [idx for idx, chk in enumerate(era_che) if chk is True] + [float('inf')]

    # 부분합 경우의 수 계산
    start_pointer = 0
    end_pointer = 0
    partial_sum = era_che[end_pointer]

    # 답
    answer = 0

    while end_pointer < len(era_che) - 1:
        if partial_sum < N:
            end_pointer += 1
            partial_sum += era_che[end_pointer]
        elif partial_sum == N:
            answer += 1
            partial_sum -= era_che[start_pointer]
            start_pointer += 1
        else:
            partial_sum -= era_che[start_pointer]
            start_pointer += 1

    print(answer)
