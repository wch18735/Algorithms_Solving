def dist(car_pos_x, car_pos_y, work_num):
    return abs(car_pos_x - works[work_num][0]) + abs(car_pos_y - works[work_num][1])

def print_cache():
    for i in range(W + 1):
        for j in range(W + 1):
            print(DP[i][j],end=' ')
        print()

def trace_route(a, b):
    if a == W or b == W:
        return

    # next work num
    next_work = max(a, b) + 1

    # car1 distance for next work number
    if a == 0:
        dist1 = dist(1, 1, next_work)
    else:
        dist1 = dist(works[a][0], works[a][1], next_work)

    # car2 distance for next work number
    if b == 0:
        dist2 = dist(N, N, next_work)
    else:
        dist2 = dist(works[b][0], works[b][1], next_work)

    if DP[next_work][b] + dist1 < DP[a][next_work] + dist2:
        # car1 출동할 때 남은 거리가 더 짧음
        print(1)
        trace_route(next_work, b)
    else:
        # car2 출동할 때 남은 거리가 더 짧음
        print(2)
        trace_route(a, next_work)

    return

def dfs(a, b):
    # last case
    if a == W or b == W:
        return DP[a][b]

    # if exist
    if DP[a][b] != float('inf'):
        return DP[a][b]

    # 다음 사건 번호
    next_case = max(a, b) + 1

    # 차량1 위치
    if a == 0:
        car1_x, car1_y = 1, 1
    else:
        car1_x, car1_y = works[a]

    # 차량2 위치
    if b == 0:
        car2_x, car2_y = N, N
    else:
        car2_x, car2_y = works[b]

    # result
    DP[a][b] = min(dfs(next_case, b) + dist(car1_x, car1_y, next_case),
                   dfs(a, next_case) + dist(car2_x, car2_y, next_case))
    
    return DP[a][b]

def solution():
    global N, W, DP, works, result

    # village width
    N = int(input())

    # work number
    W = int(input())
    works = [(0, 0)]

    # N x N Cache
    DP = [[float('inf') for i in range(W + 1)] for j in range(W + 1)]
    for i in range(W):
        DP[i][W] = 0
        DP[W][i] = 0

    # input works
    for i in range(W):
        a, b = map(int, input().split(' '))
        works.append((a, b))

    # minimum total distances
    result = dfs(0, 0)
    print(result)

    # route
    trace_route(0, 0)

if __name__=="__main__":
    solution()