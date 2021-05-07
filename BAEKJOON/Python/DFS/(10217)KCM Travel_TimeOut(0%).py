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
            # 방문한 곳보다 시간도 오래 걸리고, 비용도 높을 때
            if travel_time + n_time > dp_t[next_node] and travel_cost + n_cost > dp_c[next_node]:
                # 검사 생략
                continue

        # 이전 값
        prev_t = dp_t[next_node]
        prev_c = dp_c[next_node]

        # 다음 위치 시간, 비용 값 업데이트
        dp_t[next_node] = travel_time + n_time
        dp_c[next_node] = travel_cost + n_cost

        # 이동 (dp 값 채움)
        chk[next_node] = True
        dfs(next_node, travel_cost + n_cost, travel_time + n_time)
        chk[next_node] = False

        # 이전 값 복원
        dp_t[next_node] = prev_t
        dp_c[next_node] = prev_c


for test_case in range(1, T+1):
    N, M, K = map(int, input().split(' '))

    # 정답
    result = 2 << 31

    # 인접
    adj_node_list = [[] for _ in range(N+1)]
    chk = [False for _ in range(N + 1)]
    dp_t = [float('inf') for _ in range(N + 1)]
    dp_c = [float('inf') for _ in range(N + 1)]

    # 초기화
    dp_t[1] = 0
    dp_c[1] = 0

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