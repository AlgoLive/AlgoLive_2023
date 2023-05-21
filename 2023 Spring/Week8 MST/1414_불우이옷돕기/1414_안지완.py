import heapq

n = int(input())
pmatrix = [[] for _ in range(n)]
edges = []
parent = [0 for _ in range(n)]
rank = [0 for _ in range(n)]
total = 0

for i in range(n):
    pmatrix[i] = list(map(str,input().strip()))
    for j in range(n):
        if str.isalpha(pmatrix[i][j]):
            if (96-ord(pmatrix[i][j]) < 0):
                cost = ord(pmatrix[i][j])-96
                edges.append([cost,i,j])
                total += cost
            else:
                cost = ord(pmatrix[i][j]) - 38
                edges.append([cost,i,j])
                total += cost

for i in range(n):
    parent[i] = i

def find(a):
    if parent[a] == a:
        return a
    p = find(parent[a])
    parent[a] = p
    return parent[a]

def union(a,b):
    a = find(a)
    b = find(b)
    if a == b:
        return
    if rank[a] > rank[b]:
        parent[b] = a
    else:
        parent[a] = b
        if rank[a] == rank[b]:
            rank[b] += 1

def sol():
    edges.sort()
    s_t = 0
    count = 0

    for edge in edges:
        if not edge:
            continue
        cost, start, end = edge
        if find(start) != find(end):
            union(start,end)
            s_t += cost
            count += 1

    if count == n-1:
        return s_t
    else:
        print(-1)
        exit()

print(total-sol())



