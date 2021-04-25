T = int(input())

for test_case in range(1, T+1):
    t_num = int(input())

    # 성적 리스트
    score_list = list(map(int, input().strip().split(' ')))

    # 분포
    distribution_list = [0 for i in range(0, 101)]

    for s in score_list:
        distribution_list[s] += 1

    max_val = max(distribution_list)
    answer_list = []
    for score, val in enumerate(distribution_list):
        if val == max_val:
            answer_list.append(score)

    print(f'#{t_num} {answer_list[-1]}')