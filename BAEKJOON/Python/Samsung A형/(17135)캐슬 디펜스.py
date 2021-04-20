from copy import deepcopy

# 세로, 가로, 사정거리
N, M, D = map(int, input().split(' '))

# 궁수 위치는 시작 때 고정
# DP + DFS
# 각 턴마다 죽인 개수 합 저장
castle = [list(map(int, input().split(' '))) for i in range(N)]
result = 0
answer = 0

# point[y][x] 에 대하여 거리 D를 체크하는 함수
def check_diamond(y, x, D, enemy):
    global result

    # target list
    targets = []

    # 가장 가가운 거리
    for d in range(1, D + 1):
        # 가장 가까운 행
        for y_idx in range(y-1, y-d-1, -1):
            # 가까운 거리가 여러 개일 때 왼쪽부터 고려
            for x_idx in range(x-d, x+d+1):
                # x_idx 의 범위가 허용범위일 때
                if not (0 <= x_idx < M): continue
                # y_idx 의 범위가 허용범위일 때
                if not (0 <= y_idx < N): continue
                # 사정거리 안에 있을 때
                if not (abs(y_idx-y) + abs(x_idx-x) <= d): continue
                # 해당 target 위치가 1 or 'k' 일 때
                if not (enemy[y_idx][x_idx] == 1 or enemy[y_idx][x_idx] == 'k'): continue

                # 해당 타겟을 추가
                targets.append((y_idx, x_idx))

        # 거리마다 탐색하며 있는 경우
        if len(targets) == 0:
            continue
        else:
            targets.sort(key=lambda x:x[1])
            y_idx, x_idx = targets[0]
            if enemy[y_idx][x_idx] == 1:
                enemy[y_idx][x_idx] = 'k'
                result += 1
                return

            # 이미 한 번 쐈을 경우 kill 세지 않음
            elif enemy[y_idx][x_idx] == 'k':
                return

# 길이 M, 1의 개수 3개인 리스트 반환하는 함수
comblist = [0 for _ in range(M)]

# 이중 리스트 프린트
def print_list(enemy):
    for i in range(N):
        for j in range(M):
            print(enemy[i][j], end=' ')
        print()
    print()

def elimniate_kill(enmy):
    for y_idx in range(N):
        for x_idx in range(M):
            if enmy[y_idx][x_idx] == 'k':
                enmy[y_idx][x_idx] = 0

# 주어진 comblist 를 이용해 총 해치우는 적 수 계산
def solution():
    copied_castle = deepcopy(castle)

    # 아래서부터 순회하며 결과 값 해석
    for y_idx in range(N, 0, -1):
        for x_idx, archer in enumerate(comblist):
            if archer == 1:
                # 궁수가 배치된 곳일 때
                check_diamond(y_idx, x_idx, D, copied_castle)

        # turn이 끝날 때마다 kill 된 적들 0으로 변환
        elimniate_kill(copied_castle)

    global answer
    global result
    answer = max(answer, result)
    result = 0

def dfs(cnt, sidx):
    if cnt == 3:
        solution()
        return

    if sidx == M:
        return

    # dfs
    comblist[sidx] = 1
    dfs(cnt + 1, sidx + 1)
    comblist[sidx] = 0
    dfs(cnt, sidx + 1)

def main():
    dfs(0, 0)
    print(answer)

if __name__=="__main__":
    main()


# 문제에서 중요하게 다룰 점
# 1. Diamond 범위 탐색
# 2. 탐색 순서를 for문 순서를 이용해 조절할 수 있다는 것
# 3. 가장 왼쪽, 오른쪽 등은 list.sort(key=lambda x:(x[0], x[1])) 을 이용해 정렬할 수 있다는 것
# 4. global 을 이용해 함수 내부에서도 전역변수 접근!!
# 5. combination -> dfs() 를 통해 구현!!