from collections import defaultdict

N = int(input())
papers = list()
res = defaultdict(int)
for _ in range(N):
    papers.append(list(map(int, input().split())))

def solve(start_x, start_y, length):
    global papers
    pivot = papers[start_y][start_x]
    divide = False

    for y in range(start_y, start_y + length):
        for x in range(start_x, start_x + length):
            if papers[y][x] != pivot:
                divide = True

    if divide is True:
        new_len = length//3
        start_points = [[start_x + i, start_y + j] for i in [0, new_len, 2*new_len]
                                                        for j in [0, new_len, 2*new_len]]
        for x, y in start_points:
            solve(x, y, new_len)
    else:
        res[pivot] += 1


if __name__ == "__main__":
    solve(0, 0, N)
    print(res[-1])
    print(res[0])
    print(res[1])
