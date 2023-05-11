import heapq
import sys

n = int(input())
m = int(input())
INF = sys.maxsize
graph = [[] for _ in range(n+1)]
table = [INF for _ in range(n+1)]
pred = [0 for _ in range(n+1)]
ans = []
heap = []

for _ in range(m):
    s,f,c = map(int,input().split())
    graph[s].append((f,c))

ts, tf = map(int,input().split())

heapq.heappush(heap, (ts,0))
table[ts] = 0
pred[ts] = ts
while heap:
    now_node, wei = heapq.heappop(heap)
    #if now_node == tf:
    #   break => 목적지가 한번 갱신되었다고 그것이 정답이라는 보장이 없음
    if wei > table[now_node]:
        continue
    for new_node, w in graph[now_node]:
        sum = w + wei
        if table[new_node] > sum:
            table[new_node] = sum
            pred[new_node] = now_node
            heapq.heappush(heap, (new_node, sum))

def find_prev(forw_node):
    global ans
    ans.append(forw_node)

    if forw_node == ts:
        print(table[tf])
        print(len(ans))
        ans.reverse()
        print(*ans)
        exit()
    prev_node = pred[forw_node]
    find_prev(prev_node)

find_prev(tf)