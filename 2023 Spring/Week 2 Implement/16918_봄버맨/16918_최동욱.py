def progress(bomber_map, N):
    time = 1

    while time < N:
        if time % 2 == 1: # 폭탄 설치 (홀수 시간)
            # 시간 흐름 및 설치
            for i in range(R):
                for j in range(C):
                    if bomber_map[i][j] == 2:
                        bomber_map[i][j] = 1
                    elif bomber_map[i][j] == 0:
                        bomber_map[i][j] = 3

        else: # 폭탄 폭발 (짝수 시간) (해당 시간 됐을 때 bomber_map이 0이면 지금 폭발하도록 함)
            # 시간 흐름 및 폭발 예정 정보 반영
            for i in range(R):
                for j in range(C):
                    if bomber_map[i][j] == 1:
                        bomber_map[i][j] = 0
                        explode_map[i][j] = 1
                    elif bomber_map[i][j] == 3:
                        bomber_map[i][j] = 2

            # 폭발 시키기
            for i in range(R):
                for j in range(C):
                    if explode_map[i][j] == 1:
                        explode_map[i][j] = 0
                        bomber_map[i][j] = 0
                        for dx, dy in zip(dxs, dys):
                            nx, ny = j + dx, i + dy
                            if 0 <= nx < C and 0 <= ny < R:
                                bomber_map[ny][nx] = 0

        # 시간 흐름
        time += 1


if __name__ == "__main__":
    R, C, N = map(int, input().split())
    bomber_map = [[0 for _ in range(C)] for _ in range(R)]
    # 폭탄이 설치 타이머가 적히는 map
    dxs = [1, 0, -1, 0]
    dys = [0, 1, 0, -1]

    explode_map = [[0 for _ in range(C)] for _ in range(R)]
    # explode 현황을 보여주는 map

    for i in range(R):
        tmp_line = input()
        for j in range(C):
            if tmp_line[j] == '.':
                continue
            else:
                bomber_map[i][j] = 2
                # 1초 이미 지난 후의 모습으로

    progress(bomber_map, N)

    for i in range(R):
        for j in range(C):
            if bomber_map[i][j] == 0:
                print('.', end='')
            else:
                print('O', end='')
        print()