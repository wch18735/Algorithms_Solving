# 테스트 케이스
T = int(input())

for test_case in range(1, T + 1):
    INF = 2<<31

    # 입력
    N, M, W = map(int, input().split(' '))

    adj_node_list = [[] for _ in range(N+1)]
    dp = [INF for _ in range(N + 1)]

    for _ in range(M):
        S, E, T = map(int, input().split(' '))
        adj_node_list[S].append((E, T))
        adj_node_list[E].append((S, T))

    for _ in range(W):
        S, E, T = map(int, input().split(' '))
        adj_node_list[S].append((E, -T))

    possible_flag = False
    for turn in range(1, N + 1):
        for current_node in range(1, N+1):
            for next_node, w in adj_node_list[current_node]:
                if dp[current_node] + w < dp[next_node]:
                    # 값 갱신
                    dp[next_node] = dp[current_node] + w

                    if turn == N:
                        possible_flag = True

    if possible_flag:
        print('YES')
    else:
        print('NO')