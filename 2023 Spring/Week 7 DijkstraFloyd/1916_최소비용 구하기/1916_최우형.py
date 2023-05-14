import heapq
import sys

INF = int(1e10)

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
edge = [list(map(int, sys.stdin.readline().split(' '))) for _ in range(M)]
graph = [[] for _ in range(N + 1)]
for i in edge:
    graph[i[0]].append([i[1], i[2]])
start, end = map(int, sys.stdin.readline().split(' '))
distance = [INF for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]

q = [[0, start]]


def dikjstra(start):
    q = []
    heapq.heappush(q, [0, start])
    visited[start] = 0

    while q:
        next_cost, next_index = heapq.heappop(q)
        if not visited[next_index]:
            visited[next_index] = True
            for i in graph[next_index]:
                if distance[i[0]] > next_cost + i[1]:
                    distance[i[0]] = next_cost + i[1]
                    heapq.heappush(q, [distance[i[0]], i[0]])


dikjstra(start)

if start == end:
    print(0)
else:
    print(distance[end])