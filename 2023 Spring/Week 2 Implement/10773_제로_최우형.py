import sys
from collections import deque

K = int(sys.stdin.readline().rstrip())

queue = deque()
for i in range(K):
    temp = int(sys.stdin.readline().rstrip())
    if temp:
        queue.append(temp)
    else:
        queue.pop()
print(sum(queue))