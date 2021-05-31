# input
N = int(input())

# bricks
bricks = [[0 for i in range(N+1)]] + [[0] + list(map(int, input().split(' '))) for i in range(N)]

# DP 풀이 (Memoization or Terbulance)
# 도착했을 때 가로, 세로, 대각인 상태 DP를 만들 수 있다
# (N+1) * (N+1) * 3 형태 DP
dp = [[[0, 0, 0] for i in range(N+1)] for j in range(N+1)]
# (1, 2)의 가로는 1 가능
dp[1][2][0] = 1

def print_dp():
    for i in range(1, N+1):
        for j in range(1, N+1):
            print(sum(dp[i][j]), end=' ')
        print()

def main():
    for y in range(1, N + 1):
        for x in range(1, N + 1):
            if bricks[y][x] == 1:
                continue

            # 도착했을 때 가로 (0)
            # 왼 쪽 옆 가로
            # 왼 쪽 옆 대각
            dp[y][x][0] += (dp[y][x - 1][0] + dp[y][x - 1][2])

            # 도착했을 때 세로 (1)
            # 위 세로
            # 위 대각
            dp[y][x][1] += (dp[y - 1][x][1] + dp[y - 1][x][2])

            # 도착했을 때 대각 (2, 위 옆으로 벽이 없을 때)
            # 대각선 세로
            # 대각선 가로
            # 대각선 대각
            if bricks[y - 1][x] == 1 or bricks[y][x - 1] == 1:
                continue
            dp[y][x][2] += (dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2])

    print(sum(dp[N][N]))

if __name__=="__main__":
    main()
