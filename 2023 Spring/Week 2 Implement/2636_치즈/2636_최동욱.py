from collections import deque
import sys


def bfs(x, y, total_map):
    dxs = [1, 0, -1, 0]
    dys = [0, 1, 0, -1]
    visited = [[False for _ in range(N)] for _ in range(M)]
    q = deque()
    q.append((x, y))
    melt_index = []
    visited[y][x] = True

    while q:
        x, y = q.popleft()
        for dx, dy in zip(dxs, dys):
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < M:
                if visited[ny][nx] is False:
                    if total_map[ny][nx] == 1:
                        melt_index.append((nx, ny))
                        visited[ny][nx] = True
                    else:
                        q.append((nx, ny))
                        visited[ny][nx] = True


    return melt_index


def progress(total_map):
    # N 세로, M 가로, total_map 전체 맵, cheese_index 치즈 있는 인덱스
    time = 0
    remain = 0
    for i in total_map:
        remain += sum(i)

    while remain > 0:
        time += 1
        melt_count = 0
        remain = 0

        melt_index = bfs(0, 0, total_map)

        for index in melt_index:
            x, y = index
            total_map[y][x] = 0
            melt_count += 1

        for i in total_map:
            remain += sum(i)

    print(time, melt_count)


if __name__ == "__main__":
    input = sys.stdin.readline
    M, N = map(int, input().split())  # M 세로, N 가로

    total_map = [[] for _ in range(M)]

    for i in range(M):
        total_map[i] = list(map(int, input().split()))

    progress(total_map)
