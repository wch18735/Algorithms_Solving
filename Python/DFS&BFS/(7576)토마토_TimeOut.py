# M: 가로, N: 세로
M,N = map(int,input().split())

# tomato location
tomato = [[x for x in map(int,input().split())] for i in range(N)]

# day
day = [[-1 for i in range(M)] for j in range(N)]

# direction (anti-clockwise)
dx = [1,0,-1,0]
dy = [0,1,0,-1]

# dqeue
from collections import deque

dq = deque()

for i in range(N):
    for j in range(M):
        if tomato[i][j] == 0 or tomato[i][j] == -1: continue

        # visit check : 1 is visited
        # 매 익은 토마토마다 방문 chk가 필요함
        chk = [[0 for _ in range(M)] for __ in range(N)]

        # visit the point
        dq.append([i,j])
        chk[i][j] = 1
        day[i][j] = 0

        # bfs loop
        while(bool(dq)):
            x, y = dq.popleft()

            for k in range(4):
                tmp_x = x + dx[k]
                tmp_y = y + dy[k]

                if tmp_x < 0 or N <= tmp_x: continue    # 세로 경계조건
                if tmp_y < 0 or M <= tmp_y: continue    # 가로 경계조건
                if tomato[tmp_x][tmp_y] == -1: continue # 벽 경계조건
                if chk[tmp_x][tmp_y] == 1: continue     # 방문조건
                if day[tmp_x][tmp_y] <= day[x][y] and day[tmp_x][tmp_y] != -1: continue # 익는 날짜 선행 조건

                chk[tmp_x][tmp_y] = 1
                day[tmp_x][tmp_y] = day[x][y] + 1
                dq.append([tmp_x, tmp_y])

                # for idx_x in range(N):
                #     for idx_y in range(M):
                #         print(day[idx_x][idx_y], end=' ')
                #     print()
                # print()

li = []
for i in range(N):
    for j in range(M):
        if tomato[i][j] != -1: # 빈 공간이 아닐 때
            li.append(day[i][j])

if len(li) == 0: print(-1)
else:
    if min(li) == -1: print(-1)
    else: print(max(li))