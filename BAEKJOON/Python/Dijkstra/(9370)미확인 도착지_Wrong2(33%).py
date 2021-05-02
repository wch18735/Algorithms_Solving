from heapq import heappush, heappop

# test case
T = int(input())

def dijkstra(start_node):
    global n, adj_node_list

    # 최단거리 dp
    dp = [float('inf') for _ in range(n + 1)]
    dp[start_node] = 0

    # 선택 HEAP
    HEAP = []
    heappush(HEAP, (0, start_node))

    while HEAP:
        d, current_node = heappop(HEAP)
        adj_nodes = adj_node_list[current_node]

        for next_node, w in adj_nodes:
            if dp[next_node] <= d + w:
                continue
            else:
                dp[next_node] = d + w
                heappush(HEAP, (d+w, next_node))

    return dp


def main():
    global n, adj_node_list

    for test_case in range(1, T + 1):
        # 노드 개수, 간선 개수, 후보 수
        n, m, t = map(int, input().split(' '))

        # 출발지, g ~ h
        s, g, h = map(int, input().split(' '))

        # 양방향 도로 채우기
        adj_node_list = [[] for _ in range(n + 1)]
        for _ in range(m):
            a, b, d = map(int, input().split(' '))
            adj_node_list[a].append((b, d))
            adj_node_list[b].append((a, d))

        # 후보
        validate_nodes = []
        for _ in range(t):
            validate_nodes.append(int(input()))
        validate_nodes.sort(key=lambda x: x)

        # 다익스트라
        s_dp = dijkstra(s)
        h_dp = dijkstra(h)
        g_dp = dijkstra(g)
        h_to_g = min(h_dp[g], g_dp[h])

        for v in validate_nodes:
            minimum_d = s_dp[v]

            if s_dp[h] + h_to_g + g_dp[v] == minimum_d or s_dp[g] + h_to_g + h_dp[v] == minimum_d:
                print(v, end=' ')

        print()


if __name__=="__main__":
    main()