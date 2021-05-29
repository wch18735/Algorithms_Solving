def solution(lottos, win_nums):
    answer = []

    zero_count = 0
    win_count = 0

    for num in lottos:
        if num == 0:
            zero_count += 1
            continue

        for w_num in win_nums:
            if num == w_num:
                win_count += 1

    best_score = min(6, zero_count + win_count)
    worst_score = win_count

    answer = [min(7 - best_score, 6), min(7 - win_count, 6)]

    return answer