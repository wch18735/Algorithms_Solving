T = int(input())

def find_min_t(dis):
    # teleport count
    count = [0, 0]

    # dis <= n*(n+1)
    # dis <= k**2

    k = 1
    while True:  # case1
        if dis < k ** 2:
            break
        k += 1

    n = 1
    while True:  # case2
        if dis < n * (n + 1):
            break
        n += 1

    # case1
    # 거리: (k-1)^2 -> 2*(k-1)-1 회 이동
    # count = dis-(k-1)**2 + 2*(k-1) - 1
    if dis - (k-1)**2 >= 4:
        count[0] += 2 * (k - 1) - 1 + find_min_t(dis-(k-1)**2)
        print(dis - (k-1)**2)
    else:
        count[0] += dis - (k - 1) ** 2 + 2 * (k - 1) - 1

    # case2
    # 거리: (n-1)*n -> 2*(n-1)회 이동
    # count = dis - (n-1)*n + 2*(n-1)
    if dis - (n - 1)*n >= 6:
        count[1] += 2 * (n - 1) + find_min_t(dis - (n - 1) * n)
    else:
        count[1] += dis - (n - 1) * n + 2 * (n - 1)

    return min(count)


for _ in range(T):
    x,y = map(int,input().split())

    # distance
    dis = y - x

    print(find_min_t(dis))
