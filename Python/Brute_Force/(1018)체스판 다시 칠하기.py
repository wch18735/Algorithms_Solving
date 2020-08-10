# txt = open('./input.txt')
# M,N = map(int,txt.readline().split()) # M: row, N: coloumn
# chess_table = [[ch for ch in txt.readline() if ch != '\n'] for _ in range(M)]

M,N = map(int, input().split())
chess_table = [[ch for ch in input() if ch != '\n'] for _ in range(M)]

def print_table(chess_table):
    for i in chess_table:
        for j in i:
            print(j,end='')
        print()

def check_chess_table(chess_table, row_point, coloum_point):
    # chess_table[row][col]
    # start with B: count_B, normal_count_B
    # start with W: count_W, normal_count_W
    count_B = 0
    count_W = 0


    normal_table_B = [['B' if (i + j) % 2 == 0 else 'W' for i in range(8)] for j in range(8)]

    for i in range(8):
        for j in range(8):
            if chess_table[row_point + i][coloum_point + j] != normal_table_B[i][j]:
                count_B += 1


    normal_table_W = [['W' if (i + j) % 2 == 0 else 'B' for i in range(8)] for j in range(8)]

    for i in range(8):
        for j in range(8):
            if chess_table[row_point + i][coloum_point + j] != normal_table_W[i][j]:
                count_W += 1

    return min(count_B, count_W)

dif_list = []

for i in range(M):
    if i > M-8: break # 도달 시 모든 경우 확인 (경계조건)
    for j in range(N):
        if j > N-8: continue # 도달 시 아직 남은 경우 있음 (경계조건)

        dif_list.append(check_chess_table(chess_table,i,j))

print(min(dif_list))