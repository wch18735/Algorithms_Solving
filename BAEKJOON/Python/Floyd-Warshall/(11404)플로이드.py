N = int(input())
M = int(input())

# 갈 수 없음
INF = 2 << 31

# 인접 매트릭스
adj_matrix = [[INF if (i != j) else 0\
               for i in range(N+1)] \
              for j in range(N+1)]

# 인접 모두 더하기
for i in range(M):
    S, E, C = map(int, input().split(' '))
    if C < adj_matrix[S][E]:
        # 다른 도시로 갈 때 여러 루트가 존재하는 경우
        # 최소 비용만 추가
        adj_matrix[S][E] = C

def print_adj_matrix():
    for i in range(1, N+1):
        for j in range(1, N+1):
            if adj_matrix[i][j] == INF:
                print(0, end=' ')
            else:
                print(adj_matrix[i][j], end=' ')
        print()

def floyd_warshall():
    # 지나는 점 k, 시작점 i, 끝 점 j에 대하여
    # shortPath(i, j, k) = min( shortPath(i, j, k-1), shortPath(i, k, k-1) + shortPath(k, j, k-1) )
    # 로 나타낼 수 있다
    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                if adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j]:
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j]

    # print answer
    print_adj_matrix()

if __name__=="__main__":
    floyd_warshall()