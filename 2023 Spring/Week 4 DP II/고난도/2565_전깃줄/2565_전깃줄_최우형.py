# 2565 전깃줄
import sys

N = int(sys.stdin.readline())
line = []
for i in range(N):
    line.append(list(map(int, sys.stdin.readline().split())))

line.sort()

# 정렬하면 왼쪽 정보는 증가하는 인덱스와 같은 역할을 할 뿐...
# 즉 오른쪽 정보를 통해 증가하는 수열의 가장 길이가 긴 경우를 찾으면 됨..
# dp[i] 는 dp[i 번째 정보를 마지막으로 하는 수열]
# 즉 i번째 전기 선과 j( 0 ~ i-1 )번째 전기 선을 비교하여 증가하는 경우 해당 dp + 1한 값을 저장
# 어차피 가장 큰 경우를 골라야 하므로 루프를 돌며 접근하게된 된 dp[j] + 1 중 가장 큰 값으로 계속 초기화
dp = [1 for _ in range(N)]

for i in range(1,N):
    for j in range(i):
        if line[i][1] > line[j][1]:
            dp[i] = max(dp[j] + 1, dp[i])

answer = N - max(dp)
print(answer)
