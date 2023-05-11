# Dijkstra 알고리즘 연습용 문제

import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize

V, E = map(int, input().split())
K = int(input())

graph = [[] for _ in range(V+1)] #그래프
table = [INF]*(V+1) #춟발 노드로부터 각 인접한 노드들 간의 거리를 담은 테이블
heap = [] #우선순위 큐로 사용할 리스트

def dijkstra(start):
    table[start] = 0 #출발 노드는 0으로 초기화
    heapq.heappush(heap, (0, start))

    while heap: #큐의 원소가 없을때까지
        wei, now = heapq.heappop(heap) #이전노드를 기준으로 가장 거리가 짧은 노드로 이동

        for w, next_node in graph[now]:
            next_w = w + wei #출발노드로부터의 거리를, 누적된 값 + 현재 가중치로 알아낸다.
            if table[next_node] > next_w: #그 값이 현재 테이블에 기록된 값보다 적으면,
                table[next_node] = next_w #업데이트 한다.
                heapq.heappush(heap, (next_w, next_node)) #우선순위 큐에 삽입

for i in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((w,v))

dijkstra(K)
for i in range(1,V+1):
    print("INF" if table[i] == INF else table[i])
