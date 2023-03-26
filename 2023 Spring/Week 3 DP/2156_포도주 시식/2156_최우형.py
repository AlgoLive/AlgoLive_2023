import sys

# 포도주! 포도주!!

dp = [0 for _ in range(100001)]
n = int(sys.stdin.readline().rstrip())
grape = [0 for _ in range(n)]

for i in range(n):
    grape[i] = int(sys.stdin.readline().rstrip())

# 포도주 1개
dp[1] = grape[0]
if n >= 2:
    dp[2] = grape[0] + grape[1]
if n >= 3:
    dp[3] = max(dp[2], grape[1] + grape[2], dp[1] + grape[2])

for i in range(4, n+1):
    dp[i] = max(dp[i-1], dp[i-2] + grape[i-1], dp[i-3] + grape[i-1] + grape[i-2])

print(dp[n])