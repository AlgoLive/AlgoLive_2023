from collections import deque

N = int(input())
town_map = [[0 for _ in range(N)] for _ in range(N)]
visited = [[False for _ in range(N)] for _ in range(N)]
town_list = []
dys = [0, 1, 0, -1]
dxs = [1, 0, -1, 0]

for y in range(N):
    line = input()
    for x in range(N):
        town_map[y][x] = int(line[x])

def bfs(y: int, x: int):
    global town_list

    house_cnt = 0
    q = deque()
    q.append((y, x))
    house_cnt += 1

    while q:
        loc_y, loc_x = q.popleft()
        visited[loc_y][loc_x] = True
        for dx, dy in zip(dxs, dys):
            nx, ny = loc_x + dx, loc_y + dy
            if 0 <= nx < N and 0 <= ny < N:
                if town_map[ny][nx] == 1 and visited[ny][nx] is False:
                    visited[ny][nx] = True
                    house_cnt += 1
                    q.append((ny, nx))

    town_list.append(house_cnt)


for y in range(N):
    for x in range(N):
        if town_map[y][x] == 1 and visited[y][x] is False:
            bfs(y, x)

print(len(town_list))
for n in sorted(town_list):
    print(n)
