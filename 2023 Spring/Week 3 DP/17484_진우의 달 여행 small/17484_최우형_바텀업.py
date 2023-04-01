import sys

N, M = map(int, sys.stdin.readline().split())

graph = list()
dp = [[[1000 for _ in range(3)] for _ in range(M)] for _ in range(N)]

for i in range(N):
    graph.append(list(map(int, sys.stdin.readline().split())))

for i in range(M):
    for j in range(3):
        dp[0][i][j] = graph[0][i]

for i in range(1, N):
    for j in range(M):
        for direction in range(3):
            if direction == 0:
                # 왼쪽에서 건너온 칸
                if j > 0:
                    dp[i][j][direction] = graph[i][j] + min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2])

            elif direction == 1:
                # 중간에서 건너온 칸:
                dp[i][j][direction] = graph[i][j] + min(dp[i - 1][j][0], dp[i - 1][j][2])
            elif direction == 2:
                # 우측에서 건너온 칸
                if j < M - 1:
                    dp[i][j][direction] = graph[i][j] + min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1])

answer = list()
for i in range(M):
    for j in range(3):
        answer.append(dp[N-1][i][j])

print(min(answer))