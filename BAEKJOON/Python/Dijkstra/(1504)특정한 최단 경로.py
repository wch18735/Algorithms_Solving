# 저장용 heapq
import heapq

N, E = map(int, input().split(' '))

# 인접 노드
adj_node_list = [[] for _ in range(N+1)]

# 간선 정보 저장
for i in range(E):
    v1, v2, c = map(int, input().split(' '))

    # 양방향 인접 노드 저장
    adj_node_list[v1].append((v2, c))
    adj_node_list[v2].append((v1, c))

# 거쳐야 하는 중간 노드
node1, node2 = map(int, input().split(' '))


def dijkstra(start_node):
    # 시작 노드에서부터 시작되는 최단거리 스패닝 트리
    dp = [float('inf') for _ in range(N + 1)]
    dp[start_node] = 0

    # 가장 짧은 거리를 가진 힙
    heap = []
    heapq.heappush(heap, (dp[start_node], start_node))

    while heap:
        d, n = heapq.heappop(heap)

        # 인접 노드 확인
        adj_nodes = adj_node_list[n]

        # 인접 노드별로 거리 검사
        for a_n, w in adj_nodes:
            if dp[a_n] == float('inf'):
                # 인접 노드가 float('inf')인 경우
                # 최단거리 업데이트, 큐에 삽입
                dp[a_n] = dp[n] + w
                heapq.heappush(heap, (dp[a_n], a_n))

            else:
                if dp[a_n] <= dp[n] + w:
                    continue
                else:
                    dp[a_n] = dp[n] + w
                    heapq.heappush(heap, (dp[a_n], a_n))
    return dp

def main():
    start_dp = dijkstra(1)
    node1_dp = dijkstra(node1)
    node2_dp = dijkstra(node2)

    # 1 -> node1 -> node2 -> N
    # 1 -> node2 -> node1 -> N
    result = min(start_dp[node1] + node1_dp[node2] + node2_dp[N],
                 start_dp[node2] + node2_dp[node1] + node1_dp[N])

    # 결과 해석
    if result == float('inf'):
        print(-1)
    else:
        print(result)

if __name__=="__main__":
    main()