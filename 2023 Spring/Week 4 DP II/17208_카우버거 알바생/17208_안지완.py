#dp는 주문 처리 갯수가 맞다.
#치즈 버거, 프라이 어느 하나가 용량을 초과하면 그 주문은 처리를 못한다. 그럼 조건문 하나로 줄어들 수 있음
#만약 용량을 초과 안하면, 어쨌든 주문 아닌가? 그럼 만약 하나를 더 넣을 수 있다면 dp+=1

n,m,k = map(int, input().split())
order = [(0,0)]
dp = [[[0 for _ in range(k+1)] for _ in range(m+1)] for _ in range(n+1)]

for _ in range(n):
    x,y = map(int,input().split())
    order.append((x,y))


for i in range(1,n+1):
    for j in range(1,m+1):
        for l in range(1, k+1):
            cheese_w = order[i][0]
            fries_w = order[i][1]
            if j >= cheese_w and l >= fries_w:
                dp[i][j][l] = max(dp[i-1][j-cheese_w][l-fries_w]+1, dp[i-1][j][l])
            else:
                dp[i][j][l] = dp[i-1][j][l]

print(dp[n][m][k])

