#접근법
#치즈1과 똑같은 문제지만, 두번 접촉해야 사라진다는 점에서 약간 다르다.
#여전히 치즈 내부에서는 알턱이 없고, 바깥에서 bfs를 실행해야 할 것이다.
#2636에서는 접촉하면 해당 노드의 값을 -1씩 감소시켜 0이 되면 사라지게 하는 거면
#이번에는 오히려 +1씩 시켜 3이상이 되면 사라지게 하는 것이 맞을 것이다.
#똑같이 2636과 같은 방법을 쓰고 조건만 다르게 하자.
#이번엔 시간만 출력하면 되므로, 쓸데없는 변수는 삭제하자.

#만약 첫줄에서 그래프가 녹아 내렸으면 그곳은 비게 되므로 접근해야 하지 말아야 할 치즈까지 접근 할 수 있다.
#또 스캔을 하면 분명 시간 복잡도에 걸릴 것 같긴 한데...
#그럼 visited를 역으로 이용할까. 한번 visit하면 -1, 이걸 누적시켜 현재 그래프에 역으로 뺸다면?

#t_graph+=1을 하면 bfs탈출할 때 초기화 시켜야되는데 이게 누적이 되버린다.
#그럼 visited를 하자.

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

    d = [(1,0),(-1,0),(0,1),(0,-1)]

    queue.append((0,0))
    t_visited[0][0] = 1

    while queue:
        row, col = queue.pop()
        for mv in d:
            dr = row + mv[0]
            dc = col + mv[1]
            if 0 <= dr < n and 0 <= dc < m:
                if 0 < graph[dr][dc] < 3: #치즈 발견시 -1
                    t_visited[dr][dc] -=1
                    if t_visited[dr][dc] <= -2:
                        t_visited[dr][dc] = 1 #3이상이 되면 더이상 방문할 이유가 없으므로 이때 t_visited를 1로 한다.
                        t_graph[dr][dc] = 0
                        c_cnt-=1
                        is_melted = 1
                elif graph[dr][dc] == 0 and t_visited[dr][dc] == 0: #이동
                    t_visited[dr][dc] = 1
                    queue.append((dr,dc))
    graph = t_graph
    if is_melted:
        if c_cnt <= 0: #다 녹았거나 녹일 것이 없을 때만 True
            c_time += 1
            return True
        else:
            c_time += 1
            return False #녹인 게 있고, 잔여 치즈가 있으면 False
    else:
        return True



for i in range(n):
    graph[i] = list(map(int, input().split()))
    for j in graph[i]:
        if j == 1:
            c_cnt += 1
while True:
    if bfs():
        print(c_time)
        break