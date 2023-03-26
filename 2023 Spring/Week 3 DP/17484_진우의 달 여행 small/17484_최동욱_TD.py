memo = [[[] for _ in range(1000)] for _ in range(1000)]
N, M = map(int, input().split())  # 2 <= N, M <= 6 / NxM matrix
matrix = [[] for _ in range(N)]

for i in range(N):
    matrix[i] = list(map(int, input().split()))

def dp(x, y):
    global memo
    global matrix
    global N, M

    if memo[y][x]:
        return memo[y][x]

    if y == 0:
        return (matrix[0][x], 0)

    elif y == 1:
        if x == 0:
            return ((dp[0][1][0] + matrix[1][0], 1), (dp[0][0][0] + matrix[1][0], 2))
        elif x == M-1:
            return ((dp[0][x][0] + matrix[1][x], 2), (dp[0][x-1][0] + matrix[1][x], 3))
        else:
            return ((dp[0][x+1][0] + matrix[1][x], 1), (dp[0][x][0] + matrix[1][x], 2), (dp[0][x+1][0] + matrix[1][x], 3))

    else:
        if x == 0:
            return ((dp(x, y-1), dp(x+1, y-1)))
        elif x == M - 1:
            return ((dp(x-1, y-1), dp(x, y-1)))
        else:
            return ((dp(x-1, y-1), dp(x, y-1), dp(x+1, y-1))


    # dir -> 1: left, 2: direct, 3: right
    for y in range(N):
        for x in range(M):
            if y == 0:
                dp_table[y][x] = [(matrix[y][x], 0)]

            elif y == 1:
                current = matrix[1][x]
                if x == 0:
                    temp_up, temp_right = matrix[0][x], matrix[0][x + 1]
                    dp_table[1][x] = [(temp_up + current, 2), (temp_right + current, 1)]

                elif x == M - 1:
                    temp_left, temp_up = matrix[0][x - 1], matrix[0][x]
                    dp_table[1][x] = [(temp_left + current, 3), (temp_up + current, 2)]

                else:
                    temp_left, temp_up, temp_right = matrix[0][x - 1], matrix[0][x], matrix[0][x + 1]
                    dp_table[1][x] = [(temp_left + current, 3), (temp_up + current, 2), (temp_right + current, 1)]

            elif y >= 2:
                current = matrix[y][x]
                if x == 0:
                    temp_up, temp_right = dp_table[y - 1][x], dp_table[y - 1][x + 1]
                    min_up, min_right = (9999999, 0), (9999999, 0)

                    for info in temp_up:
                        if min_up[0] > info[0] + current:
                            if info[1] == 2:
                                continue
                            else:
                                min_up = (info[0] + current, 2)

                    for info in temp_right:
                        if min_right[0] > info[0] + current:
                            if info[1] == 1:
                                continue
                            else:
                                min_right = (info[0] + current, 1)

                    dp_table[y][x] = [min_up, min_right]

                elif x == M - 1:
                    temp_left, temp_up = dp_table[y - 1][x - 1], dp_table[y - 1][x]
                    min_left, min_up = (9999999, 0), (9999999, 0)

                    for info in temp_left:
                        if min_left[0] > info[0] + current:
                            if info[1] == 3:
                                continue
                            else:
                                min_left = (info[0] + current, 3)

                    for info in temp_up:
                        if min_up[0] > info[0] + current:
                            if info[1] == 2:
                                continue
                            else:
                                min_up = (info[0] + current, 2)

                    dp_table[y][x] = [min_left, min_up]

                else:
                    temp_left, temp_up, temp_right = dp_table[y - 1][x - 1], dp_table[y - 1][x], dp_table[y - 1][x + 1]
                    min_left, min_up, min_right = (9999999, 0), (9999999, 0), (9999999, 0)

                    for info in temp_left:
                        if min_left[0] > info[0] + current:
                            if info[1] == 3:
                                continue
                            else:
                                min_left = (info[0] + current, 3)

                    for info in temp_up:
                        if min_up[0] > info[0] + current:
                            if info[1] == 2:
                                continue
                            else:
                                min_up = (info[0] + current, 2)

                    for info in temp_right:
                        if min_right[0] > info[0] + current:
                            if info[1] == 1:
                                continue
                            else:
                                min_right = (info[0] + current, 1)

                    dp_table[y][x] = [min_left, min_up, min_right]

    min_route = 9999999
    for routes in dp_table[N-1]:
        for info in routes:
            if min_route > info[0]:
                min_route = info[0]

    return min_route


if __name__ == "__main__":
    N, M = map(int, input().split())  # 2 <= N, M <= 6 / NxM matrix
    matrix = [[] for _ in range(N)]

    for i in range(N):
        matrix[i] = list(map(int, input().split()))

    print(travel_to_moon(M, N, matrix))


# 최대한 단계적으로 올라가야하는구나
# 테스트 케이스를 많이 넣어봐야하는구나 생각이 들었다
