import heapq
from sys import maxsize
import sys

inf = 1e9
input = sys.stdin.readline


def solve(start, end, cities):
    hq = []
    distance = [maxsize for _ in range(N+1)]
    distance[start] = 0
    heapq.heappush(hq, (0, start))

    while hq:
        from_cost, from_city = heapq.heappop(hq)

        if distance[from_city] < from_cost:
            continue

        for info in cities[from_city]:
            to_cost, to_city = info[0], info[1]
            new_distance = from_cost + to_cost
            if distance[to_city] > new_distance:
                heapq.heappush(hq, (new_distance, to_city))
                distance[to_city] = new_distance

    return distance[end]


if __name__=="__main__":
    N = int(input())
    M = int(input())
    cities = [[] for _ in range(N+1)]

    for _ in range(M):
        s, e, d = map(int, input().split())
        cities[s].append([d, e])

    start, end = map(int, input().split())
    print(solve(start, end, cities))


# 처음에 안되어서, visited 안쓰고 distance로 해결
# 그래도 17% 떠서 보니, 처음에 for문 들어가기 전에 걸러줄 수 있는 distance[from_city] < from_cost 추가
# 진짜 더러운 문제군요...