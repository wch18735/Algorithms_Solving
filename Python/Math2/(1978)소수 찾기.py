import math

T = int(input())

def check_prime(N):
    if N == 1: # 1이 아닌 양수 조건
        return 0
    
    n = int(math.sqrt(N))

    while n >= 2:
        if N%n == 0:
            return 0
        n -= 1

    return 1

numbers = list(map(int,input().split()))
count = 0

for i in range(T):
    if check_prime(numbers[i]) == 1:
        count += 1

print(count)
