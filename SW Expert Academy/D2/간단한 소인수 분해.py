T = int(input())

for test_case in range(1,T+1):
    num = int(input())
    denominator = [2, 3, 5, 7, 11]

    print(f'#{test_case}', end=' ')

    num_idx = 0
    while num_idx < 5:
        d = denominator[num_idx]

        cnt = 0
        while num % d == 0:
            cnt += 1
            num //= d

        print(cnt, end=' ')
        num_idx += 1
    print()