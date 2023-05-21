edges = []
parent = []
rank = []
def test():
    global edges, parent, rank

    n,m,k = map(int,input().split())
    if n == 0 and m == 0 and k == 0:
        exit()
    edges = []
    parent = [0 for _ in range(n + 1)]
    rank = [0 for _ in range(n+1)]

    for _ in range(m):
        c,f,t = map(str,input().split())
        if c == 'R':
            c = 0
        else:
            c = 1
        edges.append([c,int(f),int(t)])
    for i in range(n+1):
        parent[i] = i

    print(sol(n,k))

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

def sol(n,k):
    edges.sort(reverse=True)
    rb_count = 0
    edge_count = 0

    for edge in edges:
        if not edge:
            continue
        rb, start, end = edge
        if find(start) != find(end):
            if rb and rb_count < k:
                union(start,end)
                rb_count += 1
                edge_count += 1
            elif not rb:
                union(start,end)
                edge_count += 1
    if edge_count == n-1 and rb_count == k:
        return 1
    else:
        return 0

while True:
    test()


