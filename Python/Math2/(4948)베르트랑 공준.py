# 에라토스테네스의 체로 풀기

while True:
    n = int(input())
    if n == 0:
        break

    count = 0

    era = [i for i in range(2*n+1)]
    era[0] = era[1] = False

    i = 2

    while i <= 2*n:
        if era[i] == False:
            i += 1
            continue
        else:
            if i > n:
                count += 1
            t = 2
            while i*t <= 2*n:
                era[i*t] = False
                t += 1
            i += 1

    print(count)