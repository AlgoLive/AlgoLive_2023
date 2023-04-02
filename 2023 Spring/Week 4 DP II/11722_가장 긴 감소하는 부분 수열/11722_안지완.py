n = int(input())
arr = list(map(int, input().split()))
dp = [0 for _ in range(n)]

dp[0] = 1

for i in range(1,n):
    val = 0
    for j in range(i):
        if arr[i] < arr[j]:
            if dp[j] > val:
                val = dp[j]
    dp[i] = val + 1

print(sorted(dp, reverse=True)[0])
