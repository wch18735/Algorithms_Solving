# input
M,N = map(int,input().split())

# tomato map
tomato = [[x for x in map(int,input().split())] for _ in range(N)]

# deque for bfs
from collections import deque
dq = deque()

# initial check
for i in range(N):
    for j in range(M):
        if tomato[i][j] == 1:
            dq.append([i,j])

# diriection
dx = [1,0,-1,0]
dy = [0,1,0,-1]

day = -1
while(bool(dq)):
    dq_size = len(dq)

    for _ in range(dq_size):
        x, y = dq.popleft()

        for i in range(4):
            tmp_x = x + dx[i]
            tmp_y = y + dy[i]

            if tmp_x < 0 or N <= tmp_x: continue
            if tmp_y < 0 or M <= tmp_y: continue
            if tomato[tmp_x][tmp_y] != 0: continue

            dq.append([tmp_x, tmp_y])
            tomato[tmp_x][tmp_y] = 1

    # for idx_x in range(N):
    #     for idx_y in range(M):
    #         print(tomato[idx_x][idx_y], end=' ')
    #     print()
    # print()

    day += 1

minus = False
for i in range(N):
    for j in range(M):
        if tomato[i][j] == 0:
            minus = True

if minus:
    print(-1)
else:
    print(day)