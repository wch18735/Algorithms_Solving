# f = open('./input.txt')

# T: Test Number
# T = int(f.readline())
T = int(input())

# map_print
def map_print(li):
    for line in li:
        print(line)
    print()

import queue
dq = queue.deque()

for _ in range(T):
    # Test Number T
    # M: 가로, N: 세로, K: 배추 개수
    M, N, K = map(int, input().split())
    # M, N, K = map(int, f.readline().split())
    if K == 1: # 배추가 한 개인 경우
        # 여기서 k == 1이면 어차피 한 개 밖에 없는데
        # input을 안 받으면 Error를 띄움
        dumb = input()
        print(1)
        continue

    # MAP
    MAP = [[0] * M for _ in range(N)]

    # 배추 위치
    for _ in range(K):
        x, y = map(int, input().split())
        # x,y = map(int, f.readline().split())
        MAP[y][x] = 1

    # chk
    chk = [[False for i in range(M)] for j in range(N)]

    # chk match to map
    for i in range(M):
        for j in range(N):
            if MAP[j][i] == 1:
                chk[j][i] = True
    # 방향
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    # discriminator D
    D = 1

    # bfs
    def bfs(node):
        # initialize
        dq.append(node)

        while bool(dq):
            x, y = dq.popleft()
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if nx < 0 or nx >= M: continue  # 좌표 범위
                if ny < 0 or ny >= N: continue  # 좌표 범위
                if chk[ny][nx] is not True: continue  # 탐색조건1
                if MAP[ny][nx] == 0: continue  # 탐색조건2

                dq.append([nx, ny])
                chk[ny][nx] = D

    # Find Discriminator
    def find_D(chk):
        # Discriminator D 선언
        D = 1
        for i in range(M):
            for j in range(N):
                if chk[j][i] is True:
                    bfs([i, j])
                    D += 1
        return D - 1

    print(find_D(chk))

# 반복되는 것은 while 안으로
# 한 번 받는 것은 while 밖으로

# Python 에서 is 는 Object 비교, ==은 Value 비교
# 0, 1 과 같은 value는 ==로 비교
# True, False 와 같은 객체는 Object로 비교

# bfs: condition 초기화가 필요할 때
# dfs: 빠르게 외부 list를 참조해 한 번만 사용할 때