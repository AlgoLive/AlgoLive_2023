# 1, 2, 3, 4, 5, 6, 7, 8
N, M = map(int, input().split())
s = []

def dfs(used, depth, index, visited):
    global N, M
    visited[index] = True
    print(depth, index)

    for i in range(1, N+1):
        if not (visited[depth+1][i]):
            if depth < M+1 and i not in used:
                dfs(used, depth+1, i, visited)
    used.pop()
    visited[node] = False


if __name__ == "__main__":
    visited = [False for _ in range(N+1)]
    dfs(0, 1, visited)

# 탈출 조건 먼저 표현
# dfs + backtracking
