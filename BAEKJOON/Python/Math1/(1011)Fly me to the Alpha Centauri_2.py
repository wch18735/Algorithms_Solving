T = int(input())

for _ in range(T):
    x,y = map(int, input().split())

    # distance: y-x (y > x)
    dis = y-x-1
    count = 1 # 이미 1은 한 번 count
    n = 1

    if dis == 0:
        print(1)
    else:
        while True:
            # print("남은 거리 = ", dis, "이전 이동 = ", n, end=" ")

            # 이동 경우의 수는 세 가지
            # 1) dis -= n-1 or n or n+1
            # 2) n은 증가, 유지, 감소
            # 이 순서 지켜줘야함

            # 증가 가능
            if dis - (n+1) >= int(n*(n+1)/2):
                dis -= (n+1)
                n += 1
                count += 1
            # 유지
            elif dis - n >= int((n-1)*n/2):
                dis -= n
                count += 1
            # 감소
            elif dis - (n-1) >= int((n-2)*(n-1)/2):
                dis -= (n-1)
                n -= 1
                count += 1

            # print("다음 이동 = ", n)

            if dis == 0:
                break

        print(count)

# 경계조건 해석 주의 문제!!
# y-x = 1 이 바로 주어지는 경우도 생각!!
# Step마다 판단