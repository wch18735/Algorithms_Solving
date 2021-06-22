if __name__=="__main__":
    T = int(input())

    for test_case in range(1, T + 1):
        N, K = map(int, input().strip().split(' '))

        if N % K == 0:
            print("#{} {}".format(test_case, 0))
        else:
            print("#{} {}".format(test_case, 1))