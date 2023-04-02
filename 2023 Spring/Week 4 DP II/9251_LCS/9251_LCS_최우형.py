#9251 LCS
import sys

first = list(sys.stdin.readline().rstrip())
second = list(sys.stdin.readline().rstrip())

# N * M 이라고 생각할 거임

N = len(first)
M = len(second)

dp = [[0 for _ in range(N)] for _ in range(M)]

for j in range(M):
    if first[0] == second[j]:
        dp[j][0] = 1
    else:
        if j > 0:
            dp[j][0] = dp[j - 1][0]

for i in range(1, N):
    for j in range(M):
        if j == 0:
            if first[i] == second[j]:
                dp[j][i] = 1
            else:
                dp[j][i] = dp[j][i - 1]
        elif j > 0:
            if first[i] == second[j]:
                dp[j][i] = dp[j - 1][i - 1] + 1
            else:
                dp[j][i] = max(dp[j][i - 1], dp[j - 1][i])

answer = 0
for i in range(M):
    for j in range(N):
        answer = max(answer, dp[i][j])

print(answer)
