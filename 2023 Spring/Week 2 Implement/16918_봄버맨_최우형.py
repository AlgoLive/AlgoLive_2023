import sys
from collections import deque

R, C, N = map(int, sys.stdin.readline().split())
graph = [['0' for _ in range(C)] for _ in range(R)]
queue = deque()
move = [(0, 1), (0, -1), (-1, 0), (1, 0)]
for i in range(R):
    graph[i] = list(sys.stdin.readline().rstrip())

for i in range(R):
    for j in range(C):
        if graph[i][j] == 'O':
            graph[i][j] = 0
        else:
            graph[i][j] = -1

for k in range(1, N + 1):
    # 짝수일때 -1 즉 빈칸에 폭탄 놓기
    if k % 2 == 0:
        for i in range(R):
            for j in range(C):
                if graph[i][j] == -1:
                    graph[i][j] = k
    # 홀수일때
    elif k % 2 == 1 and k != 1:
        for i in range(R):
            for j in range(C):
                if graph[i][j] == k - 3:
                    queue.append((i, j))
        while queue:
            x, y = queue.popleft()
            graph[x][y] = -1
            for dx, dy in move:
                if 0 <= x + dx < R and 0 <= y + dy < C:
                    graph[x + dx][y + dy] = -1

for i in range(R):
    for j in range(C):
        if graph[i][j] == -1:
            print('.', end='')
        else:
            print('O', end='')
    print()

# 0초 0초 폭탄
# 1초 ---
# 2초 2초 폭탄
# 3초 3-3 = 0초 폭탄 펑
# 4초 4초 폭탄
# 5초 5-3 = 2초 폭탄 펑
# 6초 6초 폭탄
# 7초 4초폭탄 펑
# 8초 8초 폭탄 설치
# 9초 6초 폭탄 펑