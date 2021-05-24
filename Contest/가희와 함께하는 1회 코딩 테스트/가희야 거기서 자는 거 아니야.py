if __name__=="__main__":
    room_row, room_col = map(int, input().split(' '))
    gahui_row, gagui_col, pill_row, pill_col = map(int, input().split(' '))

    MAP = [list(input()) for i in range(room_row)]

    cnt = 0
    for i in range(room_row):
        for j in range(room_col):
            if MAP[i][j] == 'P':
                cnt += 1

    if cnt == pill_row * pill_col:
        print(0)
    else:
        print(1)