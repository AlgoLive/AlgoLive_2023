import sys
from collections import deque

N = int(sys.stdin.readline())

graph = [[0 for col in range(N)] for row in range(N)]
visited = [[False for col in range(N)] for row in range(N)]

for i in range(N):
    graph[i] = list(map(int, list(sys.stdin.readline().rstrip())))


# 큐의 처음은 0,0이다. 여기서 출발한다.
queue = deque()

# cnt 개수를 세기위한 변수
cnt = list()

for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            visited[i][j] = True

            if graph[i][j]:
                cnt.append(0)
                queue.append((i, j))

                # 큐를 선회
                while queue:
                    v = queue.popleft()
                    cnt[-1] += 1


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
                            if graph[a][b] and not visited[a][b]:
                                queue.append((a, b))
                                visited[a][b] = True

print(len(cnt))
cnt.sort()
for i in cnt:
    print(i)
