from itertools import combinations
from collections import deque

# 노드 개수
N = int(input())

# 노드별 인구수 (index start with 1)
people = [0] + list(map(int, input().split()))

# 노드 별 인접 노드 저장
nodes = dict()
node_idx = 1
for i in range(N):
    _, *adjacent = list(map(int, input().split()))
    nodes[node_idx] = adjacent
    node_idx += 1

def bfs(node, region):
    # 인접노드
    node_queue = deque()

    # 탐색 시작 노드 삽입
    node_queue.append(node)

    # 방문한 노드 합계
    node_sum = 0
    visit_number = 0

    # 최초 방문한 노드 체크
    chk = [0 for _ in range(N+1)]
    chk[node] = 1
    node_sum += people[node]
    visit_number += 1

    # 인접 노드 탐색
    while bool(node_queue):
        current_node = node_queue.popleft()

        # 연결 된 노드
        adjacent_nodes = nodes.get(current_node)

        for n in adjacent_nodes:
            # 인접 노드가 region 에 들어있지 않은 경우 pass
            if not (n in region):
                continue
            # 인접 노드를 이미 방문한 경우
            if chk[n] == 1:
                continue

            # 방문할 노드 추가
            node_queue.append(n)
            chk[n] = 1
            node_sum += people[n]
            visit_number += 1

    return node_sum, visit_number

result = float('inf')

# 구역 나누기
for k in range(1, N//2+1):
    # 1 ~ N//2 까지
    for region1 in list(combinations(range(1, N+1), k)):
        region1 = list(region1)

        # region1 처음 노드로부터 탐색
        sum1, visit_num1 = bfs(region1[0], region1)

        # region2
        region2 = [i for i in range(1, N+1) if not (i in region1)]
        sum2, visit_num2 = bfs(region2[0], region2)

        if visit_num1 + visit_num2 == N:
            # print(f"region1: {region1}, visit: {visit_num1}, sum: {sum1}")
            # print(f"region2: {region2}, visit: {visit_num2}, sum: {sum2}")
            # print()
            result = min(result, abs(sum1 - sum2))

if result == float('inf'):
    print(-1)
else:
    print(result)
    
# bfs 에서 append 하는 순간 chk 업데이트
# 그래프의 탐색은 bfs or dfs 두 가지 방법이 존재
# N 개 중 C개 선택하는 문제는 combination 사용!!