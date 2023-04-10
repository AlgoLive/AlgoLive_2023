import sys

N = int(sys.stdin.readline())
mat = [list(map(int, sys.stdin.readline().split(' '))) for _ in range(N)]
next_xy = [[0, 0], [0, 1], [1, 0], [1, 1]]
answer = 0


def dnq(n):
    global answer
    next_n = n // 2

    for i in range(next_n):
        for j in range(next_n):
            second_num = []
            for dx, dy in next_xy:
                second_num.append(mat[2 * i + dx][2 * j + dy])
            second_num.sort()
            mat[i][j] = second_num[-2]
            if n == 2:
                answer = second_num[-2]
                return

    dnq(next_n)


dnq(N)
print(answer)
