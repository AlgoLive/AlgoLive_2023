import sys
input = sys.stdin.readline

#3초, 5초 상태가 번갈아가므로 3초,5초 상태를 저장하는 것이 중요
#1초는 3초를 구하기 위한 초기값
#짝수 초는 모조리 O
r,c,n = map(int,input().split())
graph = [['0' for _ in range(c)] for _ in range(r)]
bomb_placed = [[0 for _ in range(c)] for _ in range(r)]

bomb_thr = [] #3초 상태에서 터지는 폭탄 인덱스
bomb_ndes_thr = [] #3초 상태에서 파괴되지 않는 폭탄 인덱스
bomb_des_thr = [] #3초 상태에서 파괴되지 않은 폭탄에 의해 파괴되는 폭탄 인덱스


d = [(1,0),(-1,0),(0,1),(0,-1)]
for i in range(r):
    graph[i] = list(map(str, input().strip()))

def output(n):
    if n == 1:
        for i in range(r):
            for j in range(c):
                if graph[i][j] == 'O':
                    print("O", end = "")
                else:
                    print('.', end = "")
            print()
    elif n%2 == 0:
        for i in range(r):
            for j in range(c):
                print("O", end = "")
            print()

    elif (n-3)%4 == 0:
        for i in range(r):
            for j in range(c):
                if (i,j) in bomb_ndes_thr:
                    print('O', end = "")
                else:
                    print('.', end = "")
            print()
    elif (n-3)%4 == 2:
        for i in range(r):
            for j in range(c):
                if (i, j) in bomb_ndes_thr or (i,j) in bomb_des_thr:
                    print(".", end="")
                else:
                    print('O', end="")
            print()

#3,5초 폭탄 인덱스 저장
for row in range(r):
    for col in range(c):
        if graph[row][col] == 'O':
            bomb_thr.append((row,col))
            bomb_placed[row][col] = 1
            for mv in d:
                dr = row + mv[0]
                dc = col + mv[1]
                if 0 <= dr < r and 0 <= dc < c and graph[dr][dc] == '.':
                    bomb_placed[dr][dc] = 1

#파괴되지 않고 정상적으로 5초에 폭발하는 폭탄들
for row in range(r):
    for col in range(c):
        if bomb_placed[row][col] != 1:
            bomb_ndes_thr.append((row,col))
            for mv in d:
                dr = row + mv[0]
                dc = col + mv[1]
                if 0 <= dr < r and 0 <= dc < c and graph[dr][dc] == '.':
                    bomb_des_thr.append((dr,dc))
                    bomb_placed[row][col] = 1

output(n)