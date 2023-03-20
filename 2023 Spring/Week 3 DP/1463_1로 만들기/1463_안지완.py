n = int(input())

dp = [0,0]

for _ in range(2):
    dp.append(1)

for i in range(4,n+1):
    temp = []
    if i%3 == 0:
        temp.append(dp[i//3]+1)
    if i%2 == 0:
        temp.append(dp[i//2]+1)
    temp.append(dp[i-1]+1)
    dp.append(sorted(temp)[0])

print(dp[n])

