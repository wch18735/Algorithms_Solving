import queue

N = int(input())
dq = queue.deque()

# a,b 선언
a = 0
b = 0

while N - 3*b >= 0:
    # N 이 3의 배수
    if (N-3*b) == 0:
        dq.append((0,b))
    # N 이 5a + 3b 형태일 때 (a,b는 정수)
    elif (N-3*b) % 5 == 0:
        dq.append(((N-3*b)//5,b))
    # End
    b += 1

    if bool(dq):
        x,y = dq.popleft()
        dq.append((x,y))
        print(x+y)
        break

if not bool(dq):
    print(-1)