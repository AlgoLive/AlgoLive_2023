n = int(input())
w = [0 for _ in range(n)]
pm = [[0 for _ in range(n)] for _ in range(n)]
edges = []
rank = [0 for _ in range(n+1)]
parent = [0 for _ in range(n+1)]

for i in range(n):
    w[i] = int(input())

for i in range(n):
    pm[i] = list(map(int,input().split()))
    for j in range(n):
        if i!=j:
            edges.append([pm[i][j],i,j])

for i in range(n+1):
    parent[i] = i

for i in range(n):
    edges.append([w[i],n,i]) #각 노드 별 우물 비용을 간선으로 만들기.

def find(a):
    if a == parent[a]:
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
            rank[b]+=1

def sol():
    edges.sort()
    total = 0
    for edge in edges:
        if not edge:
            continue
        cost, start, end = edge
        if find(start) != find(end):
            union(start,end)
            total += cost
    return total

print(sol())