import sys

sys.setrecursionlimit(1500000)

N = int(sys.stdin.readline())
paper = [list(map(int, sys.stdin.readline().split(' '))) for _ in range(N)]
answer = [0, 0]


# 왼위 , 오아래
def dp(x, y, I, J):
    if x - I == 0:
        answer[paper[x][y]] += 1
        return

    else:
        # 틀리면 -1 맞음녀 0, 1
        temp = paper[x][y]
        for i in range(x, I):
            for j in range(y, J):
                if paper[i][j] != temp:
                    temp = -1
                    break
            if temp == -1:
                break

        # 통과 못하면...
        if temp == -1:
            dp(x, y, (x + I) // 2, (y + J) // 2)
            dp(x, (y + J) // 2, (x + I) // 2, J)
            dp((x + I) // 2, y, I, (y + J) // 2)
            dp((x + I) // 2, (y + J) // 2, I, J)
        else:
            answer[temp] += 1

dp(0, 0, N, N)
for i in answer:
    print(i)
