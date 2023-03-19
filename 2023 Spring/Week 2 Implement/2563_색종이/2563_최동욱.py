N = int(input())
nums = []
paper = [[0 for _ in range(100)] for _ in range(100)]
area = 0

for _ in range(N):
    nums.append(tuple((map(int, input().split()))))

for x, y in nums:
    for i in range(x, x+10):
        for j in range(y, y+10):
            paper[j][i] = 1

for i in range(100):
    area += sum(paper[i])

print(area)