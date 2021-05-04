# test case
T = int(input())

for test_case in range(1, T + 1):
    # 지점 수, 도로 수, 웜홀 수
    N, M, W = map(int, input().split(' '))

    # 도로 정보
    adj_node_list = [[] for _ in range(N + 1)]
    for _ in range(M):
        # 연결된 지점 번호, 시간
        S, E, T = map(int, input().split(' '))

        adj_node_list[S].append((E, T))
        adj_node_list[E].append((S, T))

    # 웜홀 정보
    for _ in range(W):
        S, E, T = map(int, input().split(' '))

        adj_node_list[S].append((E, -T))

    # 길이 (1번 노드를 시작 노드로 초기화)
    dp = [float('inf') for _ in range(N+1)]
    dp[1] = 0

    # MST 만들기
    loop_flag = False
    for turn in range(1, N+1):
        # MST 가장 긴 길이 N-1 / 마지막 Loop 계산
        for v in range(1, N+1):
            # 인접 노드
            adj_nodes = adj_node_list[v]

            for next_node, w in adj_nodes:
                if dp[v] + w < dp[next_node]:
                    # 갱신!!
                    dp[next_node] = dp[v] + w

                    # 마지막 갱신에서 Loop 확인
                    if turn == N:
                        # Loop 이 형성되는 목적지를 -INF로 맞춤
                        dp[next_node] = -float('inf')
                else:
                    continue

    # 체크
    # 단절된 경우
    if float('inf') in dp[1:]:
        print('NO')
    else:
        if -float('inf') in dp[1:]:
            print('YES')
        else:
            print('NO')
