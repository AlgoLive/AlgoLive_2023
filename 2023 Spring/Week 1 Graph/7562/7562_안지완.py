from collections import deque

dxy = [(1,2),(1,-2),(2,1),(2,-1),(-1,2),(-1,-2),(-2,1),(-2,-1)]

def sol():
    global l,c,d
    graph = [[0 for _ in range(l)] for _ in range(l)]
    graph[c[0]][c[1]] = 1
    queue = deque()
    queue.append(c)

    while(queue):
        x = queue.popleft()
        if x[0] == d[0] and x[1] == d[1]:
            print(graph[x[0]][x[1]] - 1)
            break
        for i in range(8):
            dr = x[0] + dxy[i][0]
            dc = x[1] + dxy[i][1]
            if 0 <= dr < l and 0 <= dc < l and not graph[dr][dc]:
                graph[dr][dc] = graph[x[0]][x[1]] + 1
                queue.append([dr,dc])

T = int(input())
for _ in range(T):
    l = int(input())
    c = list(map(int, input().split()))
    d = list(map(int, input().split()))
    sol()