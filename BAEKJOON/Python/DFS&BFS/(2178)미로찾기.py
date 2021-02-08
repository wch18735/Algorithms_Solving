# # input with txt
# f = open('./input.txt')
# N,M = map(int,f.readline().split())
# maze_map = [[int(i) for i in f.readline() if i is not '\n'] for _ in range(N)]

import queue

# input with online
N,M = map(int, input().split())
maze_map = [[int(i) for i in input() if i != '\n'] for _ in range(N)]
chk = [[0 for _ in range(M)] for _ in range(N)]

# directtion
drow = [-1, 0, 1, 0]
dcol = [0, 1, 0, -1]

node = [0,0]
dq = queue.deque()

def bfs(node):
    row,col = node
    dq.append(node)
    chk[row][col] = 1

    while bool(dq):
        row, col = dq.popleft()

        for i in range(4):
            nrow = row + drow[i]
            ncol = col + dcol[i]

            if nrow < 0 or nrow >= N: continue
            if ncol < 0 or ncol >= M: continue
            if maze_map[nrow][ncol] == 0 : continue
            if chk[nrow][ncol] != 0 : continue

            dq.append([nrow,ncol])
            chk[nrow][ncol] = chk[row][col]+1

    print(chk[N-1][M-1])

bfs(node)