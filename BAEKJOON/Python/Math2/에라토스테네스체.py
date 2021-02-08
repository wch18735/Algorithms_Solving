import math

M,N = map(int, input().split())

era = [i for i in range(N+1)]
era[0] = False
era[1] = False

n = int(math.sqrt(N))
i = 2

while True:
    if era[i] == False:
        i += 1
        continue

    t = 2

    while i*t <= N:
        era[i*t] = False
        t += 1

    if i > n:
        break

    i += 1

for i in range(M, N+1):
    if era[i] != False:
        print(i)
