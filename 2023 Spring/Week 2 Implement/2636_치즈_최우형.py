import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

graph = [[0 for _ in range(M)] for _ in range(N)]
move = [(0, 1), (0, -1), (1, 0), (-1, 0)]
for i in range(N):
    graph[i] = list(map(int, sys.stdin.readline().split(' ')))

queue = deque()
time = 0
while True:
    time += 1
    visited = [[False for _ in range(M)] for _ in range(N)]
    queue.append((0, 0))
    while queue:
        x, y = queue.popleft()
        if not visited[x][y] and graph[x][y] < 1:
            visited[x][y] = True
            graph[x][y] = -1
            for dx, dy in move:
                if 0 <= x + dx < N and 0 <= y + dy < M:
                    if graph[x+dx][y+dy] < 1 and not visited[x+dx][y+dy]:
                        queue.append((x + dx, y + dy))

    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                for dx, dy in move:
                    if 0 <= i + dx < N and 0 <= j + dy < M:
                        if graph[i + dx][j + dy] == -1:
                            queue.append((i, j))
                            break

    numOfCheese = len(queue)
    while queue:
        x, y = queue.popleft()
        graph[x][y] = -1

    loopOut = True

    for i in range(N):
        for j in range(M):
            if graph[i][j] > 0:
                loopOut = False
    if loopOut:
        break
print(time)
print(numOfCheese)
