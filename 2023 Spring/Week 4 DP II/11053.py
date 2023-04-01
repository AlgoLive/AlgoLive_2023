def sol(seq):
    dp_table = [0]*len(seq)
    dp_table[0] = 1

    for i in range(1, len(seq)):
        cur = seq[i]
        max_temp = 0
        for j in range(i):
            if seq[j] < cur:
                max_temp = max(max_temp, dp_table[j])

        dp_table[i] = max_temp + 1

    return max(dp_table)


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    print(sol(A))
