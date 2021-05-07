from heapq import heappop, heappush

# test case
T = int(input())

for test_case in range(1, T+1):
    # 공항, 지원비용, 간선 수
    N, M, K = map(int, input().split(' '))

    # 인접 노드
    adj_node_list = [[] for _ in range(N + 1)]

    # (시간, 비용) dp
    dp_t_c = [[float('inf'), float('inf')] for _ in range(N + 1)]

    for i in range(K):
        u, v, c, d = map(int, input().split(' '))

        # 노드, 시간, 비용
        adj_node_list[u].append((v, d, c))

    # 힙 선언
    HEAP = []

    # 초기화
    dp_t_c[1] = [0, 0]
    heappush(HEAP, (1, 0, 0))

    while HEAP:
        # 가장 가까운 거리 거리 출력
        current_p, current_t, current_c = heappop(HEAP)

        # 인접 위치
        for next_node, trip_time, trip_cost in adj_node_list[current_p]:
            if current_t + trip_time < dp_t_c[next_node][0]:
                dp_t_c[next_node][0] = current_t + trip_time
                dp_t_c[next_node][1] = current_c + trip_cost

                # 힙 삽입
                heappush(HEAP, (next_node, dp_t_c[next_node][0], dp_t_c[next_node][1]))

    if dp_t_c[N][1] == float('inf'):
        print('Poor KCM')
    elif dp_t_c[N][1] > M:
        print('Poor KCM')
    else:
        print(dp_t_c[N][0])
