N, M = map(int, input().split())
relationship = [[] for i in range(N)]
for _ in range(M):
    temp1, temp2 = map(int, input().split())
    relationship[temp1].append(temp2)
    relationship[temp2].append(temp1)

s = []
is_in = 0

def solve(node):
    global s, is_in
    if is_in == 1:
        return

    if len(s) == 5:
        is_in = 1
    else:
        for i in relationship[node]:
            if i not in s:
                s.append(i)
                solve(i)
                s.pop()


for i in range(0, N):
    if is_in == 1:
        break
    solve(i)

print(is_in)