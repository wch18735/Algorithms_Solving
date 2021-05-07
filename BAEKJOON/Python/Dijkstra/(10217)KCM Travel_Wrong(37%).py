from collections import deque
from heapq import heappop, heappush

# input
T = int(input())

TIME = 0
COST = 1

# test case
for test_case in range(1, T+1):
    # 공항 수, 지원 비용, 티켓 정보 수
    N, M, K = map(int, input().split(' '))

    # 인접 노드
    adj_node_list = [[] for _ in range(N + 1)]

    # 시간, 비용 dp
    dp_t_c = [[float('inf'), float('inf')] for _ in range(N + 1)]
    chk = [False for _ in range(N + 1)]

    for _ in range(K):
        u, v, c, d = map(int, input().split(' '))

        # 인접 노드 추가
        adj_node_list[u].append((v, c, d))

    # bfs queue
    dq = deque()

    # bfs init
    dp_t_c[1] = [0, 0]
    chk[1] = True
    dq.append(1)
    
    # or heap (time, node)
    HEAP = []
    heappush(HEAP, (0, 0, 1))
    
    # 예산이 가능한 범위 내에서
    # 모든 최단 경로를 업데이트
    while HEAP:
        # 현재 노드
        current_time, current_cost, current_node = heappop(HEAP)

        # N에 도달했을 때
        if current_node == N:
            continue
        
        for next_node, trip_cost, trip_time in adj_node_list[current_node]:
            # 지원 비용을 넘어서는 경우 패스
            if current_cost + trip_cost > M:
                continue

            # 비용 가능한데 한 번도 도달한 적 없는 곳
            if current_time == float('inf'):
                dp_t_c[next_node][TIME] = current_time + trip_time
                dp_t_c[next_node][COST] = current_cost + trip_cost
                heappush(HEAP, (dp_t_c[next_node][TIME], dp_t_c[next_node][COST], next_node))
                continue

            # 다음 노드가 N일 때
            if next_node == N:
                # 최소 값으로 변환
                if current_time + trip_time < dp_t_c[next_node][TIME]:
                    dp_t_c[next_node][TIME] = current_time + trip_time
                    dp_t_c[next_node][COST] = current_cost + trip_cost
                continue

            # 다음 노드와 같은 경우
            if current_time + trip_time == dp_t_c[next_node][TIME]:
                if current_cost + trip_cost < dp_t_c[next_node][COST]:
                    dp_t_c[next_node][COST] = current_cost + trip_cost
                    heappush(HEAP, (dp_t_c[next_node][TIME], dp_t_c[next_node][COST], next_node))
                continue

            # 다음 노드보다 빠른 경우
            if current_time + trip_time < dp_t_c[next_node][TIME]:
                dp_t_c[next_node][TIME] = current_time + trip_time
                dp_t_c[next_node][COST] = current_cost + trip_cost
                heappush(HEAP, (dp_t_c[next_node][TIME], dp_t_c[next_node][COST], next_node))
                continue
                
    if dp_t_c[N][0] == float('inf'):
        print('Poor KCM')
    else:
        print(dp_t_c[N][TIME])