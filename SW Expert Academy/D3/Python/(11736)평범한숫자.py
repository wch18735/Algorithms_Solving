def solution():
    T = int(input())

    for test_case in range(1, T + 1):
        # length of integer sequence
        N = int(input())

        # number list
        num_list = list(map(int, input().split(' ')))

        answer = 0
        for idx in range(1, len(num_list) - 1):
            if (num_list[idx - 1] - num_list[idx]) * (num_list[idx + 1] - num_list[idx]) < 0:
                answer += 1

        print("#{} {}".format(test_case, answer))


if __name__=="__main__":
    solution()