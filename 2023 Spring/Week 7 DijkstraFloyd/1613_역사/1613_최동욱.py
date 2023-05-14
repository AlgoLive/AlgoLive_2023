import sys
inf = int(1e9)
input = sys.stdin.readline


def solve(n, history):
    # for i in range(1, n+1):
    #     history[i][i] = 0
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if history[i][k] * history[k][j] > 0:
                    history[i][j] = history[i][k]
                else:
                    continue

    return history


if __name__ == "__main__":
    n, k = map(int, input().split())
    matrix = [[0 for _ in range(n+1)] for _ in range(n+1)]

    for _ in range(k):
        bef, aft = map(int, input().split())
        matrix[bef][aft] = 1
        matrix[aft][bef] = -1

    history = solve(n, matrix)

    s = int(input())
    for _ in range(s):
        case1, case2 = map(int, input().split())
        ans = history[case1][case2]
        if ans == 0:
            print(0)
        elif ans < 0:
            print(1)
        else:
            print(-1)

