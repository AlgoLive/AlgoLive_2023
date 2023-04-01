import sys
sys.setrecursionlimit(10000)

N = int(sys.stdin.readline().rstrip())

graph = list()
dp = [[1001 for _ in range(3)] for _ in range(N)]

for i in range(N):
    graph.append(list(map(int, sys.stdin.readline().split())))

# 0 : R || 1 : G || 2 : B
for i in range(3):
    dp[0][i] = graph[0][i]


def dpf(i, j):
    global dp
    if dp[i][j] == 1001:
        if i > 0:
            if j == 0:
                # i 번째 집을 0 (R)로 칠하는 경우
                dp[i][j] = graph[i][j] + min(dpf(i - 1, 1), dpf(i - 1, 2))
                return dp[i][j]

            elif j == 1:
                # i 번째 집을 1 (G)로 칠하는 경우

                dp[i][j] = graph[i][j] + min(dpf(i - 1, 0), dpf(i - 1, 2))
                return dp[i][j]
            elif j == 2:
                # i 번째 집을 2 (B)로 칠하는 경우
                dp[i][j] = graph[i][j] + min(dpf(i - 1, 0), dpf(i - 1, 1))
                return dp[i][j]

        if i == 0:
            return dp[i][j]
    else:
        return dp[i][j]


for i in range(3):
    dpf(N - 1, i)

print(min(dp[N - 1]))
