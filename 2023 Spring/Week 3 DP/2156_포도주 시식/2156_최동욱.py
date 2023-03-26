if __name__ == "__main__":
    N = int(input())

    wines = [0 for _ in range(10000)]

    for i in range(N):
        wines[i] = int(input())

    drunk = [0 for _ in range(10000)]

    drunk[0] = wines[0]
    drunk[1] = wines[0] + wines[1]
    drunk[2] = max(wines[0] + wines[2], wines[1] + wines[2], drunk[1])

    for i in range(3, N):
        drunk[i] = max(drunk[i-3] + wines[i-1] + wines[i], drunk[i-2] + wines[i], drunk[i-1])

    print(max(drunk))