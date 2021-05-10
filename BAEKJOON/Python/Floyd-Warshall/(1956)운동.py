if __name__=="__main__":
    V, E = map(int, input().split(' '))

    node_matrix = [[float('inf') for i in range(V + 1)] for j in range(V + 1)]

    for _ in range(E):
        a, b, c = map(int, input().split(' '))
        node_matrix[a][b] = c

    for k in range(1, V + 1):
        for i in range(1, V + 1):
            for j in range(1, V + 1):
                if node_matrix[i][j] > node_matrix[i][k] + node_matrix[k][j]:
                    node_matrix[i][j] = node_matrix[i][k] + node_matrix[k][j]

    result = float('inf')
    for i in range(1, V+1):
        result = min(result, node_matrix[i][i])

    if result == float('inf'):
        print(-1)
    else:
        print(result)