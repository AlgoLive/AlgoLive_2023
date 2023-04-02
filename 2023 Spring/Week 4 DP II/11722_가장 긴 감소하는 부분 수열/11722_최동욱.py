def sol(A):
    dp_table = [0 for _ in range(len(A))]
    dp_table[0] = 1

    for i in range(1, len(A)):
        dp_table[i] = 1
        for j in range(i):
            if A[j] > A[i]:
                dp_table[i] = max(dp_table[i], dp_table[j] + 1)

    print(max(dp_table))


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    sol(A)
