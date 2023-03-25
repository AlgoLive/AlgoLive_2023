n = int(input())
rgb = [[] for _ in range(n)]
dp = [[0 for _ in range(3)] for _ in range(n)]

for i in range(n):
    rgb[i] = list(map(int,input().split()))

for i in range(n):
    if i == 0:
        dp[i][0] = rgb[i][0]
        dp[i][1] = rgb[i][1]
        dp[i][2] = rgb[i][2]
    else:
        dp[i][0] = rgb[i][0] + min(dp[i-1][1],dp[i-1][2])
        dp[i][1] = rgb[i][1] + min(dp[i-1][0],dp[i-1][2])
        dp[i][2] = rgb[i][2] + min(dp[i-1][0],dp[i-1][1])

print(min(dp[n-1][0], dp[n-1][1], dp[n-1][2]))



