# 14728 벼락치기
import sys

N, T = map(int, sys.stdin.readline().split())
KS = [[] for _ in range(N)]
answer = 0

for i in range(N):
    KS[i] = list(map(int, sys.stdin.readline().split()))

# K == 예상 공부 시간 / S == 배점

# dp[~번째 단원까지 포함한다][공부할 수 있는 총시간] = [점수(최대)]
dp = [[0 for _ in range(T + 1)] for _ in range(N)]

for i in range(N):
    for j in range(1, T + 1):
        if i == 0:
            if KS[0][0] <= j:
                dp[0][j] = KS[0][1]

        elif j - KS[i][0] == 0:
            dp[i][j] = max(dp[i - 1][j], KS[i][1])

        elif j - KS[i][0] > 0:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - KS[i][0]] + KS[i][1])
        else:
            dp[i][j] = dp[i - 1][j]

for i in range(N):
    for j in range(1, T + 1):
        answer = max(answer, dp[i][j])

print(answer)

for i in dp:
    print(i)
