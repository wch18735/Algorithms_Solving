from copy import deepcopy

# 행, 열, 회전 수
N, M, R = map(int, input().split(' '))

# 배열
MAP = [list(map(int, input().split(' '))) for _ in range(N)]

# 회전 명령어
command_list = list(map(int, input().split(' ')))

# 4개의 부분 수열
part1 = [(y, x) for y in range(N//2) for x in range(M//2)]
part2 = [(y, x) for y in range(N//2) for x in range(M//2, M)]
part3 = [(y, x) for y in range(N//2, N) for x in range(M//2, M)]
part4 = [(y, x) for y in range(N//2, N) for x in range(M//2)]
part_point = [part1, part2, part3, part4]

def update_part(row, col):
    global part1, part2, part3, part4, part_point

    part1 = [(y, x) for y in range(row // 2) for x in range(col // 2)]
    part2 = [(y, x) for y in range(row // 2) for x in range(col // 2, col)]
    part3 = [(y, x) for y in range(row // 2, row) for x in range(col // 2, col)]
    part4 = [(y, x) for y in range(row // 2, row) for x in range(col // 2)]
    part_point = [part1, part2, part3, part4]

def rotate(command, row, col):
    if command == 1:
        # 상하 반전
        upper_idx = 0
        lower_idx = row-1
        while upper_idx < lower_idx:
            MAP[upper_idx], MAP[lower_idx] = MAP[lower_idx], MAP[upper_idx]
            upper_idx += 1
            lower_idx -= 1

    if command == 2:
        # 좌우 반전
        left_idx = 0
        right_idx = col-1

        for trow in MAP:
            while left_idx < right_idx:
                trow[left_idx], trow[right_idx] = trow[right_idx], trow[left_idx]
                left_idx += 1
                right_idx -= 1
            left_idx = 0
            right_idx = col-1

    if command == 3:
        # 오른쪽 90도 회전
        TMP_MAP = deepcopy(MAP)
        MAP.clear()
        for x in range(col):
            tmp_li = list()
            for y in range(row-1, -1, -1):
                tmp_li.append(TMP_MAP[y][x])
            MAP.append(tmp_li)

    if command == 4:
        # 왼쪽 90도 회전
        TMP_MAP = deepcopy(MAP)
        MAP.clear()
        for x in range(col-1, -1, -1):
            tmp_li = list()
            for y in range(row):
                tmp_li.append(TMP_MAP[y][x])
            MAP.append(tmp_li)

    if command == 5:
        # 4개의 부분 배열을 오른 쪽으로 회전
        TMP_MAP = deepcopy(MAP)

        source_part_idx = 0
        target_part_idx = 1
        for _ in range(4):
            for source_p, target_p in zip(part_point[source_part_idx], part_point[target_part_idx]):
                MAP[target_p[0]][target_p[1]] = TMP_MAP[source_p[0]][source_p[1]]

            source_part_idx = (source_part_idx + 1) % 4
            target_part_idx = (target_part_idx + 1) % 4

    if command == 6:
        # 4개의 부분 배열을 왼 쪽으로 회전
        TMP_MAP = deepcopy(MAP)

        source_part_idx = 1
        target_part_idx = 0
        for _ in range(4):
            for source_p, target_p in zip(part_point[source_part_idx], part_point[target_part_idx]):
                MAP[target_p[0]][target_p[1]] = TMP_MAP[source_p[0]][source_p[1]]

            source_part_idx = (source_part_idx + 1) % 4
            target_part_idx = (target_part_idx + 1) % 4

def print_answer(row, col):
    # 답 출력
    for y in range(row):
        for x in range(col):
            print(MAP[y][x], end=' ')
        print()

def main():
    # row, col
    row = N
    col = M

    # 회전
    for command in command_list:
        if command == 5 or command == 6:
            if not (row == N and col == M):
                update_part(row, col)

        # 주어진 행, 열 기준 회전
        rotate(command, row, col)

        # 회전 후 형태 변환
        if command == 3 or command == 4:
            row, col = col, row

    # 답 출력
    print_answer(row, col)


if __name__=="__main__":
    main()