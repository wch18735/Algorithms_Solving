from heapq import heappush, heappop

# 최소비용 구하기
N = int(input())
M = int(input())

INF = 2 << 31
adj_node_list = [[] for _ in range(N+1)]
dp = [INF for _ in range(N+1)]

for _ in range(M):
    start_n, end_n, c = map(int, input().split(' '))

    # 인접 노드 채우기
    adj_node_list[start_n].append((end_n, c))

FROM, TO = map(int, input().split(' '))

def dijkstra(start_n):
    # 현재 위치 값 0
    dp[start_n] = 0

    # 우선순위큐 힙 선언
    HEAP = []
    heappush(HEAP, (dp[start_n], start_n))

    while HEAP:
        current_c, current_n = heappop(HEAP)

        for next_n, w in adj_node_list[current_n]:
            if dp[current_n] + w < dp[next_n]:
                # 이동 후보로 등록
                dp[next_n] = current_c + w
                heappush(HEAP, (dp[next_n], next_n))

if __name__=="__main__":
    dijkstra(FROM)
    print(dp[TO])