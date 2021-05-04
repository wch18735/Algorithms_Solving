T = int(input())

for test_case in range(1, T + 1):
    N, M, W = map(int, input().split(' '))

    # 인접 노드
    adj_node_list = [[] for _ in range(N + 1)]
    dp = [float('inf') for _ in range(N + 1)]
    dp[1] = 0

    # 간선
    for _ in range(M):
        S, E, T = map(int, input().split(' '))
        adj_node_list[S].append((E, T))
        adj_node_list[E].append((S, T))

    # 웜홀
    for _ in range(W):
        S, E, T = map(int, input().split(' '))
        adj_node_list[S].append((E, -T))

    # possible flag
    possible_flag = True
    for turn in range(N):
        for current_node in range(1, N+1):
            for next_node, w in adj_node_list[current_node]:
                if dp[current_node] + w < dp[next_node]:
                    # 갱신 지점
                    dp[next_node] = dp[current_node] + w

                    # 마지막 갱신
                    if turn == N-1:
                        possible_flag = False
                else:
                    continue

    print("NO" if possible_flag else "YES")
