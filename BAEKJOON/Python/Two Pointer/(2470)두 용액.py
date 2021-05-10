if __name__=="__main__":
    N = int(input())

    # 용액
    liquid_list = list(map(int, input().split(' ')))

    # 정렬
    liquid_list.sort(key=lambda x: x)

    left_pointer = 0
    right_pointer = len(liquid_list) - 1

    # 최대 값
    INF = 2 << 31
    min_rate = INF

    # 최소 쌍
    minimum_pair = [left_pointer, right_pointer]

    while left_pointer < right_pointer:
        # 용액 합성
        acid_rate = liquid_list[left_pointer] + liquid_list[right_pointer]

        if acid_rate == 0:
            minimum_pair[0] = liquid_list[left_pointer]
            minimum_pair[1] = liquid_list[right_pointer]
            break
        elif acid_rate < 0:
            if abs(acid_rate) < min_rate:
                min_rate = abs(acid_rate)
                minimum_pair[0] = liquid_list[left_pointer]
                minimum_pair[1] = liquid_list[right_pointer]
            left_pointer += 1
        elif acid_rate > 0:
            if abs(acid_rate) < min_rate:
                min_rate = abs(acid_rate)
                minimum_pair[0] = liquid_list[left_pointer]
                minimum_pair[1] = liquid_list[right_pointer]
            right_pointer -= 1

    print(*minimum_pair)