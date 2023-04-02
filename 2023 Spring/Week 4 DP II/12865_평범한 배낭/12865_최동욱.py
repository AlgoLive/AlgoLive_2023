
# 0 -> kg, 1 -> val
def sol(N, K, jewels):
    his = [[0 for _ in range(K + 1)] for _ in range(N)]

    for j in range(K + 1):
        if jewels[0][0] <= j:
            his[0][j] = jewels[0][1]

    for i in range(1, N):
        for j in range(K + 1):
            if jewels[i][0] <= j:
                his[i][j] = max(his[i-1][j - jewels[i][0]] + jewels[i][1], his[i-1][j])
            else:
                his[i][j] = his[i-1][j]
    return his[N-1][K]


if __name__ == "__main__":
    N, K = map(int, input().split())
    jewels = []
    for _ in range(N):
        jewels.append(list(map(int, input().split())))

    print(sol(N, K, jewels))