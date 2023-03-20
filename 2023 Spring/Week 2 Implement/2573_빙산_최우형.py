import sys
from collections import deque

# 그래프 / bfs /

N, M = map(int, sys.stdin.readline().split())
graph = [[0 for _ in range(M)] for _ in range(N)]
queue = deque()
move = [(0, 1), (0, -1), (-1, 0), (1, 0)]
answer = 0
for i in range(N):
    graph[i] = list(map(int, sys.stdin.readline().split(' ')))

k = 0

while True:
    for i in range(N):
        for j in range(M):
            cnt = 0
            if graph[i][j] > 0:
                for dx, dy in move:
                    if graph[i + dx][j + dy] < 1 and 0 <= i + dx < N and 0 <= j + dy < M:
                        cnt += 1
                queue.append((i, j, cnt))

    while queue:
        x, y, subtract = queue.popleft()
        graph[x][y] -= subtract
        if graph[x][y] < 1:
            graph[x][y] = 0

    visited = [[False for _ in range(M)] for _ in range(N)]

    mass_queue = deque()
    depth = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] > 0 and not visited[i][j]:
                visited[i][j] = True
                mass_queue.append((i, j))
                depth += 1
                if depth == 2:
                    break
                while mass_queue:
                    visited_x, visited_y = mass_queue.popleft()
                    for dx, dy in move:
                        if 0 <= visited_x + dx < N and 0 <= visited_y + dy < M:
                            if not visited[visited_x + dx][visited_y + dy] and graph[visited_x + dx][visited_y + dy]:
                                visited[visited_x + dx][visited_y + dy] = True
                                mass_queue.append((visited_x + dx, visited_y + dy))
    if depth >= 2:
        answer = k + 1
        break
    if depth == 0:
        answer = 0
        break
    k += 1
print(answer)