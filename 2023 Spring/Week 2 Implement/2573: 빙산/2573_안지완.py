import sys
import copy
from collections import deque
input = sys.stdin.readline

year = 0
ice = {} #빙산의 인덱스와 높이를 담는 딕셔너리

def bfs(r,c): #빙산의 갯수를 카운트 및 녹이기를 위한 bfs, 빙산 갯수와 탐색 깊이가 다를 경우 분리되었다고 판별
    global year, graph
    cnt = 0 #빙산 갯수 카운트 변수
    ice_num = len(ice) #실제 빙산 갯수
    t_visited = copy.deepcopy(visited) #bfs를 위한 임시 visited 행렬
    t_graph = copy.deepcopy(graph) #빙산 녹는 걸 저장하기 위한 임시 그래프

    queue = deque()
    queue.append((r,c))
    t_visited[r][c] = 1

    d = [(1,0),(-1,0),(0,1),(0,-1)]

    while queue:
        n_row, n_col = queue.pop()
        cnt+=1
        for mv in d:
            dr = n_row + mv[0]
            dc = n_col + mv[1]
            if 0 <= dr < n and 0 <= dc < m:
                if graph[dr][dc] != 0 and t_visited[dr][dc] == 0:
                    t_visited[dr][dc] = 1
                    queue.append((dr,dc))
                elif graph[dr][dc] == 0:
                    t_graph[n_row][n_col] -= 1
                    ice[(n_row,n_col)] -= 1
        if ice[(n_row,n_col)] <= 0:
            t_graph[n_row][n_col] = 0
            ice.pop((n_row,n_col))

    graph = copy.deepcopy(t_graph)
    if cnt == ice_num:
        year+=1
        return True
    else:
        return False

if __name__ == '__main__':
    n, m = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(n)]
    visited = [[0 for _ in range(m)] for _ in range(n)]

    for i in range(n): #ice dict 초기화
        for j in range(m):
            if graph[i][j] != 0:
                ice[(i,j)] = graph[i][j]

    while True:
        if len(ice.keys()) == 0:
            print(0)
            break
        else:
            r,c = list(ice.keys())[0] #빙산의 첫 부분부터 순회할 예정 (녹을 수 있으므로)
            if not bfs(r,c):
                print(year)
                break
