import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

v, e = map(int,input().split())
graph = [[] for _ in range(v+1)] #주어진 원본 그래프
edges = [[] for _ in range(e)] #간선의 정보 (Prim's Algorithm과 달리, 간선 자체를 이어붙여야 하므로, 간선만의 정보도 필요하다
parent = [0 for _ in range(v+1)] #각 집합의 최상위 노드를 구하기 위한 자료구조. 같은 집합인지 확인
rank = [0 for _ in range(v+1)] # 랭크가 높을 수록, 먼저 생성된 집합을 의미한다. 집합의 최상위 노드를 구하기 위한 자료구조

for i in range(v+1):
    parent[i] = i #처음엔 자기자신으로 최상위 루트를 설정

for i in range(e):
    a,b,c = map(int,input().split())
    edges[i] = [c,a,b]

def find(a):
    if parent[a] == a: #자기 자신이 최상위 노드라면 자신을 반환
        return a
    p = find(parent[a]) #최상위 노드를 거슬러 올라가며 찾음
    parent[a] = p
    return parent[a]

def union(a,b):
    a= find(a) #a집합의 최상위 노드
    b = find(b) #b집합의 최상위 노드
    if a == b:
        return #같은 집합임을 의미함
    if rank[a] > rank[b]:
        parent[b] = a #a가 먼저 생성된 집합이라면 최상위 노드를 a로 함
    else:
        parent[a] = b #그 외의 경우는 b를 최상위 노드로 설정
        if rank[a] == rank[b]: #두개 모두 랭크가 같다면 b를 최상위 노드로 설정했으므로, b를 먼저 생성된 것으로 인식
            rank[b] += 1

def kruskal(edges):
    edges.sort()
    total = 0
    mst =[]
    for edge in edges:
        if not edge: #0번째 제외
            continue
        cost,a,b = edge
        if find(a) != find(b): #a,b의 집합이 다르다는 것이므로 이어붙이기
            union(a,b)
            total += cost #이어 붙였으므로 총 비용 계산
            mst.append((a,b))
    return total

print(kruskal(edges))
