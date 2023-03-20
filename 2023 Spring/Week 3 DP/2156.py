# 일단 봤을 때 아 DP 구나
# bottom-up 방식

# case 를 나눠서 진행해봐야겠다
# 근데, 3잔을 기준으로 했을 때, 전에 몇개까지 저장을 해야 할까?
# 생각을 해보자
# N잔까지 마셔야 한다고 생각을 할 떄,
# 일단 3잔 연속이 기준이니 3잔을 제외하고는 최대라고 카운트해보자
# N-3잔까지의 최대량은 M

# 현재 포함 4잔을 제외하고 최대라고 카운트하자
# N-4잔까지의 최대량을 M
# 즉, 4잔을 대상으로 카운트 하는 것이다
# 그럼 그 4잔을 대상으로는 어떻게 카운트해야할까?

# 아니다
# 다시 생각해보니 연속횟수와 량을 카운트하는 것이 쉽겠다
# 예를 들어, N위치의 것을 세야 하는데 N-1까지의 가능한 경우는
# 연속된 것 X, 연속된 것 1, 연속된 것 2 이런 식으로 카운트하는 거다
# 딕셔너리를 통해 업데이트 하면 될 것 같다.
# 결과는 틀렸죠? ㅎ

# 4개를 카운트해보자
# 0011 0101 1001 1010 1100
# 1101 1011


# 아니다, 직전, 두개전, 세개전 까지는 확인해야 한다



K = int(input())
wines = []
drunk = []

for _ in range(K):
    wines.append(int(input()))


def DP(K, wines):
    drunk.append((wines[0], 1))
    drunk.append((wines[0] + wines[1], 2))
    drunk.append((0,0))
    if drunk[0][0] + wines[2] > drunk[1][0]:
        drunk[2] = (drunk[0][0] + wines[2], 1)
    else:
        drunk[2] = (drunk[1][0], 0)

    for i in range(3, K):
        # 1개 전
        max = 0
        drunk.append((0, 0))
        if drunk[i-1][1] == 2:
            temp_1_2 = drunk[i-1][0]
            if temp_1_2 > max:
                max = temp_1_2
                drunk[i] = (max, 0)
        elif drunk[i-1][1] == 1:
            temp_1_1 = drunk[i-1][0] + wines[i]
            if temp_1_1 > max:
                max = temp_1_1
                drunk[i] = (max, 2)
        elif drunk[i-1][1] == 0:
            temp_1_0 = drunk[i-1][0] + wines[i]
            if temp_1_0 > max:
                max = temp_1_0
                drunk[i] = (max, 1)
        if drunk[i-2][1] == 2:
            temp2_2 = drunk[i-2][0] + wines[i]
            if temp2_2 > max:
                max = temp2_2
                drunk[i] = (max, 1)
        elif drunk[i-2][1] == 1:
            temp2_1 = drunk[i-2][0] + wines[i]
            if temp2_1 > max:
                max = temp2_1
                drunk[i] = (max, 1)
        elif drunk[i-2][1] == 0:
            temp2_0 = drunk[i-2][0] + wines[i-1] + wines[i]
            if temp2_0 > max:
                max = temp2_0
                drunk[i] = (max, 2)
        if drunk[i-3][1] == 2:
            temp3_2 = drunk[i-3][0] + wines[i-1] + wines[i]
            if temp3_2 > max:
                max = temp3_2
                drunk[i] = (max, 2)
        elif drunk[i - 3][1] == 1:
            temp3_1 = drunk[i-3][0] + wines[i-2] + wines[i]
            if temp3_1 > max:
                max = temp3_1
                drunk[i] = (max, 1)
        elif drunk[i - 3][1] == 0:
            temp3_0 = drunk[i-3][0] + wines[i-2] + wines[i-1]
            if temp3_0 > max:
                max = temp3_0
                drunk[i] = (max, 0)

    print(drunk[K-1][0])


DP(K, wines)