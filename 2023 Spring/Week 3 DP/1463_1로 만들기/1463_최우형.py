import sys

dp = [0 for _ in range(1000003)]

dp[1] = 0
dp[2] = 1
dp[3] = 1

N = int(sys.stdin.readline().rstrip())

for i in range(4, N + 1):
    if i % 3 == 0 and i % 2 == 0:
        # 3가지 -> 최솟값 -->>
        dp[i] = min(dp[i - 1], dp[i // 3], dp[i // 2]) + 1
    elif i % 3 == 0:
        dp[i] = min(dp[i - 1], dp[i // 3]) + 1
    elif i % 2 == 0:
        dp[i] = min(dp[i - 1], dp[i // 2]) + 1

    else:
        dp[i] = dp[i - 1] + 1

print(dp[N])