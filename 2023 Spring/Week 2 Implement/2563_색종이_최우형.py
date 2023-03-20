import sys

paper = [[0 for _ in range(100)] for _ in range(100)]

N = int(sys.stdin.readline().rstrip())

#0,0 이면 0,0~ 9~9 // 1,1 이면 1,1~ 10,10
for i in range(N):
    x, y = map(int, sys.stdin.readline().split(' '))
    for paper_x in range(10):
        for paper_y in range(10):
            paper[x+paper_x][y+paper_y] = 1
answer = 0
for i in paper:
    answer += sum(i)
print(answer)