import sys
input = sys.stdin.readline

k = int(input())
list = []

for _ in range(k):
    num = int(input())
    if num:
        list.append(num)
    else:
        list.pop()

sum =0
for i in list:
    sum+=i

print(sum)