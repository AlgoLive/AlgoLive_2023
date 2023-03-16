import sys
from collections import deque

N = int(sys.stdin.readline())

graph = [[0 for col in range(N)] for row in range(N)]

for i in range(N):
    graph[i] = list(list(sys.stdin.readline().rstrip()))

# 큐의 처음은 0,0이다. 여기서 출발한다.
queue = deque()

# cnt 개수를 세기위한 변수
# 적록 색약이므로 RGB -> RRB / G를 R로

cnt = list()

for n in range(2):

    visited = [[False for col in range(N)] for row in range(N)]

    if n == 1:
        for i in range(N):
            for j in range(N):
                if graph[i][j] == 'G':
                    graph[i][j] = 'R'

    cnt.append(0)
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                visited[i][j] = True

                if graph[i][j]:
                    cnt[-1] += 1
                    queue.append((i, j))

                    # 큐를 선회
                    while queue:
                        v = queue.popleft()

                        for k in range(4):
                            if k == 0:
                                a, b = v
                                a += 1
                            if k == 1:
                                a, b = v
                                b -= 1
                            if k == 2:
                                a, b = v
                                a -= 1
                            if k == 3:
                                a, b = v
                                b += 1
                            if -1 < a < N and -1 < b < N:
                                if graph[a][b] == graph[i][j] and not visited[a][b]:
                                    queue.append((a, b))
                                    visited[a][b] = True
for i in cnt:
    print(i, end=" ")

