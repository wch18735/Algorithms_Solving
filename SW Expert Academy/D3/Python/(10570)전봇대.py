if __name__=="__main__":
    T = int(input())

    for test_case in range(1, T + 1):
        N = int(input())

        lines = []
        for _ in range(N):
            a, b = map(int, input().split(' '))
            lines.append((a, b))

        answer = 0
        lines_length = len(lines)
        for i in range(lines_length):
            for j in range(lines_length):
                if i == j:
                    continue

                if (lines[i][0] - lines[j][0]) * (lines[i][1] - lines[j][1]) < 0:
                    answer += 1

        answer = answer // 2

        print("#{} {}".format(test_case, answer))
