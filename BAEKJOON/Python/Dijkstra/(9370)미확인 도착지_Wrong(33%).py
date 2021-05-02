from heapq import heappush, heappop

# test_case
T = int(input())

def dijkstra(start_node):
    global adj_node_list, route_dp, dp

    # 시작점 dp 0으로 초기화
    dp[start_node] = 0

    HEAP = []

    # 해당 노드까지 거리, 해당 노드, 지나가는 경로
    heappush(HEAP, (dp[start_node], start_node, []))

    while HEAP:
        d, currentNode, route = heappop(HEAP)

        # 인접 노드 확인
        adj_node = adj_node_list[currentNode]

        for nextNode, w in adj_node:
            if dp[nextNode] < d + w:
                continue
            else:
                dp[nextNode] = d + w
                route.append((currentNode, nextNode))
                route_dp[nextNode] = route
                heappush(HEAP, (dp[nextNode], nextNode, route.copy()))

if __name__=="__main__":
    global adj_node_list, route_dp, dp

    for test_case in range(1, T + 1):
        # 노드 수, 간선 수, 후보 수
        n, m, t = map(int, input().split(' '))

        # 인접 노드 리스트
        adj_node_list = [[] for _ in range(n + 1)]
        # 경로 dp
        route_dp = [[] for _ in range(n + 1)]
        # dp
        dp = [float('inf') for _ in range(n + 1)]

        # 출발지, g ~ h
        s, g, h = map(int, input().split(' '))

        for i in range(m):
            a, b, d = map(int, input().split(' '))

            # 인접 노드 추가
            adj_node_list[a].append((b, d))
            adj_node_list[b].append((a, d))

        # 후보 노드
        validate_list = []
        for i in range(t):
            validate_list.append(int(input()))
        validate_list.sort(key=lambda x: x)

        # 다익스트라
        dijkstra(s)

        # 확인
        for v in validate_list:
            route = route_dp[v]

            if (g, h) in route or (h, g) in route:
               print(v, end=' ')
        print()