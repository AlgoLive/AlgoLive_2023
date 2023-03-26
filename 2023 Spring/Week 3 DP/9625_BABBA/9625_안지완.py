k = int(input())
dp = [[0 for _ in range(2)] for _ in range(45)]

dp[0][0] = 1 #B
dp[0][1] = 0 #A

dp[1][0] = 1
dp[1][1] = 1

for i in range(2,k):
    dp[i][0] = dp[i-1][0] + dp[i-2][0]
    dp[i][1] = dp[i-1][0]

print(str(dp[k-1][1]) + " " + str(dp[k-1][0]))


