import sys
from sys import maxsize
import heapq

input = sys.stdin.readline

def solve(start, depend):
    hq = []
    count = [maxsize for _ in range(len(depend))]
    count[start] = 0
    heapq.heappush(hq, (count[start], start))

    while hq:
        from_count, from_com = heapq.heappop(hq)

        if from_count > count[from_com]:
            continue

        for info in depend[from_com]:

            to_count, to_com = info[0], info[1]
            new_count = from_count + to_count
            if new_count < count[to_com]:
                count[to_com] = new_count
                heapq.heappush(hq, (new_count, to_com))

    infected = [x for x in count if x != maxsize]
    prop_time = max(infected)
    print(len(infected), prop_time)


if __name__=="__main__":
    t = int(input())

    for _ in range(t):
        n, d, c = map(int, input().split())
        depend = [[] for _ in range(n+1)]
        for i in range(d):
            a, b, s = map(int, input().split())
            depend[b].append([s, a])

        solve(c, depend)