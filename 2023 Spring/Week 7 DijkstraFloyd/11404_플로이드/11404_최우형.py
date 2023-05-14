import sys

INF = 1e9

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

graph = [[INF for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(m):
    a, b, c = map(int, sys.stdin.readline().rstrip().split(' '))
    graph[a][b] = min(graph[a][b], c)

for i in range(n + 1):
    graph[i][i] = 0

for i in range(1, n + 1):
    for j in range(1, n + 1):
        for k in range(1, n + 1):
            graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if graph[i][j] == INF:
            print(0, end=' ')
        else:
            print(graph[i][j], end=' ')
    print()