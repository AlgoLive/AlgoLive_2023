import sys

n = int(input())
m = int(input())
INF = sys.maxsize
dp = [[INF for _ in range(n)] for _ in range(n)]

for _ in range(m):
    a,b,c = map(int,input().split())
    if dp[a-1][b-1] > c:
        dp[a-1][b-1] = c

for i in range(n):
    dp[i][i] = 0

for k in range(n):
    for i in range(n):
        for j in range(n):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

for i in range(n):
    for j in range(n):
        if dp[i][j] == INF:
            print(0, end = " ")
            continue
        print(dp[i][j], end = " ")
    print()