# # input text
# f = open('./input.txt')
# N = int(f.readline())

N = int(input())

# 인접행렬 선언
adj_list = [list() for _ in range(N+1)]

for _ in range(N-1):
    p_node, c_node, d = map(int, input().split())
    adj_list[p_node].append([c_node, d])
    adj_list[c_node].append([p_node, d])

# # input txt
# for _ in range(N-1):
#     p_node, c_node, d = map(int, f.readline().split())
#     adj_list[p_node].append([c_node, d])
#     adj_list[c_node].append([p_node, d])


# queue(deque) 선언
import queue
dq = queue.deque()

def bfs(node):
    # distance 선언
    # 'node' 에서 시작해 다른 노드까지 거리
    # 모두 0으로 초기화
    dist = [0] * (N + 1)
    dist[0] = -1

    # dist 자기 자신 초기화
    dist[node] = -1
    dq.append(node)

    while bool(dq):
        n = dq.popleft()

        for c_node, d in adj_list[n]:
            if dist[c_node] != 0 : continue # 탐색했던 곳인지 확인
            dq.append(c_node)
            dist[c_node] = dist[n] + d

    return [k+1 for k in dist]

dist = bfs(1)
max_idx = dist.index(max(dist))
print(max(bfs(max_idx)))
