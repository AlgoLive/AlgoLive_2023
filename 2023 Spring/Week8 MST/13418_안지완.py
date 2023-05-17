n, m = map(int, input().split())
edges = []
rank = [0 for _ in range(n + 1)]
parent = [0 for _ in range(n + 1)]
ent_cost = 0

for i in range(m + 1):
    a, b, c = map(int, input().split())
    edges.append([c, a, b])
    if i == 0:
        ent_cost = not c


for i in range(n + 1):
    parent[i] = i


def find(a):
    if parent[a] == a:
        return a
    p = find(parent[a])
    parent[a] = p
    return parent[a]


def union(a, b):
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
    global rank, parent
    rank = [0 for _ in range(n + 1)]
    parent = [i for i in range(n + 1)]
    union(1,0)

    edges.sort()
    total = ent_cost
    for edge in edges:
        if not edge:
            continue
        cost, start, end = edge
        if find(start) != find(end):
            union(start, end)
            if not cost:
                total += 1

    return pow(total, 2)


def rsol():
    global parent, rank
    union(1,0)

    edges.sort(reverse=True)
    total = ent_cost

    for edge in edges:
        if not edge:
            continue
        cost, start, end = edge
        if find(start) != find(end):
            union(start, end)
            if not cost:
                total += 1

    return pow(total, 2)

a = rsol()
b = sol()
print(b-a)