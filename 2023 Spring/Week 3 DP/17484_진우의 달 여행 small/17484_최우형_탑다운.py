import sys

sys.setrecursionlimit(45000)

N, M = map(int, sys.stdin.readline().split())

graph = [[10000 for _ in range(M)] for _ in range(N)]

for i in range(N):
    graph[i] = list(map(int, sys.stdin.readline().split(' ')))

# dp[K][N]  더해서 0~ N 정수 K 개를 더하여 합이 N
dp = [[[10000 for _ in range(3)] for _ in range(M)] for _ in range(N)]

# N, M, 방향 ; 방향은 0,1,2 순서대로 좌, 중, 우
# ~~에서 온것 이라는 의미 -> 첫줄은 방향이 의미가 없으므로 모두 동일하게 작성
# N, M, 0 -> N -1, M -1, (0 1 2 중 큰거)
# N, M, 1 -> N -1, M   , (0 1 2 중 큰거)
# N, M, 2 -> N -1, M +1, (0 1 2 중 큰거)
# 범위 조절도 해야함! 인덱스 0일때 마지막일때!

for i in range(M):
    for j in range(3):
        dp[0][i][j] = graph[0][i]


def dpfun(n, m, k):
    if n > 0:
        if k == 0:
            if m > 0:
                dp[n][m][k] = graph[n][m] + min(dpfun(n - 1, m - 1, 1), dpfun(n - 1, m - 1, 2))
                return dp[n][m][k]
        elif k == 1:
            dp[n][m][k] = graph[n][m] + min(dpfun(n - 1, m, 0), dpfun(n - 1, m, 2))
            return dp[n][m][k]
        elif k == 2:
            if m < M - 1:
                dp[n][m][k] = graph[n][m] + min(dpfun(n - 1, m + 1, 1), dpfun(n - 1, m + 1, 0))
                return dp[n][m][k]
    return dp[n][m][k]


answer = []
for i in range(M):
    for j in range(3):
        answer.append(dpfun(N - 1, i, j))

print(min(answer))

