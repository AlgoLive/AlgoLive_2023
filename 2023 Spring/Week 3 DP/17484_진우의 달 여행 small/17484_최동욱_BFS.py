from collections import deque

def go_to_moon(matrix):
    ds = [(-1, 1), (0, 1), (1, 1)]
    distances = []
    q = deque()
    for x in range(M):
        q.append((x, 0, matrix[0][x], 0)) # (x, y, value, direction)

    while q:
        cur_x, cur_y, cur_val, cur_dir = q.popleft()
        for i, d in enumerate(ds):
            dx, dy = d
            next_x, next_y = cur_x + dx, cur_y + dy
            if 0 <= next_x < M and 0 <= next_y < N:
                if i != cur_dir or cur_y == 0:
                    if next_y == N-1:
                        distances.append(cur_val + matrix[next_y][next_x])
                    q.append((next_x, next_y, cur_val + matrix[next_y][next_x], i))

    return min(distances)


if __name__ == "__main__":
    N, M = map(int, input().split()) # 2 <= N, M <= 6 / NxM matrix
    matrix = [[] for _ in range(N)]
    for i in range(N):
        matrix[i] = list(map(int, input().split()))

    print(go_to_moon(matrix))


