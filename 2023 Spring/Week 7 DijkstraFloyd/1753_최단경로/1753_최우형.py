import heapq
import sys

# v = 정점수 / E = 간선 / ie8
V, E = map(int, sys.stdin.readline().split(' '))
K = int(sys.stdin.readline())
graph = [[] for _ in range(V + 1)]
distance = [1e9 for _ in range(V + 1)]

for i in range(1, E + 1):
    x, y, z = map(int, sys.stdin.readline().split(' '))

    graph[x].append([y, z])


def daijkstra(graph, start):
    # 출발 노드 확인!!
    heap = []
    distance[start] = 0
    heapq.heappush(heap, (distance[start], start))

    while heap:
        now_distance, now = heapq.heappop(heap)
        # 이전에 힙에 들어있던 거리, 거리가 더 작아졌으면 볼 필요 없다 -> 방문 처리 대신
        if distance[now] >= now_distance:
            for i in graph[now]:
                if distance[i[0]] > distance[now] + i[1]:
                    distance[i[0]] = distance[now] + i[1]
                    heapq.heappush(heap, (distance[i[0]], i[0]))
    return distance


answer = daijkstra(graph, K)
for i in range(1, V+1):
    if answer[i] == 1e9:
        print('INF')
    else:
        print(answer[i])