import sys

paper = [[0 for _ in range(101)] for _ in range(101)]
area = 0

num = int(input())

for i in range(num):
    data = sys.stdin.readline().rstrip().split()
    x, y = int(data[0]), int(data[1])

    for m in range(x + 1, x + 11):
        for n in range(y + 1, y + 11):
            if paper[m][n] == 0:
                area += 1
                paper[m][n] = 1

print(area)