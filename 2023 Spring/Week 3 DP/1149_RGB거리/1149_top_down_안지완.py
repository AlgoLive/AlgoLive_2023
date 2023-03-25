import sys

sys.setrecursionlimit(10**6)
INF = sys.maxsize

n = int(input())
rgb = [[0 for _ in range(3)] for _ in range(1001)]
dp = [[0 for _ in range(3)] for _ in range(1001)]

for i in range(n):
    rgb[i] = list(map(int,input().split()))

def sol(pos, color):
    if pos == 0:
        return rgb[pos][color]

    min_cost = INF

    for i in range(3):
        if i == color: #다른 색이어야 하므로
            continue
        min_cost = min(min_cost, sol(pos-1,i)+rgb[pos][color]) #나머지 두 색 비교

    return min_cost

min_ans = INF
for i in range(3):
    min_ans = min(min_ans, sol(n-1,i))

print(min_ans)