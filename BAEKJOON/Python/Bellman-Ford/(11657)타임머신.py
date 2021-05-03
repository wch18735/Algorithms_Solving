

# 도시 개수, 간선 개수
N, M = map(int, input().split(' '))

# 간선 입력
adj_node_list = [[] for _ in range(N + 1)]
for _ in range(M):
    A, B, C = map(int, input().split(' '))
    adj_node_list[A].append((B, C))

def main():
    global N, adj_node_list

    dp = [float('inf') for _ in range(N + 1)]
    dp[1] = 0

    for turn in range(N):
        for current_node in range(1, N+1):
            # 인접 노드
            adj_nodes = adj_node_list[current_node]

            # 인접 노드별로 옆 노드와 최소 거리 갱신
            for next_node, w in adj_nodes:
                if dp[current_node] + w < dp[next_node]:
                    # 갱신 가능할 때
                    dp[next_node] = dp[current_node] + w

                    # 무한루프
                    if turn == N-1:
                        dp[next_node] = -float('inf')
                else:
                    continue

    if -float('inf') in dp:
        print(-1)
    else:
        for d in dp[2:]:
            if d == float('inf'):
                print(-1)
            else:
                print(d)

if __name__=="__main__":
    main()
