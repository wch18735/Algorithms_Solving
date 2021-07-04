def solution():
    T = int(input())

    for test_case in range(1, T + 1):
        p, q = map(float, input().split(" "))

        # 처음 USB를 올바르게 꽂고, 정상적으로 꼽을 때
        s1 = (1 - p) * q

        # 뒤집어서 꽂고 그 다음 정상적으로 꼽을 때
        s2 = p * (1 - q) * q

        if s1 < s2:
            print("#{} {}".format(test_case, "YES"))
        else:
            print("#{} {}".format(test_case, "NO"))

if __name__=="__main__":
    solution()