# Dijkstra algorithms
from collections import deque

# 정점 개수
V, E = map(int, input().split(' '))

# 1D 그래프 nodeMap: 연결된 간선
nodeMap = [[] for _ in range(V + 1)]

# 최단거리
dp = [float('inf') for _ in range(V + 1)]

# 시작 노드
nodeStart = int(input())

for _ in range(E):
    u, v, w = map(int, input().split(' '))

    # 인접 노드 (인접 노드, 간선 길이)
    nodeMap[u].append((v, w))
    nodeMap[v].append((u, w))

def bfs():
    # INF 인 경우 -> (현재 노드까지 거리 + 간선 길이)
    # INF 아닌 경우
    # if 현재 노드까지 거리 + 간선 길이 < 해당 노드까지 이전 거리:
    #   업데이트하고 큐에 넣음
    # else:
    #   continue

    # 초기 큐
    dq = deque()

    # 초기 큐 대입
    dq.append(nodeStart)
    dp[nodeStart] = 0

    while bool(dq):
        # 이전 노드
        prev_node = dq.popleft()

        # 인접 노드
        adj_nodes = nodeMap[prev_node]
        for n, w in adj_nodes:
            # 무한인 경우
            if dp[n] == float('inf'):
                dp[n] = (dp[prev_node] + w)
            else:
                if dp[n] <= dp[prev_node] + w:
                    # 바꿀 필요 없음
                    continue
                else:
                    # 최단거리 변경
                    dp[n] = dp[prev_node] + w
                    # 다시 해당 거리부터 다시 탐색
                    dq.append(n)

    # 출력
    for i in dp[1:]:
        print(i)


def main():
    bfs()

if __name__=="__main__":
    main()