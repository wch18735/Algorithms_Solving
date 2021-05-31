from collections import deque

VISIT = 0
NOT_VISIT = 1

if __name__=="__main__":
    N, M = map(int, input().split(' '))

    CHK = [NOT_VISIT for i in range(N + 1)]

    adj_nodes = [[] for i in range(N + 1)]

    # adjacent nodes input
    for i in range(M):
        a, b = map(int, input().split(' '))

        adj_nodes[a].append(b)
        adj_nodes[b].append(a)

    # deque() for bfs
    dq = deque()

    answer = 0
    for node in range(1, N+1):
        if CHK[node] == VISIT:
            continue
        else:
            dq.append(node)

            while bool(dq):
                current_node = dq.popleft()

                for adj_node in adj_nodes[current_node]:
                    if CHK[adj_node] == VISIT:
                        continue

                    # change to visit
                    CHK[adj_node] = VISIT
                    dq.append(adj_node)

            answer += 1

    print(answer)