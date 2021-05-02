# 최단 경로 루트를 확보한다
# 해당 루트에 g -> h 가 있는지 확인한다
# 있는 경우를 모두 출력한다

import heapq

# test case
T = int(input())

def bfs(start_node):
    global adj_node_list, dp, route_dp

    # initialize
    dp[start_node] = 0

    # heap
    heap = []
    heapq.heappush(heap, (dp[start_node], start_node))

    while heap:
        # 가장 최소의 간선 선택
        current_d, current_node = heapq.heappop(heap)

        # 인접 노드 검색
        adj_nodes = adj_node_list[current_node]

        # 인접노드 중 조건 만족하는 것 선택
        for adj_n, adj_w in adj_nodes:
            if dp[adj_n] == float('inf'):
                dp[adj_n] = dp[current_node] + adj_w
                route_dp[adj_n] = route_dp[current_node].append((current_node, adj_n))
                heapq.heappush(heap, (dp[adj_n], adj_n))
            else:
                if dp[adj_n] <= dp[current_node] + adj_w:
                    continue
                else:
                    dp[adj_n] = dp[current_node] + adj_w
                    route_dp[adj_n] = route_dp[current_node].append((current_node, adj_n))
                    heapq.heappush(heap, (dp[adj_n], adj_n))

def main():
    # 시작노드부터 탐색
    bfs(s)

    # 해당 후보로 가는 최단 경로에 (g, h) or (h, g)가 포함되는지 확인
    for v in  validate_node:
        routes = route_dp[v]

        # 가능한 후보인지 확인
        if (g, h) in routes or (h, g) in routes:
            print(v, end=' ')
    print()

    # 전역 변수 초기화

if __name__=="__main__":
    for test_case in range(T):
        # n, m, t (노드, 간선, 후보 수)
        n, m, t = map(int, input().split(' '))

        # dynamic programming
        dp = [float('inf') for _ in range(n + 1)]
        route_dp = [[] for _ in range(n + 1)]

        # 인접 노드
        adj_node_list = [[] for _ in range(n + 1)]

        # 출발 노드, 지나간 두 노드
        s, g, h = map(int, input().split(' '))

        for _ in range(m):
            a, b, d = map(int, input().split(' '))

            # 인접 노드
            adj_node_list[a].append((b, d))
            adj_node_list[b].append((a, d))

        # 후보 노드 추가
        validate_node = []
        for _ in range(t):
            validate_node.append(int(input()))

        # main 함수 실행
        main()