import math
import sys

sys.setrecursionlimit(15000)
global C

A, B, C = map(int, sys.stdin.readline().split(' '))


def mul(a, b):
    # 짝수이면
    if b == 1:
        return a % C
    elif b == 0:
        return 1
    elif b % 2 == 0:
        answer = mul(a, b // 2)
        answer %= C
        return (answer * answer) % C
    elif b % 2 == 1:
        answer = mul(a, (b - 1) // 2)
        answer %= C
        return (((answer * answer) % C) * (A % C)) % C


print(mul(A, B) % C)
print(int(math.pow(A, B) % C))

# (a*a)%c = (a%c*a%c) %c
