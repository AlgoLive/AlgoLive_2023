def get_the_max_value(N, stickers):
    dp_table = [[] for _ in range(N)]
    dp_table[0] = [(stickers[0][0], 0), (stickers[1][0], 1)]
    if N == 1:
        return max(dp_table[0])[0]

    dp_table[1] = [(stickers[0][0] + stickers[1][1], 1), (stickers[1][0] + stickers[0][1], 0)]
    if N == 2:
        return max(dp_table[1])[0]

    elif N > 2:
        dp_table[1] = [(stickers[0][0]+stickers[1][1], 1), (stickers[1][0]+stickers[0][1], 0)]

        for i in range(2, N):
            temp_0 = []
            temp_1 = []

            for info in dp_table[i - 2]:
                temp_0.append((info[0] + stickers[0][i], 0))
                temp_1.append((info[0] + stickers[1][i], 1))

            for info in dp_table[i - 1]:
                if info[1] == 0:
                    temp_1.append((info[0] + stickers[1][i], 1))
                else:
                    temp_0.append((info[0] + stickers[0][i], 0))

            dp_table[i] = [max(temp_0), max(temp_1)]

    return max(dp_table[N-1])[0]


if __name__ == "__main__":
    T = int(input())
    stickers = []

    for _ in range(T):
        N = int(input())
        temp = []
        temp.append(N)
        temp.append(list(map(int, input().split())))
        temp.append(list(map(int, input().split())))
        stickers.append(temp)

    for sticker in stickers:
        print(get_the_max_value(sticker[0], sticker[1:]))