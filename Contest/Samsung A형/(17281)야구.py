from itertools import permutations

INNING = int(input())
GAME = [list(map(int, input().split(' '))) for i in range(INNING)]

def main():
    player_idx_list = [i for i in range(1, 9)]

    answer = 0
    for player_order in permutations(player_idx_list, 8):
        # player 순서 뽑음
        player_order = list(player_order)
        player_order = player_order[:3] + [0] + player_order[3:]

        # 최종 점수
        score = 0

        # 현재 타석 번호
        current_idx = 0

        # 이닝 별 경기
        for inning in range(INNING):
            # 1번, 2번, 2번 베이스 값
            base1, base2, base3 = 0, 0, 0

            # out count 초기화
            out_count = 0

            while out_count < 3:
                player_idx = player_order[current_idx]

                # 아웃일 때
                if GAME[inning][player_idx] == 0:
                    out_count += 1

                elif GAME[inning][player_idx] == 1:
                    # 3루 값을 더해줌
                    score += base3

                    # 한 칸 씩 진루
                    base1, base2, base3 = 1, base1, base2

                elif GAME[inning][player_idx] == 2:
                    # 2,3루 값을 더해줌
                    score += (base3 + base2)

                    # 2칸 씩 진루
                    base1, base2, base3 = 0, 1, base1

                elif GAME[inning][player_idx] == 3:
                    # 1,2,3루 값을 더해줌
                    score += (base3 + base2 + base1)

                    # 3칸 씩 진루
                    base1, base2, base3 = 0, 0, 1

                elif GAME[inning][player_idx] == 4:
                    # 필드 위 모든 값 더함
                    score += (base3 + base2 + base1 + 1)

                    # 필드 위 아무도 없음
                    base1, base2, base3 = 0, 0, 0

                # 다음 player index
                current_idx = (current_idx + 1) % 9

        # 모든 경기 종료 후
        answer = max(answer, score)

    print(answer)


if __name__=="__main__":
    main()

# while Ture: -> while out_count < 3: 시간초과 통과
# 시간이 촉박한 경우 여러 if 분기문 역시 시간초과의 한 이유가 될 수 있음
# brute force 의 경우 for 문을 통한 전체 검색으로 풀이 가능!!