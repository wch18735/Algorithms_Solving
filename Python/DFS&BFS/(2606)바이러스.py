# # input txt
# f = open('./input.txt')
# N = int(f.readline())
# K = int(f.readline())
N = int(input())
K = int(input())

adj_list = [list() for _ in range(N+1)]

for _ in range(K):
    x,y = map(int,input().split())
    adj_list[x].append(y)
    adj_list[y].append(x)

chk = [False]*(N+1)

def dfs(node):
    chk[node] = True

    for n in adj_list[node]:
        if chk[n] == False: # 탐색하지 않은 곳
            dfs(n)

dfs(1)

count = 0
for i in chk:
    if i == True: count +=1

print(count-1)