T = int(input())

def dfs(node, travel_cost, travel_time):
    global adj_node_list, M, N, chk, result

    # cost가 높을 때
    if travel_cost > M:
        return

    # N에 도달했을 때
    if node == N:
        if travel_time < result:
            result = travel_time
        return

    # 인접노드 확인
    for next_node, n_cost, n_time in adj_node_list[node]:
        # 한 번 방문한 곳일 때
        if chk[next_node] == True:
            continue

        # 이동
        chk[next_node] = True
        dfs(next_node, travel_cost + n_cost, travel_time + n_time)
        chk[next_node] = False



for test_case in range(1, T+1):
    N, M, K = map(int, input().split(' '))

    # 정답
    result = 2 << 31

    adj_node_list = [[] for _ in range(N+1)]
    chk = [False for _ in range(N + 1)]

    # 초기화
    chk[1] = True

    for _ in range(K):
        u, v, c, d = map(int, input().split(' '))

        # 인접 행렬
        adj_node_list[u].append((v, c, d))

    # dfs
    dfs(1, 0, 0)

    # 정답 프린트
    if result == 2 << 31:
        print('Poor KCM')
    else:
        print(result)