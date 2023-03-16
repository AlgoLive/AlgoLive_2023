from collections import deque

M, N = map(int, input().split())
box = [[0 for _ in range(M)] for _ in range(N)]
visited = [[False for _ in range(M)] for _ in range(N)]
dxs = [1, 0, -1, 0]
dys = [0, 1, 0, -1]
tomato_locs = []


for y in range(N):
    box[y] = list(map(int, input().split()))
    for x in range(len(box[y])):
        if box[y][x] == 1:
            tomato_locs.append((x, y))

def bfs(tomato_locs):
    q = deque()

    for tomato_loc in tomato_locs:
        q.append(tomato_loc)
        visited[tomato_loc[1]][tomato_loc[0]] = True

    while q:
        loc_x, loc_y = q.popleft()

        for dx, dy in zip(dxs, dys):
            cx, cy = loc_x + dx, loc_y + dy
            if 0 <= cx < M and 0 <= cy < N:
                if box[cy][cx] == 0 and visited[cy][cx] is False:
                    box[cy][cx] = box[loc_y][loc_x] + 1
                    q.append((cx, cy))
                    visited[cy][cx] = True

    for y in range(len(visited)):
        for x in range(len(visited[y])):
            if visited[y][x] is False and box[y][x] == 0:
                print(-1)
                return

    tmp = []
    for y in box:
        tmp.append(max(y) - 1)

    print(max(tmp))


bfs(tomato_locs)