import sys
sys.setrecursionlimit(10 ** 6) # 숫자는 예시

N = int(input())
nums = list(map(int, input().split()))
ops = list(map(int, input().split()))
# 0: +, 1: -, 2: *, 3: //

max_num = -1e9
min_num = 1e9


def solve(depth, total, plus, minus, multiply, divide):
    global max_num, min_num
    if depth == N:
        max_num = max(total, max_num)
        min_num = min(total, min_num)
        return

    if plus:
        solve(depth + 1, total + nums[depth], plus - 1, minus, multiply, divide)
    if minus:
        solve(depth + 1, total - nums[depth], plus, minus - 1, multiply, divide)
    if multiply:
        solve(depth + 1, total * nums[depth], plus, minus, multiply - 1, divide)
    if divide:
        solve(depth + 1, int(total / nums[depth]), plus, minus, multiply, divide - 1)


solve(1, nums[0], ops[0], ops[1], ops[2], ops[3])
print(max_num)
print(min_num)