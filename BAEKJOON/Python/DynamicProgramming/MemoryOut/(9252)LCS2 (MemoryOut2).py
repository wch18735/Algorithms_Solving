if __name__=="__main__":
    STR1 = input()
    STR2 = input()

    DP = [[[] for i in range(len(STR1) + 1)] for j in range(len(STR2) + 1)]
    LAST_IDX = [[-1 for i in range(len(STR1) + 1)] for j in range(len(STR2) + 1)]

    for i in range(len(STR1)):
        for j in range(len(STR2)):
            if STR1[i] == STR2[j]:
                if len(DP[i][j + 1]) < len(DP[i + 1][j]):
                    if LAST_IDX[i + 1][j] == i:
                        continue

                    DP[i + 1][j + 1] = DP[i + 1][j][:]
                    DP[i + 1][j + 1] += STR1[i]
                    LAST_IDX[i + 1][j + 1] = i
                else:
                    if LAST_IDX[i][j + 1] == i:
                        continue

                    DP[i + 1][j + 1] = DP[i][j + 1][:]
                    DP[i + 1][j + 1] += STR1[i]
                    LAST_IDX[i + 1][j + 1] = i

            else:
                if len(DP[i][j + 1]) < len(DP[i + 1][j]):
                    DP[i + 1][j + 1] = DP[i + 1][j][:]
                    LAST_IDX[i + 1][j + 1] = LAST_IDX[i + 1][j]
                else:
                    DP[i + 1][j + 1] = DP[i][j + 1][:]
                    LAST_IDX[i + 1][j + 1] = LAST_IDX[i][j + 1]

    answer = DP[len(STR1)][len(STR2)]
    print(len(answer))
    print(answer)
