if __name__=="__main__":
    T = int(input())

    for test_case in range(1, T + 1):
        N, A, B = map(int, input().split(' '))

        print("#{} {} {}".format(test_case, min(A, B), max(0, A + B - N)))
