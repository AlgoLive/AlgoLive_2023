dx = [0, 1, 0, 1]
dy = [0, 0, 1, 1]


def solve(pixels):
    length = len(pixels)
    pooling_points = [[[i, j] for i in range(0, length, 2)]
                    for j in range(0, length, 2)]
    pooling_map = list()

    for line in pooling_points:
        temp = list()
        for x, y in line:
            temp.append(pooling(pixels, x, y))
        pooling_map.append(temp)

    if len(pooling_map) == 1:
        return pooling_map[0][0]
    else:
        ans = solve(pooling_map)
        return ans


def pooling(pixels, start_x, start_y):
    global dx, dy
    temp = list()

    for x, y in zip(dx, dy):
        temp.append(pixels[start_y + y][start_x + x])

    return sorted(temp)[2]


if __name__ == "__main__":
    N = int(input())
    pixels = list()
    for _ in range(N):
        pixels.append(list(map(int, input().split())))

    print(solve(pixels))