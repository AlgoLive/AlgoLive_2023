from collections import deque
import sys

input = sys.stdin.readline

T = int(input())
d = [(1,0),(-1,0),(0,1),(0,-1)]

def sol(x,y):
    global visited, graph
    queue.append((x,y))

    while queue:
        c, r = queue.pop()
        for i in d:
            dr = i[0] + r
            dc = i[1] + c
            if 0<=dr<n and 0<=dc<m and graph[dr][dc] == 1 and visited[dr][dc] == 0:
                queue.append((dc,dr))
                visited[dr][dc] = 1

for _ in range(T):
    cnt =0
    m,n,k = map(int, input().split())
    veg_list = []
    graph = [[0 for _ in range(m)] for _ in range(n)]
    visited = [[0 for _ in range(m)] for _ in range(n)]
    for _ in range(k):
        x,y = map(int, input().split())
        graph[y][x] = 1

    queue = deque()

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1 and visited[i][j] == 0:
                sol(j,i)
                cnt+=1
    print(cnt)