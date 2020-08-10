T = int(input())

for _ in range(T):
    K = int(input())
    N = int(input())

    li = [i+1 for i in range(N)]

    for i in range(K):
        for j in range(1,N):
            li[j] = li[j-1]+li[j]

    print(li[N-1])