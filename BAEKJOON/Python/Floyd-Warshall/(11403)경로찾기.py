N = int(input())

# 무한
INF = 2 << 31

# 인접 행렬
adj_matrix = [[] for i in range(N + 1)]
for i in range(1, N+1):
    adj_matrix[i] = [0] + list(map(int, input().split(' ')))


# isPath(i, j, k) -> if(adj_matrix[i][k] and adj_matrix[k][j]) 이면 존재
for k in range(1, N + 1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            if adj_matrix[i][k] == 1 and adj_matrix[k][j] == 1:
                adj_matrix[i][j] = 1

for i in range(1, N+1):
    for j in range(1, N+1):
        print(adj_matrix[i][j], end=' ')
    print()