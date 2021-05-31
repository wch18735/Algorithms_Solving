# board => NxN matrix (5 <= N <= 30)
# moves => M list (1 <= M <= N)

from collections import deque

def solution(board, moves):
    # answer
    answer = 0

    # stack [][][] <- in
    doll_stack = deque()

    for b in board:
        print(*b)

    for x_idx in moves:
        # index 조정
        x_idx = x_idx - 1

        # 가장 아래에 있는 인형 뽑기
        y_idx = 0
        doll_type = 0
        while y_idx < len(board):
            if board[y_idx][x_idx] != 0:
                # 인형 뽑기
                doll_type = board[y_idx][x_idx]
                # 뽑은 칸 비우기
                board[y_idx][x_idx] = 0
                break
            y_idx += 1

        # 뽑힌 인형이 하나도 없으면
        if doll_type == 0:
            continue

        # 인형을 뽑았을 때
        if not bool(doll_stack):
            # 저장된 인형이 없으면 그냥 넣음
            doll_stack.append(doll_type)
        else:
            # 일치하면 꺼냄
            if doll_stack[-1] == doll_type:
                doll_stack.pop()
                answer += 2
            else:
                # 일치하지 않으면 맨 끝에 저장
                doll_stack.append(doll_type)

    return answer