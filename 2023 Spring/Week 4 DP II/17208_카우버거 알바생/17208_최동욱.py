# def solve(orders):
#     sorted_orders = []
#     for order in orders:
#         sorted_orders.append([order[0]+order[1], order[0], order[1]])
#
#     sorted_orders.sort()
#     # 0 -> 합, 1 -> 치즈버거 (M), 2 -> 감자튀김 (K)
#
#     dp_table = []

def solve(orders):

    dp_table = [[] for _ in range(len(orders))]





if __name__ == '__main__':
    N, M, K = map(int, input().split())
    orders = []
    for _ in range(N):
        orders.append(list(map(int, input().split())))

    solve(orders)