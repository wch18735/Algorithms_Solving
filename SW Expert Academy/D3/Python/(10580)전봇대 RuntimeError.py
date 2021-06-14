from bisect import bisect_left

def main():
    T = int(input())

    for test_case in range(1, T + 1):
        N = int(input())

        L = []

        for _ in range(N):
            a, b = map(int, input().strip().split(' '))
            L.append((a, b))

        # 오름차순으로 정리
        L.sort(key=lambda x: x[0])
        Line = list(zip(*L))[1]

        # LIS 찾기
        LIS = []
        DP = [-1 for i in range(len(Line))]

        for idx, element in enumerate(Line):
            if len(LIS) == 0:
                # 비어있는 경우
                LIS.append(element)
                DP[idx] = 0
            else:
                if LIS[-1] < element:
                    # LIS 마지막에 추가
                    DP[idx] = len(LIS)
                    LIS.append(element)
                else:
                    # 삽입될 위치를 찾음
                    pos = bisect_left(Line, element)
                    DP[idx] = pos
                    LIS[pos] = element

        num = len(LIS) - 1

        DP = DP[::-1]
        for idx, elem in enumerate(DP):
            if elem == num:
                DP[idx] = -1
                num -= 1
        DP = DP[::-1]

        answer = 0
        dp_length = len(DP)
        for idx, elem in enumerate(DP):
            if elem != -1:
                answer += dp_length - (idx + 1)

        print("#{} {}".format(test_case, answer))
                    
if __name__=="__main__":
    main()
