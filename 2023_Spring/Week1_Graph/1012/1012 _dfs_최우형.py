import sys
from collections import deque

T = int(sys.stdin.readline())

# 인접한 노드를 검색해야하믈 너비 우선 탐색 활용

def bfs(M, N, K):
    graph = [[0 for col in range(M)] for row in range(N)]
    visited = [[False for col in range(M)] for row in range(N)]

    for _ in range(K):
        x, y = map(int, sys.stdin.readline().split())
        graph[y][x] = 1

    # 방문한적이 없고, 1인곳을 방문!

    queue = deque()
    cnt = 0

    for j in range(N):
        for i in range(M):
            if not visited[j][i]:
                visited[j][i] = True

                if graph[j][i]:
                    cnt += 1
                    queue.append((j, i))

                    while queue:
                        v = queue.popleft()

                        for k in range(4):
                            if k == 0:
                                a = v[1] + 1
                                b = v[0]

                            if k == 1:
                                a, b = v[1], v[0] + 1

                            if k == 2:
                                a, b = v[1] - 1, v[0]

                            if k == 3:
                                a, b = v[1], v[0] - 1

                            if M > a >= 0 and N > b >= 0:
                                if graph[b][a] == 1 and not visited[b][a]:
                                    queue.append([b, a])
                                    visited[b][a] = True
    print(cnt)


for _ in range(T):
    M, N, K = map(int, sys.stdin.readline().split())
    bfs(M, N, K)