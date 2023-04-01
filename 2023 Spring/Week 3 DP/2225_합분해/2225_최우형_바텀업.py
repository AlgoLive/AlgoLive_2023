import sys
import math

N, K = map(int, sys.stdin.readline().split())
# dp[K][N]  더해서 0~ N 정수 K 개를 더하여 합이 N
dp = [[0 for _ in range(N + 1)] for _ in range(K + 1)]

for i in range(N):
    dp[1][i] = 1

for i in range(2, K + 1):
    for j in range(N+1):
        for k in range(j + 1):
            dp[i][j] += dp[i - 1][j - k]

print((dp[K][N]+1)%1000000000)
