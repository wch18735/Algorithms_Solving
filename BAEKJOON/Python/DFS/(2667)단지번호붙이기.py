# # input txt
# f = open('./input.txt')

# # Map size
# N = int(f.readline())
# MAP = [[int(i) for i in f.readline() if i != '\n'] for _ in range(N)]

# Map input
N = int(input())
MAP = [[int(i) for i in input() if i != '\n'] for _ in range(N)]
DMAP = [[False for i in range(N)] for j in range(N)]

# MAP setting
for i in range(N):
    for j in range(N):
        if MAP[i][j] == 1:
            DMAP[i][j] = True

# 방향
dx = [1,0,-1,0]
dy = [0,1,0,-1]

import queue
dq = queue.deque()

# dfs
# DMAP이 True 인 곳을 탐색하며 단지 번호 D로 초기화함

def map_print(li):
    for line in li:
        print(line)
    print('\n\n')

def dfs(point):
    x,y = point
    if MAP[x][y] != 0:
        DMAP[x][y] = D

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= N : continue  # x 범위 벗어남
        if ny < 0 or ny >= N : continue  # y 범위 벗어남
        if DMAP[nx][ny] is not True: continue # 건물이 없거나 탐색한 곳인 경우
        if MAP[nx][ny] == 0: continue # 벽인 경우

        dfs([nx,ny])

# D = 0
D = 0

for i in range(N):
    for j in range(N):
        if DMAP[i][j] is not True: continue # 탐색했던 경우
        if MAP[i][j] == 0: continue # 벽이면 continue
        D += 1
        dfs([i,j])

# 단지 수 세기
d_list = [0] * (D+1)
for i in range(N):
    for j in range(N):
        if DMAP[i][j] is not False:
            d_list[DMAP[i][j]] += 1

# Sorting
d_list.sort()

# 정답 print
print(D)
for i in d_list[1:]:
    print(i)

# if nx < 0 or nx >= N 조건을 and 로 썼음
# 그러면 -1이 통과하는데 list에서는 -1 index를 맨 끝으로 생각함