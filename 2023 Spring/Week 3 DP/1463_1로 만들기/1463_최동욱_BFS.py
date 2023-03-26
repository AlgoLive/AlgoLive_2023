from collections import deque

def bfs(N):
    dp_table = [0] * 1000001
    q = deque()
    q.append(1)

    while q:
        cur = q.popleft()
        if cur == N:
            return dp_table[cur]
        if cur * 3 <= 1000000 and dp_table[cur * 3] == 0:
            dp_table[cur * 3] = dp_table[cur] + 1
            q.append(cur * 3)
        if cur * 2 <= 1000000 and dp_table[cur * 2] == 0:
            dp_table[cur * 2] = dp_table[cur] + 1
            q.append(cur * 2)
        if cur + 1 <= 1000000 and dp_table[cur + 1] == 0:
            dp_table[cur + 1] = dp_table[cur] + 1
            q.append(cur + 1)


if __name__ == "__main__":
    N = int(input())
    print(bfs(N))