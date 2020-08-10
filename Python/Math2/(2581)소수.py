import math

M = int(input())
N = int(input())

def check_prime(Num):
    if Num == 1:
        return 0
    # int() 로 바꿔주는 작업 중요
    n = int(math.sqrt(Num))
    
    while n >= 2:
        if Num % n == 0:
            return 0
        n -= 1
    return 1

first_prime = 0
sum = 0

for i in range(M,N+1):
    if check_prime(i) == 1:
        if sum == 0:
            first_prime = i
        sum += i

if sum == 0:
    print(-1)
else:
    print(sum)
    print(first_prime)