from collections import deque

# 테스트 케이스
T = int(input())

# 나이트의 이동가능 방법
dx = [1, 2, 2, 1, -1, -2, -2, -1]
dy = [2, 1, -1, -2, -2, -1, 1, 2]


def solution():
    # global 함수 지정
    global ch_length, cx, cy, tx, ty, answer, chesspan, chk

    # 한 변의 길이
    ch_length = int(input())

    # 체스판
    chesspan = [[0 for i in range(ch_length)] for j in range(ch_length)]
    chk = [[0 for i in range(ch_length)] for j in range(ch_length)]

    # 현재 나이트 위치
    cx, cy = map(int, input().split())

    # 타겟 위치
    tx, ty = map(int, input().split())

    # answer
    answer = 0

    # 위치 판별
    if cx == tx and cy == ty:
        return answer

    # 탐색
    return bfs()

def bfs():
    # 초기 위치 체크
    chk[cy][cx] = 1

    # 탐색 위치 정보 저장
    positions = deque()
    positions.append((cy, cx, answer))

    # 탐색
    while bool(positions):
        y, x, step = positions.popleft()

        # 현재 위치가 타겟 위치인지 확인
        if y == ty and x == tx:
            return step

        # 아닌 경우 탐색
        for i in range(8):
            ny = y + dy[i]
            nx = x + dx[i]

            # x 범위를 초과하는 경우
            if not (0 <= nx < ch_length):
                continue
            # y 범위를 초과하는 경우
            if not (0 <= ny < ch_length):
                continue
            # 이미 밟은 곳을 지나간 경우
            if chk[ny][nx] == 1:
                continue

            # 탐색 위치 추가
            chk[ny][nx] = 1
            positions.append((ny, nx, step + 1))

def main():
    for t in range(T):
        print(solution())

if __name__=="__main__":
    main()