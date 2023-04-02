# 9084 동전 / DP, 배낭문제
import sys

T = int(sys.stdin.readline().rstrip())
answer = []

for t in range(T):
    N = int(sys.stdin.readline().rstrip())
    coin = list(map(int, sys.stdin.readline().rstrip().split(' ')))
    M = int(sys.stdin.readline().rstrip())

    dp = [[0 for _ in range(M + 1)] for _ in range(N)]

    for i in range(1, M + 1):
        if i % coin[0] == 0 and coin[0] <= i:
            dp[0][i] = 1
    for i in range(N):
        dp[i][0] = 0
    for i in range(1, N):
        for j in range(1, M + 1):
            if j - coin[i] > 0:
                dp[i][j] = dp[i][j - coin[i]] + dp[i-1][j]
            elif j - coin[i] == 0 :
                dp[i][j] = dp[i - 1][j] + 1
            else:
                dp[i][j] = dp[i - 1][j]

    answer.append(dp[N - 1][M])

for i in answer:
    print(i)
