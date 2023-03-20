def go_to_moon(matrix):
    

if __name__ == "__main__":
    N, M = map(int, input().split()) # 2 <= N, M <= 6 / NxM matrix
    matrix = [[] for _ in range(N)]
    for i in range(N):
        matrix[i] = list(map(int, input().split()))

    go_to_moon(matrix)