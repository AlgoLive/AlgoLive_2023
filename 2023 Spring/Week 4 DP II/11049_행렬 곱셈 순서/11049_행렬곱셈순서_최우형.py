import sys

N = int(sys.stdin.readline())
matrix = [[]]
dp = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(N):
    matrix.append(list(map(int, sys.stdin.readline().split(' '))))

# 5 3 2 5 2 6
# 5 3 6 3 2 6

# 5 3
# 3 2
# 2 6
# 6 y

# [1][1]
# [2][2] ... 그 항

# [1][2] 1~ 2
# [2][3] 바로 구할 수 있음!!
# [3][4]

# [1][3] 1 ~ 3
# [1][1] + [2][3], [1][2] + [3][3]

# [1][5] 를 구하고 싶다..
# [1][1] + [2][5] , [1][2] + [3][5], [1][3] + [4][5], [1][4] + [5][5]

for i in range(1, N):
    for j in range(1, N - i + 1):
        dp[j][j + i] = 2147483647
        for k in range(j, j + i):
            dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + matrix[j][0] * matrix[k][1] * matrix[j + i][1])

print(dp[1][N])
