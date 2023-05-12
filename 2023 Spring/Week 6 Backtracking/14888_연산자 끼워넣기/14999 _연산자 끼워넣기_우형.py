import sys

N = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split(' ')))
op = list(map(int, sys.stdin.readline().split(' ')))
answer = list()


# 0,0,nums[0] 들어갑니다
def operation(temp_result, depth):
    if sum(op) < 1:
        answer.append(temp_result)
        return

    for i in range(4):
        if op[i] > 0:
            op[i] -= 1
            # temp_result (연산) nums[depth]
            if i == 0:
                operation(temp_result + nums[depth], depth + 1)
            elif i == 1:
                operation(temp_result - nums[depth], depth + 1)
            elif i == 2:
                operation(temp_result * nums[depth], depth + 1)
            elif i == 3:
                if temp_result < 0:
                    operation(-(-temp_result // nums[depth]), depth + 1)
                else:
                    operation(temp_result // nums[depth], depth + 1)
            op[i] += 1
    return


operation(nums[0], 1)
print(max(answer))
print(min(answer))
