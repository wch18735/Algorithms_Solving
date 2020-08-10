
# if True:
#     # input txt
#     f = open('./input.txt')
#     N = int(f.readline())
#     inarr = [list(map(int,f.readline().split())) for _ in range(N-1)]

N = int(input())
inarr = [list(map(int,input().split())) for _ in range(N-1)]

import queue
dq = queue.deque()

par = [0] * (N+1)
par[1] = -1
adj_map = [[] for _ in range(N+1)]

# adjecent list
for x,y in inarr:
    adj_map[x].append(y)
    adj_map[y].append(x)

def bfs(node): # to make parent list
    dq.append(node)

    while bool(dq):
        root = dq.popleft()
        for i in adj_map[root]:
            if par[i] == 0: # if not searched
                par[i] = root
                dq.append(i)
            else: continue

bfs(1)
for i in par[2:]:
    print(i)
