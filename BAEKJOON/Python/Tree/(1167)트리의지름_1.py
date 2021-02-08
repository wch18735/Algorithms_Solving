# # input txt
# f = open('./input.txt')
# V = int(f.readline())
# adj_list = [list() for _ in range(V+1)]
#
# for i in range(V):
#     node, *li = map(int,f.readline().replace('\n','').split(' '))
#     li.remove(-1)
#     for j in range(0,len(li),2):
#         adj_list[node].append([li[j], li[j+1]])

# input online
V = int(input())
adj_list = [list() for _ in range(V+1)]

for _ in range(V):
    node, *li = map(int,input().split())
    li.remove(-1)
    for j in range(0, len(li), 2):
        # 연결된 node와 weight을 담고 있는 인접행렬
        adj_list[node].append([li[j], li[j + 1]])

import queue
dq = queue.deque()

def bfs(node):
    # 거리 dist
    dist = [0] * (V+1)

    # 자기 자신과 0번째 idx는 -1 로 초기화
    dist[0] = -1
    dist[node] = -1

    # 입력된 node를 queue에 추가
    dq.append(node)

    # Search
    while bool(dq):
        i = dq.popleft()
        for n, w in adj_list[i]:
            if dist[n] != 0: continue # 방문했음

            # if i == 1:  # 1일 때는 식별거리 -1을 해주기 때문에 구분
            #     dq.append(n)
            #     dist[n] += w
            # else: # 나머지는 node에서부터 i node까지 거리 dist[i]를 더해줌
            # 이 부분을 처음 return 시 +1 해주는 것으로 수정

            dq.append(n)
            dist[n] += dist[i] + w

    return [d+1 for d in dist] # node로부터 weight만큼 얼마나 떨어졌는지 계산


# 최대 거리인 노드에서 최대거리를 구하기
first_dist = bfs(1)
max_idx = first_dist.index(max(first_dist))
second_dist = bfs(max_idx)
print(max(second_dist))

# list().index(element): element가 있는 index를 반환한다
# element = max(list) 이면 최대 index
# m = max(list) 일 때, i for i,j in enumerate(list) if j == m 으로 최대 index 모두 찾을 수 있음
