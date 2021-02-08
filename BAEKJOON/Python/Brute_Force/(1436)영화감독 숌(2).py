N = int(input())
num = 666

while True:
    if (str(666) in str(num)):
        N -= 1

    if N == 0:
        break

    num += 1

print(num)

# 제일 황당한 문제
# 그냥 0부터 증가시키면서 666이 있을 때마다 N = N-1
# N == 0이 됐을 때의 num을 출력