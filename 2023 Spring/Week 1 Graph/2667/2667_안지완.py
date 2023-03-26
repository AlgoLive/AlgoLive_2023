import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().strip())) for _ in range(n)]
visited = [[0 for _ in range(n)] for _ in range(n)]
apt_list = []
d = [(1,0),(-1,0),(0,1),(0,-1)]

def sol(r,c):
    global visited,apt_list, graph

    queue = deque()
    queue.append((r,c))
    visited[r][c] = 1
    cnt = 1

    while queue:
        r, c = queue.pop()
        for i in d:
            dr = r + i[0]
            dc = c + i[1]
            if 0<=dr<n and 0<=dc<n and graph[dr][dc] == 1 and visited[dr][dc] == 0:
                queue.append((dr,dc))
                cnt+=1
                visited[dr][dc] = 1
    apt_list.append(cnt)

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1 and visited[i][j] == 0:
            sol(i,j)

print(len(apt_list))
for i in sorted(apt_list):
    print(i)
