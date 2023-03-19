K = int(input())
stack = []

for n in range(K):
    tmp = int(input())
    if tmp == 0:
        if stack:
            stack.pop()
        else:
            continue
    else:
        stack.append(tmp)

res = 0
for n in stack:
    res += n

print(sum(stack))
