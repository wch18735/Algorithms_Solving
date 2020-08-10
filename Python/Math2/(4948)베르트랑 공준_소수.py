import math

def check_prime(N):
    if N <= 1:
        return 0

    root_N = int(math.sqrt(N))

    while root_N >= 2:
        if N % root_N == 0:
            return 0
        root_N -= 1

    return 1

while True:
    n = int(input())
    if n == 0:
        break

    count = 0
    for i in range(n+1, 2*n+1):
        if check_prime(i) == 1:
            count += 1

    print(count)
