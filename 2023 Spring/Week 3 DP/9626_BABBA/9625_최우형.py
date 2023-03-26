import sys

# A B BA BAB BABBA
# B -> BA, A->B

K = int(sys.stdin.readline().rstrip())

A = 1
B = 0

for i in range(K):
    tempA = A
    tempB = B
    A = tempB
    B = tempA + tempB

print(A, B)