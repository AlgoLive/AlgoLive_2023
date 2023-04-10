import sys

# A1 A2 A3 ...  B
# m1 m2 m3 ...  M
# c1 c2 c3 ...

N, M = map(int, sys.stdin.readline().split(' '))

memory = [0] + list(map(int, sys.stdin.readline().split(' ')))
cost = [0] + list(map(int, sys.stdin.readline().split(' ')))
total_cost = sum(cost)

dp = [[0 for _ in range(total_cost + 1)] for _ in range(N + 1)]
answer = 1000000

for j in range(total_cost):
    if j >= cost[1]:
        dp[1][j] = memory[1]
        if dp[1][j] >= M:
            answer = min(answer, j)
    else:
        dp[1][j] = 0
        if dp[1][j] >= M:
            answer = min(answer, j)

for i in range(1, N + 1):
    for j in range(1, total_cost + 1):
        if j - cost[i] >= 0:
            dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j])
            if dp[i][j] >= M:
                answer = min(answer, j)
        else:
            dp[i][j] = dp[i - 1][j]
            if dp[i][j] >= M:
                answer = min(answer, j)

print(answer)


