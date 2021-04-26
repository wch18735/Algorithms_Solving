from collections import deque

# test_case
T = int(input())

for test_case in range(1, T+1):
    V, E = map(int, input().split(' '))

    # 노드 맵 (인접노드 정보)
    nodeMap = [[] for _ in range(V+1)]

    # 노드 색
    nodeColor = ['e' for _ in range(V+1)]

    for _ in range(E):
        n1, n2 = map(int, input().split(' '))

        # 노드 정보 추가
        nodeMap[n1].append(n2)
        nodeMap[n2].append(n1)

    # 정답 판단 Flag
    bi_possible = True

    # Time Critical -> At least one connected node group doesn't satisfy bipartite graph, answer is same
    while 'e' in nodeColor[1:] and bi_possible:
        # 시작 노드
        current_node = nodeColor.index('e')

        # 시작 색 (빨 / 파)
        current_color = 'r'

        # 노드를 저장할 큐 (노드 번호, 색)
        node_que = deque()

        # bfs는 추가할 때 chk 발생
        node_que.append((current_node, current_color))
        nodeColor[current_node] = current_color

        while bool(node_que) and bi_possible is True:
            current_node, current_color = node_que.popleft()

            # 인접 노드
            adj_nodes = nodeMap[current_node]

            for n in adj_nodes:
                # 인접 노드의 색이 현재 색과 같으면 bi_possible = False
                if nodeColor[n] != 'e':
                    # 이미 체크한 곳인 경우
                    if nodeColor[n] == current_color:
                        # 색이 같으면 불가능
                        bi_possible = False
                        break
                    else:
                        # 다르면 가능하니 진행
                        continue
                else:
                    # 현재 색이 칠해져있지 않으면 반대 색으로 칠함
                    if current_color == 'r':
                        nodeColor[n] = 'b'
                    elif current_color == 'b':
                        nodeColor[n] = 'r'

                    # 현재 색과 노드번호 보냄
                    node_que.append((n, nodeColor[n]))

    if bi_possible:
        print('YES')
    else:
        print('NO')