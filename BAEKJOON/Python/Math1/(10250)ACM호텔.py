T = int(input())

for i in range(T):
    H,W,N = map(int,input().split())
    # flour|room_num
    if N % H == 0:
        room_num = N//H
        flour = H
    else:
        room_num = N//H+1
        flour = N-(N//H)*H

    print(flour,end="")
    if room_num < 10:
        print(0,end='')
        print(room_num)
    else:
        print(room_num)

# W는 쓰지도 않음
