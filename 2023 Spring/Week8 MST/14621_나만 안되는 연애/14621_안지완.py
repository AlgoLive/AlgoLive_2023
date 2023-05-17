import heapq

n,m = map(int,input().split())
mw = list(map(str,input().split()))
mw.insert(0,'x')
graph = [[] for _ in range(n+1)]
visited = [0 for _ in range(n+1)]

for _ in range(m):
    u,v,d = map(int,input().split())
    graph[u].append([d,u,v])
    graph[v].append([d,v,u])

def sol(start):
    s_edges = graph[start]
    heapq.heapify(s_edges)
    visited[start] = 1
    count = 1
    total = 0

    while s_edges:
        cost, start, end = heapq.heappop(s_edges)
        if visited[end] == 0 and mw[start] != mw[end]:
            visited[end] = 1
            total += cost
            count += 1
            for edges in graph[end]:
                if visited[edges[2]] == 0 and mw[end] != mw[edges[2]]:
                    heapq.heappush(s_edges, edges)
    if count == n:
        return total
    return -1

print(sol(1))