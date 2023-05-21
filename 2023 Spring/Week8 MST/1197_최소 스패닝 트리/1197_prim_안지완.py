import heapq
import sys
INF = sys.maxsize

v,e = map(int,input().split())
graph = [[] for _ in range(v+1)]

for _ in range(e):
    a,b,c = map(int,input().split())
    graph[a].append([c,a,b]) #비용, 시작, 도착
    graph[b].append([c,b,a])

def Prim(start_node): #시작 노드부터 차래로 탐색해 나가므로, 시작 노드를 정해주어야 한다.
    total_weight = 0
    s_edges = graph[start_node] #시작노드의 모든 간선들을 불러옴
    visited = [0 for _ in range(v+1)]
    visited[start_node] = 1
    heapq.heapify(s_edges) #첫 시작 노드의 간선들을 우선순위 큐에 넣어준다.

    while s_edges:
        wei, start, end = heapq.heappop(s_edges)
        if visited[end] == 0:
            visited[end] = 1
            total_weight += wei
            for n_edge in graph[end]: #노드를 새로 방문했으므로, 정보가 있는 간선들을 우선순위 큐에 추가함
                if visited[n_edge[2]] == 0: #완전 새로운 간선일 경우에는 새로운 간선이므로 추가
                    heapq.heappush(s_edges,n_edge)
    return total_weight

print(Prim(1))



