import sys

(n, m, r) = map(int, sys.stdin.readline().split())

arr = [[16] * (n + 1) for _ in range(n + 1)]
itemNum = [16] + list(map(int, sys.stdin.readline().split()))
maxItem = []

for _ in range(r):
    (x, y, distance) = map(int, sys.stdin.readline().split())
    arr[x][y] = distance
    arr[y][x] = distance
for i in range(1, n + 1):
    arr[i][i] = 0


def printarray(array):
    print("------------------------")
    for i in array:
        for j in i:
            if j == 16:
                print("   ", end='')
            else:
                print(f"{j:>3}", end='')
        print()


#printarray(arr)

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if arr[i][k] < 16 and arr[k][j] < 16:
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j])

#printarray(arr)

for i in range(1, n + 1):
    itemBuffer = 0
    for j in range(1, n + 1):
        if arr[i][j] <= m:
            itemBuffer += itemNum[j]
    maxItem.append(itemBuffer)

print(max(maxItem))