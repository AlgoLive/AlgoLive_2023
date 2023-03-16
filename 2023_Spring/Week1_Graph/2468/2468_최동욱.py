from collections import deque

N = int(input())
area = [[0 for _ in range(N)] for _ in range(N)]
dxs = [1, 0, -1, 0]
dys = [0, 1, 0, -1]
max_h = 0
min_h = 101
max_area_num = 0


for y in range(N):
    area[y] = list(map(int, input().split()))
    if max(area[y]) > max_h:
        max_h = max(area[y])
    if min(area[y]) < min_h:
        min_h = min(area[y])

h_list = [n for n in range(min_h - 1, max_h + 1)]


def bfs(x, y, h):
    global count
    q = deque()
    q.append((x, y))

    while q:
        loc_x, loc_y = q.popleft()
        visited[loc_y][loc_x] = True

        for dx, dy in zip(dxs, dys):
            nx, ny = loc_x + dx, loc_y + dy
            if 0 <= nx < N and 0 <= ny < N:
                if visited[ny][nx] is False and area[ny][nx] > h:
                    q.append((nx, ny))
                    visited[ny][nx] = True

    count += 1


for h in h_list:
    count = 0
    visited = [[False for _ in range(N)] for _ in range(N)]
    for y in range(N):
        for x in range(N):
            if visited[y][x] is False and area[y][x] > h:
                bfs(x, y, h)

    if max_area_num < count:
        max_area_num = count

print(max_area_num)
