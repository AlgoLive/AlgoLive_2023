import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

graph = [[0 for _ in range(M)] for _ in range(N)]

for i in range(N):
    graph[i] = list(map(int, sys.stdin.readline().split(' ')))

move = [(0, 1), (0, -1), (1, 0), (-1, 0)]
queue = deque()
time = 0

# TODO!! BFS활용하여 바깥거 정보 가져오기! 바깥 정보 업데이트!
# 치즈 : 1 빈칸 0 외부 공기 -1로 설정

while True:
    visited = [[False for _ in range(M)] for _ in range(N)]

    queue.append((0, 0))
    while queue:
        x, y = queue.popleft()
        if not visited[x][y] and graph[x][y] < 1:
            graph[x][y] = -1
            visited[x][y] = True
            for dx, dy in move:
                if 0 <= x + dx < N and 0 <= y + dy < M:
                    if graph[x + dx][y + dy] < 1:
                        queue.append((x + dx, y + dy))

    cheeseQueue = deque()
    cheeseQueue.clear()

    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                cnt = 0
                for dx, dy in move:
                    if 0 <= i + dx < N and 0 <= j + dy < M:
                        if graph[i + dx][j + dy] == -1:
                            cnt += 1
                if cnt >= 2:
                    cheeseQueue.append((i, j))

    while cheeseQueue:
        x, y = cheeseQueue.popleft()
        graph[x][y] = -1

    time += 1

    breaker = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                breaker = 1

    if breaker == 0:
        break

print(time)
