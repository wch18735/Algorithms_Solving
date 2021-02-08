# input
N,M,V = map(int, input().split())
inarr = [list(map(int, input().split())) for _ in range(M)]
chk = [False] * (N+1)

# DFS&BFS (Depth First Search)
# adjacency list
a = [[] for _ in range(N+1)]

for x,y in inarr:
    a[x].append(y)
    a[y].append(x)

for i in range(1,N+1):
    a[i].sort()

def dfs(node):
    chk[node] = True
    print(node, end=' ')

    for i in a[node]:
        if chk[i] is not True:
            dfs(i)

dfs(V)

# BFS (Beadth First Search)
for i in range(len(chk)):
    chk[i] = False

import queue
dq = queue.deque()

def bfs(node):
    dq.append(node)
    chk[node] = True

    while bool(dq):
        t = dq.popleft()
        print(t, end=' ')

        for i in a[t]:
            if chk[i] is not True:
                # "dq.append -> search" so chk[i] = true
                dq.append(i)
                chk[i] = True
print()
bfs(V)