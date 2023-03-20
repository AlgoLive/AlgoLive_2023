import sys
from collections import deque

N = sys.stdin.readline().rstrip()

numbers = list(map(int, list(N)))

countNumber = [0, 0, 0, 0, 0, 0, 0, 0, 0]
# 9 는 6과 동일하게 평가
for i in numbers:
    if i == 6 or i == 9:
        countNumber[6] += 1
    else:
        countNumber[i] += 1
countNumber[6] += 1
countNumber[6] //= 2
print(max(countNumber))