#접근법 :
#치즈 내에서 해당 치즈가 경계선이라는 걸 알 턱이 없으므로, 아예 바깥에서 bfs를 시도한다.
#(0,0)은 항상 가장자리이므로, (0,0)에서 시작
#치즈가 놓여있지 않은 방향으로만 탐색을 하고, 상하좌우에 치즈가 있다면 지운다.
#변경사항은 복사한 그래프에만 적용하고, 탐색은 원본 그래프만 탐색하고, 나중에 덮어씌운다.
#최악 케이스는 10^9 이므로 시간제한에 걸리지 않음.
#시간을 저장하는 변수, 그리고 그 시간대에 치즈 갯수를 두어, 탐색마다 치즈가 발견되면 치즈 개수를 업데이트하고
#탐색 횟수마다 시간을 +1

import sys
import copy
from collections import deque
input = sys.stdin.readline

c_time = 0 #시간 저장
c_cnt = 0 #치즈 갯수

n,m = map(int, input().split())
graph = [[] for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]

def bfs():
    global c_cnt, graph, c_time
    is_melted = 0 #치즈를 녹였는가. 녹였으면 +1
    t_graph = copy.deepcopy(graph)
    t_visited = copy.deepcopy(visited)
    queue = deque()

    prev = c_cnt #이전 값 보존

    d = [(1,0),(-1,0),(0,1),(0,-1)]

    queue.append((0,0))
    t_visited[0][0] = 1

    while queue:
        row, col = queue.pop()
        for mv in d:
            dr = row + mv[0]
            dc = col + mv[1]
            if 0 <= dr < n and 0 <= dc < m and t_visited[dr][dc] == 0:
                if graph[dr][dc] == 1: #치즈 발견시 마킹
                    t_graph[dr][dc] = 0
                    t_visited[dr][dc] = 1
                    c_cnt-=1
                    is_melted = 1
                elif graph[dr][dc] == 0: #이동
                    t_visited[dr][dc] = 1
                    queue.append((dr,dc))
    graph = t_graph
    if is_melted:
        c_time += 1
    if c_cnt <= 0:
        return prev
    else:
        return -1

for i in range(n):
    graph[i] = list(map(int, input().split()))
    for j in graph[i]:
        if j == 1:
            c_cnt += 1
while True:
    flag = bfs()
    if flag != -1:
        print(c_time)
        print(flag)
        break

