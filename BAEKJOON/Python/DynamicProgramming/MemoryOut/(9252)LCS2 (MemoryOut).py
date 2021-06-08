if __name__=="__main__":
    STR1 = input()
    STR2 = input()

    DP = [[[('', -1)] for i in range(len(STR1) + 1)] for j in range(len(STR2) + 1)]

    for i in range(len(STR1)):
        for j in range(len(STR2)):
            if STR1[i] == STR2[j]:
                if len(DP[i][j + 1]) < len(DP[i + 1][j]):
                    if DP[i + 1][j][-1][1] == i:
                        continue

                    DP[i + 1][j + 1] = DP[i + 1][j][:]
                    DP[i + 1][j + 1].append((STR1[i], i))
                else:
                    if DP[i][j + 1][-1][1] == i:
                        continue

                    DP[i + 1][j + 1] = DP[i][j + 1][:]
                    DP[i + 1][j + 1].append((STR1[i], i))

            else:
                if len(DP[i][j + 1]) < len(DP[i + 1][j]):
                    DP[i + 1][j + 1] = DP[i + 1][j][:]
                else:
                    DP[i + 1][j + 1] = DP[i][j + 1][:]

    answer = ''
    for CH, idx in DP[len(STR1)][len(STR2)][1:]:
        answer += CH
    print(len(answer))
    print(answer)
