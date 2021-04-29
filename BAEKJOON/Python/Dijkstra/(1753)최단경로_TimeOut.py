from queue import PriorityQueue

# input
V, E = map(int, input().split(' '))

# start point
start_node = int(input())

# input
adj_node_list = [[] for _ in range(V + 1)]
for _ in range(E):
    a, b, w = map(int, input().split(' '))

    # add node
    adj_node_list[a].append((b, w))

# dynamic memory
dp = [float('inf') for _ in range(V + 1)]

# bfs
def bfs():
    # initial node
    dp[start_node] = 0

    # priority que
    que = PriorityQueue()
    que.put((dp[start_node], start_node))

    while que.qsize() != 0:
        # 가장 거리가 짧은 노드
        d, node = que.get()

        # 인접 노드
        adj_nodes = adj_node_list[node]

        # 인접 노드들을 추가
        for n, w in adj_nodes:
            if dp[n] <= dp[node] + w:
                continue
            else:
                dp[n] = dp[node] + w
                que.put((dp[n], n))

    for d in dp[1:]:
        print(d)

def main():
    bfs()

if __name__=="__main__":
    main()