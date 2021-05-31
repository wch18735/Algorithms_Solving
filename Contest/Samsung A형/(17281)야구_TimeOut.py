# 이닝 수
N = int(input())

# 경기 기록
record = [list(map(int, input().split(' '))) for _ in range(N)]

# 최종 수열 (1번은 항상 4번 타자)
order_array = [0 for i in range(9)]
order_array[0] = 4

# answer
answer = 0
result = 0

# move base
PLAYER = True
EMPTY = False
base_state = [PLAYER, EMPTY, EMPTY, EMPTY]

# score
score = [0 for i in range(50)]

def move_base(hit_number):
    global result

    for base_number in range(3, -1, -1):
        if base_state[base_number] == PLAYER:
            # 홈으로 돌아온다면
            if base_number + hit_number >= 4:
                result += 1
                base_state[base_number] = EMPTY
            # 홈으로 돌아오지 못 한다면
            else:
                # 안타만큼 진루하고, 해당 칸은 비워둠
                base_state[base_number + hit_number] = PLAYER
                base_state[base_number] = EMPTY

# play game
def play_game():
    global base_state, answer, result
    player_order_list = list()

    # (선수 번호, 타순)
    for player_idx, player_order in enumerate(order_array):
        player_order_list.append((player_idx, player_order))

    # 타순으로 정렬
    player_order_list.sort(key=lambda x: x[1])

    # 타순에 따라 경기 진행
    current_player_idx = 0
    inning = 0
    out_count = 0

    while True:
        # 모든 이닝 종료
        if inning == N:
            break

        # 플레이어 뽑기
        base_state[0] = PLAYER
        player_idx = player_order_list[current_player_idx][0]   # player idx
        hit_number = record[inning][player_idx]
        if hit_number == 0:
            out_count += 1

            # out count 가 3개이면 이닝 종료 (아웃 초기화, 다음 이닝, 다음 선수부터 진행, 베이스 초기화)
            if out_count == 3:
                out_count = 0
                inning += 1
                base_state = [PLAYER, EMPTY, EMPTY, EMPTY]
        else:
            # move base
            move_base(hit_number)

        # 다음 선수 뽑음
        current_player_idx += 1
        current_player_idx %= 9

    # 모든 이닝 종료 후
    if result > answer:
        answer = result
        result = 0
    else:
        result = 0

def dfs(cnt):
    global answer

    # cnt == 10 일 때, 1 ~ 9로 채워진 수열 완성
    if cnt == 10:
        play_game()
        return

    # cnt == 4번은 이미 존재
    if cnt == 4:
        dfs(cnt + 1)
        return

    # 현재 순서가 채워지지 않은 칸 탐색
    for i in range(1, 9):
        if order_array[i] != 0:
            continue

        order_array[i] = cnt
        dfs(cnt + 1)
        order_array[i] = 0

def main():
    dfs(1)
    print(answer)

if __name__=="__main__":
    main()