import heapq

n = int(input())
pmatrix = [[] for _ in range(n)]
graph = [[] for _ in range(n)]
visited = [0 for _ in range(n)]

for i in range(n):
    pmatrix[i] = list(map(int,input().split()))
    for j in range(n):
        if i!=j:
            graph[i].append([pmatrix[i][j], i,j])

def sol(start):
    s_edges = graph[start]
    heapq.heapify(s_edges)
    visited[start] = 1
    total = 0

    while s_edges:
        cost, start, end = heapq.heappop(s_edges)
        if visited[end] == 0:
            visited[end] = 1
            total += cost
            for edge in graph[end]:
                if visited[edge[2]] == 0:
                    heapq.heappush(s_edges,edge)
    return total

print(sol(0))



