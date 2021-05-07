from heapq import heappop, heappush

# test case
T = int(input())

for test_case in range(1, T + 1):
    # 노드 수, 총 지원비용, 간선 개수
    N, M, K = map(int, input().split(' '))

    # 인접 노드
    adj_node_list = [[] for _ in range(N + 1)]

    # [도착노드][사용한 비용] <- 걸린 시간
    dp = [[float('inf') for i in range(M + 1)] for j in range(N + 1)]

    for _ in range(K):
        # 출발, 도착, 비용
        u, v, c, d = map(int, input().split(' '))

        # 인접 노드 추가
        adj_node_list[u].append((v, c, d))

    # 힙 선언 및 초기화
    # pq <- (time, cost, node_number)
    HEAP = []
    heappush(HEAP, (0, 0, 1))
    dp[1][0] = 0

    while HEAP:
        # HEAP Q 중 우선순위 가장 높은 것
        current_t, current_c, current_n = heappop(HEAP)

        # 인접 노드 검색
        for next_n, interval_c, interval_t in adj_node_list[current_n]:
            # 다음 노드에 해당하는 비용과 시간
            next_c = current_c + interval_c
            next_t = current_t + interval_t

            # 지원금 초과 검사
            if next_c > M:
                continue

            # 다음 도달할 위치 값과 시간 비교
            if dp[next_n][next_c] <= next_t:
                continue

            # 최소 결과 값 저장
            dp[next_n][next_c] = next_t
            heappush(HEAP, (next_t, next_c, next_n))

    if min(dp[N][1:]) == float('inf'):
        print('Poor KCM')
    else:
        print(min(dp[N][1:]))