n = int(input())
glass = [0 for _ in range(n+1)]
dp = [0]

for i in range(1,n+1):
    glass[i] = int(input())

dp.append(glass[1])
if n>1:
    dp.append(glass[2]+glass[1])
for i in range(3,n+1):
    temp = []
    temp.append(glass[i] + glass[i-1] + dp[i-3])
    temp.append(glass[i] + dp[i-2])
    temp.append(dp[i-1])

    dp.append(sorted(temp, reverse=True)[0])

print(dp[n])


