t = int(input())

def sol():
    n = int(input())
    sticker = [[] for _ in range(2)]
    dp = [[0 for _ in range(2)] for _ in range(n)]
    for i in range(2):
        sticker[i] = list(map(int, input().split()))

    for i in range(n):
        if i == 0:
            dp[i][0] = sticker[0][i]
            dp[i][1] = sticker[1][i]
        elif i == 1:
            dp[i][0] = dp[i-1][1] + sticker[0][i]
            dp[i][1] = dp[i-1][0] + sticker[1][i]
        else:
            dp[i][0] = max(dp[i-1][1] + sticker[0][i], dp[i-2][1] + sticker[0][i])
            dp[i][1] = max(dp[i-1][0] + sticker[1][i], dp[i-2][0] + sticker[1][i])

    print(max(dp[n-1][0], dp[n-1][1]))


for _ in range(t):
    sol()