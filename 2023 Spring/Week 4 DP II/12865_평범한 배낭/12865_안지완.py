import sys
input = sys.stdin.readline

n,k = map(int, input().split())
stuff = [(0,0) for _ in range(n+1)]
dp = [[0 for _ in range(k+1)] for _ in range(n+1)]

for i in range(1,n+1):
    w,v = map(int,input().split())
    stuff[i] = (w,v)

# i = 물건
# w = 배낭
for i in range(n+1):
    for w in range(k+1):
        if i == 0 or w == 0:
            dp[i][w] = 0
        elif w < stuff[i][0]: #물건이 용량보다 무거우면
            dp[i][w] = dp[i-1][w] #물건을 넣을 수 없으니 그 전 dp의 값을 가져온다.
        else: #물건을 넣을 수가 있다면
            stuff_w = stuff[i][0] # 현재 넣으려는 물건의 무게
            stuff_v = stuff[i][1] # 현재 넣으려는 물건의 가치
            dp[i][w] = max(dp[i-1][w-stuff_w] + stuff_v, dp[i-1][w])
            #현재 넣으려는 물건의 무게 만큼 배낭을 비우고, 물건을 넣었을 때의 총 가치와
            #현재 넣으려는 물건을 안 넣었을 때의 가치를 비교하고, 더 큰 값을 dp에 저장한다.

print(dp[n][k])



