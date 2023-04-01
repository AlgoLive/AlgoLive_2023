n,t = map(int, input().split())
test = [(0,0)]
dp = [[0 for _ in range(10001)] for _ in range(101)]

for _ in range(n):
    time, grade = map(int,input().split())
    test.append((time,grade))

for i in range(1,n+1):
    for j in range(1,t+1):
        if j >= test[i][0]:
            dp[i][j] = max(dp[i-1][j-test[i][0]] + test[i][1], dp[i-1][j])
        else:
            dp[i][j] = dp[i-1][j]

print(dp[n][t])


