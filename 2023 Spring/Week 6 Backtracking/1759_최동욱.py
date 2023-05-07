import sys
sys.setrecursionlimit(10 ** 6) # 숫자는 예시

L, C = map(int, input().split())
mo, ja = list(), list()
ans = list()

for v in list(map(str, input().split())):
    if v in ['a','e','i','o','u']:
        mo.append(v)
    else:
        ja.append(v)

alpha = ja + mo
code = []


def solve(index):
    global code
    global ans

    if len(code) == L:
        temp = str()
        for v in sorted(code):
            temp += v
        ans.append(temp)
        return

    for i in range(index, len(alpha)):
        if len(code) == L - 1:
            if i < len(ja):
                continue

        if len(code) == 1 and i >= len(ja):
            return

        code += alpha[i]
        solve(i+1)
        code = code[:-1]

solve(0)
for v in sorted(ans):
    print(v)
