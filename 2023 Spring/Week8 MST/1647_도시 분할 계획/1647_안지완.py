n,m = map(int,input().split())
edges = [[] for _ in range(m)]
rank = [0 for _ in range(n+1)]
parent = [0 for _ in range(n+1)]

for i in range(n+1):
    parent[i] = i

for i in range(m):
    a,b,c = map(int,input().split())
    edges[i] = [c,a,b]

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

def sol(edges):
    edges.sort()
    total = 0
    m_cost = []

    for edge in edges:
        if not edge:
            continue
        cost, start, end = edge
        if find(start) != find(end):
            union(start,end)
            m_cost.append(cost)
            total += cost

    return total-sorted(m_cost,reverse=True)[0]

print(sol(edges))