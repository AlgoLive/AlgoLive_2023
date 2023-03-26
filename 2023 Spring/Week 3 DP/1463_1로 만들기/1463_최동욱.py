def sol(N):
    dp_table = [0] * 1000001
    dp_table[1] = 0
    dp_table[2] = 1
    dp_table[3] = 1

    for i in range(4, N+1):
        min_targets = []
        if i % 3 == 0:
            min_targets.append(dp_table[int(i/3)] + 1)
        if i % 2 == 0:
            min_targets.append(dp_table[int(i/2)] + 1)
        min_targets.append(dp_table[i-1] + 1)

        dp_table[i] = min(min_targets)

    return dp_table[N]


if __name__ == "__main__":
    N = int(input())
    print(sol(N))