import sys

N, K = map(int, sys.stdin.readline().split(' '))

weight_value = [0 for _ in range(N)]

for i in range(N):
    weight_value[i] = list(map(int, sys.stdin.readline().split(' ')))

dp = [[0 for _ in range(K)] for _ in range(N)]
# dp[n : ~까지 물품 중][무게 제한]

for i in range(K):
    if weight_value[0][0] <= K:
        dp[0][i] = weight_value[0][1]

for i in range(1, N):
    for j in range(K):
        if weight_value[i][0] < K:
            dp[i][j] = weight_value[i][1]
            
print(dp[N][K])            
