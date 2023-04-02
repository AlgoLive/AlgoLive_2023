def sol(seq):
    dp_table = [0] * len(seq)
    dp_table[0] = seq[0]

    for i in range(1, len(seq)):
        cur = seq[i]
        max_temp = seq[i]
        for j in range(i):
            if seq[j] < cur:
                max_temp = max(max_temp, dp_table[j] + seq[i])

        dp_table[i] = max_temp

    return max(dp_table)


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    print(sol(A))
