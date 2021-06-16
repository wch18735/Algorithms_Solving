if __name__=="__main__":
    T = int(input())

    for test_case in range(1, T + 1):
        N = int(input())

        numList = list(map(float, input().split(' ')))

        avg = sum(numList) // N

        answer = 0
        for n in numList:
            if avg >= n:
                answer += 1

        print("#{} {}".format(test_case, answer))