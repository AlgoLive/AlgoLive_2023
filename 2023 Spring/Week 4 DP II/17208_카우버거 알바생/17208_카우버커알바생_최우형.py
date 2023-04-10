# 17208번 카우버거 알바생 / DP, 배낭
import sys

# 만들어논 치즈버거 감자튀김

N, M, K = map(int, sys.stdin.readline().split())

# M : 치즈버거
# K : 감자튀김

dp = [[[0 for _ in range(K+1)] for _ in range(M+1)] for _ in range(N)]
order = [[] for _ in range(N)]
for i in range(N):
    order[i] = list(map(int, sys.stdin.readline().split()))

# dp[i번째 주문][M, 치즈버거][K, 감자튀김]

for i in range(N):
    for j in range(1, M+1):
        for k in range(1, K+1):
            if i == 0:
                if j - order[i][0] >= 0 and k - order[i][1] >= 0:
                    dp[i][j][k] = 1
            elif j - order[i][0] == 0 and k - order[i][1] == 0:
                dp[i][j][k] = 1
            elif j - order[i][0] > 0 and k - order[i][1] > 0:
                dp[i][j][k] = max(dp[i - 1][j - order[i][0]][k - order[i][1]] + 1, dp[i-1][j][k])
            else:
                dp[i][j][k] = dp[i-1][j][k]

answer = 0
for i in range(N):
    for j in range(M+1):
        for k in range(K+1):
            answer = max(answer, dp[i][j][k])

print(answer)