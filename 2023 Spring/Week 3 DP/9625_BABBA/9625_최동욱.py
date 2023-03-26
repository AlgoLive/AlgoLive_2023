K = int(input())

DP_table = {"A": 1, "B": 0}

def DP(K, DP_table):
    for _ in range(K):
        new_B = DP_table["A"] + DP_table["B"]
        new_A = DP_table["B"]

        DP_table["A"] = new_A
        DP_table["B"] = new_B

    print(DP_table["A"], DP_table["B"])

DP(K, DP_table)