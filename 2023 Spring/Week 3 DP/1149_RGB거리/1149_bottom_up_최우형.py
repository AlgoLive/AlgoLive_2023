import sys

N = int(sys.stdin.readline().rstrip())

graph = list()
dp = [[1001 for _ in range(3)] for _ in range(N)]

for i in range(N):
    graph.append(list(map(int, sys.stdin.readline().split())))

# 0 : R || 1 : G || 2 : B
for i in range(3):
    dp[0][i] = graph[0][i]

for i in range(1, N):
    for j in range(3):
        if j == 0:
            # i 번째 집을 0 (R)로 칠하는 경우
            dp[i][j] = graph[i][j] + min(dp[i - 1][1], dp[i - 1][2])
        elif j == 1:
            # i 번째 집을 1 (G)로 칠하는 경우
            dp[i][j] = graph[i][j] + min(dp[i - 1][0], dp[i - 1][2])
        elif j == 2:
            # i 번째 집을 2 (B)로 칠하는 경우
            dp[i][j] = graph[i][j] + min(dp[i - 1][0], dp[i - 1][1])

print(min(dp[N - 1]))