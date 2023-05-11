import heapq
import sys

n = int(input())
INF = sys.maxsize

def sol():
    max = INF
    count = 0

    n,d,c = map(int,input().split())
    heap = []
    graph = [[] for _ in range(n+1)]
    table = [INF for _ in range(n+1)]
    visited = [0 for _ in range(n+1)]

    for _ in range(d):
        a,b,s = map(int,input().split())
        graph[b].append((a,s))

    heapq.heappush(heap,(c,0))
    table[c] = 0
    visited[c] = 1
    count+=1

    while heap:
        now_node, wei = heapq.heappop(heap)
        for new_node, w in graph[now_node]:
            if table[new_node] > w+wei:
                table[new_node] = w+wei
                heapq.heappush(heap,(new_node, w+wei))
                if visited[new_node] == 0:
                    count+=1
                    visited[new_node] = 1
    for i in sorted(table,reverse=True):
        if i != INF:
            max = i
            break
    print(count, max, sep = " ")

for _ in range(n):
    sol()


