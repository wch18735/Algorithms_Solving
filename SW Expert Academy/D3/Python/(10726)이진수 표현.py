if __name__=="__main__":
    T = int(input())

    for test_case in range(1, T + 1):
        # M을 이진수로 나타냈을 때,
        # 끝의 N 자리가 모두 1인지 확인
        N, M = map(int, input().split(' '))
        
        # N 자리가 모두 1로 채워짐
        K = (1 << N) - 1

        if M & K == K:
            print("#{} ON".format(test_case))
        else:
            print("#{} OFF".format(test_case))