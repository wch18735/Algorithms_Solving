from collections import deque
import copy

# 길이
N = int(input())

# 벽 입력
bricks = [list((map(int, input().split(' ')))) for i in range(N)]

# 지나간 자리 DP
chk = [[[] for i in range(N)] for j in range(N)]

# 상태: 방향 start_(dy, dx), end_(dy, dx)
# 벡터에 따른 상태 판단 (가로, 세로, 대각)
# end(y2, x2) - start(y1, x1)
direction_dict = {
    (0, 1): [((0, 1), (0, 1)), ((0, 1), (1, 1))], # 오른쪽 1칸, 오른쪽 대각 1칸
    (1, 0): [((1, 0), (1, 0)), ((1, 0), (1, 1))], # 아래 1칸, 아래 대각 1칸
    (1, 1): [((1, 1), (0, 1)), ((1, 1), (1, 0)), ((1, 1), (1, 1))], # 가로로 1칸, 세로로 1칸, 대각으로 1칸
}

state_dict = {
    (0, 1): "horizon",
    (1, 0): "vertical",
    (1, 1): "slide"
}

def copypipe(pipe):
    return copy.deepcopy(pipe)

def calculvec(cstate):
    startp = cstate[0]  # (y1, x1)
    endp = cstate[1]    # (y2, x2)
    return endp[0] - startp[0], endp[1] - startp[1]

def return_state(state):
    return state_dict.get(state)

def bfs():
    # (1, 1)에서 출발하여 (N, N)에 도달하는 경우의 수
    # -> (N-1,N-1) 이면 도착!!

    # 파이프 객체 (시작 위치, 끝 위치) -> (y, x)
    pipe = [[0, 0], [0, 1]]

    # 파이프 상태 저장
    pipe_positions = deque()
    pipe_positions.append(copypipe(pipe))

    answer = 0

    # 탐색
    while bool(pipe_positions):
        # 현재 파이프 상태
        current_pipe = pipe_positions.popleft()
        state = calculvec(current_pipe)

        # 현재 파이프 도착 확인
        if current_pipe[1][0] == N-1 and current_pipe[1][1] == N-1:
            answer += 1
            continue

        # 상태에 따른 방향
        directions = direction_dict.get(state)

        # 예외처리
        if directions == None: break

        # 탐색
        for dd in directions:
            # start dy and dx, end dy and dx
            dd_s, dd_e = dd

            # 현재 상태 파이프 복사
            tmp_pipe = copypipe(current_pipe)

            # 파이프 이동
            tmp_pipe[0][0] = tmp_pipe[0][0] + dd_s[0]   # 시작 y
            tmp_pipe[0][1] = tmp_pipe[0][1] + dd_s[1]   # 시작 x
            tmp_pipe[1][0] = tmp_pipe[1][0] + dd_e[0]   # 끝 y
            tmp_pipe[1][1] = tmp_pipe[1][1] + dd_e[1]   # 끝 x

            # 끝 부분이 범위를 넘어간 경우 continue
            if not (tmp_pipe[1][0] < N): continue
            if not (tmp_pipe[1][1] < N): continue
            # 벽을 만난 경우
            if bricks[tmp_pipe[1][0]][tmp_pipe[1][1]] == 1: continue
            # 대각선일 때, 겹치는 경우
            if return_state(calculvec(tmp_pipe)) == "slide":
                s_x = tmp_pipe[0][1]
                s_y = tmp_pipe[0][0]
                if bricks[s_y + 1][s_x] == 1 or bricks[s_y][s_x + 1] == 1:
                    continue

            # 상태에 추가
            pipe_positions.append(copypipe(tmp_pipe))

    return answer

def main():
    print(bfs())
    # print(chk)

if __name__=="__main__":
    main()