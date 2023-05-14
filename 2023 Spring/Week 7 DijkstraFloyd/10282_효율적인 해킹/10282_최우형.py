import heapq
import sys
from collections import deque

INF = 1e9

test_case = int(sys.stdin.readline())


def dijkstra(start, n, graph):
    heap = []
    heapq.heappush(heap, (0, start))

    visited[start] = True
    distance[start] = 0
    # 자자 방문을 했습죠
    while heap:
        # cur_node 방문할 노드 / cur_node_cost 방문할 노드까지의 비용
        cur_node_cost, cur_node = heapq.heappop(heap)

        # 방문한 노드로부터 연결된 간선들로 distance 정리
        # cur_node -> next_node /  next_cost
        for next_node, next_cost in graph[cur_node]:
            cost = distance[cur_node] + next_cost
            if cost < distance[next_node]:
                distance[next_node] = cost
                heapq.heappush(heap, (cost, next_node))

    num = 0
    answer = []
    for i in distance:
        if i < INF:
            answer.append(i)
    return len(answer), max(answer)

for i in range(test_case):
    n, d, c = map(int, sys.stdin.readline().split(' '))
    distance = [INF for _ in range(n + 1)]
    visited = [False for _ in range(n + 1)]
    graph = [[] for _ in range(n + 1)]

    for j in range(d):
        a, b, s = map(int, sys.stdin.readline().split(' '))
        graph[b].append([a, s])

    ans_a, ans_b = dijkstra(c, n, graph)
    print(ans_a, ans_b)
    distance.clear()
