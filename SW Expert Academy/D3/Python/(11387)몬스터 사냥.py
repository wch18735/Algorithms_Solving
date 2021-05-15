T = int(input())

for test_case in range(1, T + 1):
    D, L, N = map(int, input().split(' '))

    # 데미지 총 합
    total_d = 0

    # 데미지 계산
    for n in range(N):
        total_d += D * (1 + n * L / 100)

    # 출력
    print('#' + str(test_case) + ' ' + str(int(total_d)))