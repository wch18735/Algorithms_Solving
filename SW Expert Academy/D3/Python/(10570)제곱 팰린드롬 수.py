def check_palindrome(num):
    num = str(num)

    left_idx = 0
    right_idx = len(num) - 1

    while left_idx <= right_idx:
        if num[left_idx] == num[right_idx]:
            left_idx += 1
            right_idx -= 1
            continue
        else:
            return False
    return True

if __name__=="__main__":
    T = int(input())

    SQRT_DP = [0 for i in range(1001)]

    i = 1
    while i * i <= 1000:
        SQRT_DP[i * i] = i
        i += 1

    for test_case in range(1, T+1):
        A, B = map(int, input().split(' '))

        answer = 0
        for num in range(A, B + 1):
            if SQRT_DP[num] == 0:
                # 제곱수가 아닌 경우
                continue

            if check_palindrome(num):
                if check_palindrome(SQRT_DP[num]):
                    answer += 1
                else:
                    continue
            else:
                continue

        print("#{} {}".format(test_case, answer))
