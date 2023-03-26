import sys

sys.setrecursionlimit(45000)

N, K = map(int, sys.stdin.readline().split())
# dp[K][N]  더해서 0~ N 정수 K 개를 더하여 합이 N
dp = [[0 for _ in range(N + 1)] for _ in range(K + 1)]

# dp[K][N] = dp[K-1][N-0] + dp[K-1][N-1] + dp[K-1][N-3] + ... dp[K-1][1] 이란 말이오!

for i in range(N+1):
    dp[1][i] = 1


def dpfunction(k, n):
    if k > 1:
        for j in range(0, n + 1):
            if dp[k-1][j] == 0:
                dp[k][n] += dpfunction(k-1,j)
            elif dp[k-1][j] != 0:
                dp[k][n] += dp[k-1][j]
    return dp[k][n]


answer = dpfunction(K, N)
print(answer % 1000000000)
