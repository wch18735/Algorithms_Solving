# 입력
N, M, R = map(int, input().split(' '))

# MAP
MAP = [input().split(' ') for _ in range(N)]

# command list
command_list = list(input().split(' '))

def reverse_updown():
    global MAP
    MAP = MAP[::-1]

def reverse_lr():
    global MAP
    copied_map = list()
    for e in MAP:
        copied_map.append(e[::-1])

    MAP = copied_map

def rotate_right():
    global N, M, MAP

    # 길이 변환
    M, N = N, M

    copied_map = list()
    for r in zip(*MAP):
        copied_map.append(r[::-1])

    MAP = copied_map

def rotate_left():
    global N, M, MAP

    # 길이 변환
    M, N = N, M

    copied_map = list()
    for r in zip(*MAP):
        copied_map.append(r)

    MAP = copied_map[::-1]

def partial_right():
    global N, M, MAP

    # 입력할 리스트
    copied_map = [[0 for i in range(M)] for j in range(N)]

    row_half = N//2
    column_half = M//2

    # part1 -> part2
    for y in range(row_half):
        for x in range(column_half):
            copied_map[y][x + column_half] = MAP[y][x]

    # part2 -> part3
    for y in range(row_half):
        for x in range(column_half, M):
            copied_map[y + row_half][x] = MAP[y][x]

    # part3 -> part4
    for y in range(row_half, N):
        for x in range(column_half, M):
            copied_map[y][x - column_half] = MAP[y][x]

    # part4 -> part1
    for y in range(row_half, N):
        for x in range(column_half):
            copied_map[y - row_half][x] = MAP[y][x]

    MAP = copied_map

def partial_left():
    global N, M, MAP

    # 입력할 리스트
    copied_map = [[0 for i in range(M)] for j in range(N)]

    row_half = N // 2
    column_half = M // 2

    # part2 -> part1
    for y in range(row_half):
        for x in range(column_half, M):
            copied_map[y][x - column_half] = MAP[y][x]

    # part3 -> part2
    for y in range(row_half, N):
        for x in range(column_half, M):
            copied_map[y - row_half][x] = MAP[y][x]

    # part4 -> part3
    for y in range(row_half, N):
        for x in range(column_half):
            copied_map[y][x + column_half] = MAP[y][x]

    # part1 -> part4
    for y in range(row_half):
        for x in range(column_half):
            copied_map[y + row_half][x] = MAP[y][x]

    MAP = copied_map

def main():
    for c in command_list:
        if c == '1':
            reverse_updown()
        if c == '2':
            reverse_lr()
        if c == '3':
            rotate_right()
        if c == '4':
            rotate_left()
        if c == '5':
            partial_right()
        if c == '6':
            partial_left()

    for element in MAP:
        print(*element)

if __name__=="__main__":
    main()