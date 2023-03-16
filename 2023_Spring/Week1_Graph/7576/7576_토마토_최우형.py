import sys
from collections import deque

# M 개씩 N줄의 토마토 정보
# 1 : 익은 토마토 / 0 안익 토마토, -1 : 토마토 없음

M, N = map(int, sys.stdin.readline().split())

graph = [[0 for col in range(N)] for row in range(N)]

for i in range(N):
    graph[i] = list(map(int, (sys.stdin.readline().split())))

queue = deque()

cnt = list()

for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            queue.append((i, j, 1))

visited = [[False for col in range(M)] for row in range(N)]

ans = int()

#익지 않은 토마토가 있으면 isall 0 -> 0
isAll = 0
for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            isAll = 1

for i in range(N):
    for j in range(M):
        if graph[i][j] >= 1 and not visited[i][j]:
            visited[i][j] = True
            while queue:
                (x, y, n) = queue.popleft()

                for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                    if 0 <= x + dx < N and 0 <= y + dy < M:
                        if graph[x + dx][y + dy] >= 0 and not visited[x + dx][y + dy]:
                            graph[x + dx][y + dy] = 1
                            visited[x + dx][y + dy] = True
                            queue.append((x + dx, y + dy, n + 1))
                            ans = n

#익지 않은 토마토가 있으면 isall 0 -> 0
end = 0
for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            end = 1


if isAll == 0:
    print(0)
elif end == 1:
    print(-1)
else:
    print(ans)
