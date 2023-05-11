import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize
heap = []

N = int(input())
M = int(input())

graph = [[] for _ in range(N+1) ]
table = [INF] * (N+1)

for _ in range(M):
    s,d,w = map(int, input().split())
    graph[s].append((d,w))
vs, vd = map(int, input().split())

table[vs] = 0
heapq.heappush(heap, ((0, vs)))

while heap:
    wei, now_node = heapq.heappop(heap)
    if now_node == vd: break
    if len(graph[now_node]) == 0: continue
    for new_node, w in graph[now_node]:
        new_w = wei+w
        if table[new_node] > new_w:
            table[new_node] = new_w
            heapq.heappush(heap, (new_w, new_node))
print(table[vd])