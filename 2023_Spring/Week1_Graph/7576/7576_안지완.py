from collections import deque
d = [(0,1),(0,-1),(1,0),(-1,0)]

M,N = map(int, input().split())
graph = [[0 for _ in range(M)] for _ in range(N)]
t_cnt = 0
day = 0
rt_list = []

for i in range(N):
    graph[i] = list(map(int, input().split()))
    for j in range(M):
        if graph[i][j] != -1:
            t_cnt += 1
        if graph[i][j] == 1:
            rt_list.append([i,j])

rt_cnt = len(rt_list)
queue = deque()
for i in rt_list:
    queue.append(i)
while(queue):
    x = queue.popleft()
    day = graph[x[0]][x[1]]
    for i in d:
        dr = x[0]+i[0]
        dc = x[1]+i[1]
        if 0 <= dr < N and 0 <= dc < M and graph[dr][dc] == 0:
            graph[dr][dc] = graph[x[0]][x[1]] + 1
            queue.append([dr,dc])
            rt_cnt +=1

if t_cnt == rt_cnt:
    print(day-1)
else:
    print(-1)