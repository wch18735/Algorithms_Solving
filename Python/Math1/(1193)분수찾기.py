X=int(input())

N = 0
while True:
    if X <= int(N*(N+1)/2):
        break
    else:
        N +=1

init = N
redundancy = X - int((N-1)*N/2) - 1

if N % 2 == 1:
    numerator = init
    denominator = 1
    print(numerator-redundancy,end="")
    print("/",end="")
    print(denominator+redundancy,end="")
else:
    denominator = init
    numerator = 1
    print(numerator + redundancy, end="")
    print("/", end="")
    print(denominator - redundancy, end="")