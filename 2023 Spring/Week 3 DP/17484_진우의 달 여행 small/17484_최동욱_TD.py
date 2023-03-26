import sys
sys.setrecursionlimit(10 ** 6) # 숫자는 예시

memo = [[[] for _ in range(1000)] for _ in range(1000)]
N, M = map(int, input().split())  # 2 <= N, M <= 6 / NxM matrix
matrix = [[] for _ in range(N)]

for i in range(N):
    matrix[i] = list(map(int, input().split()))


def dp(y, x):
    global memo
    global matrix
    global N, M


    if memo[y][x]:
        return memo[y][x]

    if y == 0:
        return matrix[0][x]

    elif y == 1:
        if x == 0:
            memo[y][x] = dp(0, 1) + matrix[1][0], \
                         dp(0, 0) + matrix[1][0], \
                         9999999
        elif x == M - 1:
            memo[y][x] = 9999999, \
                         dp(0, x) + matrix[1][x], \
                         dp(0, x - 1) + matrix[1][x]
        else:
            memo[y][x] = dp(0, x + 1) + matrix[1][x], \
                         dp(0, x) + matrix[1][x], \
                         dp(0, x - 1) + matrix[1][x]

        return memo[y][x]

    else:

        if x == 0:
            memo[y][x] = min(dp(y - 1, x + 1)[1], dp(y - 1, x + 1)[2]) + matrix[y][x], \
                         dp(y - 1, x)[0] + matrix[y][x], \
                         9999999
        elif x == M - 1:
            memo[y][x] = 9999999, \
                         dp(y - 1, x)[2] + matrix[y][x], \
                         min(dp(y - 1, x - 1)[0], dp(y - 1, x - 1)[1]) + matrix[y][x]
        else:
            memo[y][x] = min(dp(y - 1, x + 1)[1], dp(y - 1, x + 1)[2]) + matrix[y][x], \
                         min(dp(y - 1, x)[0], dp(y - 1, x)[2]) + matrix[y][x],\
                         min(dp(y - 1, x - 1)[0], dp(y - 1, x - 1)[1]) + matrix[y][x]

        return memo[y][x]


if __name__ == "__main__":
    ans_list = []
    for x in range(M):
        for v in dp(N-1, x):
            ans_list.append(v)

    print(min(ans_list))


# 최대한 단계적으로 올라가야하는구나
# 테스트 케이스를 많이 넣어봐야하는구나 생각이 들었다
