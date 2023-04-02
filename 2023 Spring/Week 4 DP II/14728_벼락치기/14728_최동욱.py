# study_data[0][0]: 공부 시간
# study_data[0][1]: 문제 배점

def sol(study_data):
    dp_table = [[0 for _ in range(T+1)] for _ in range(N)]
    dp_table[0] = [study_data[0][1] if i >= study_data[0][0] else 0 for i in range(T+1)]

    for i in range(1, N):
        for j in range(T+1):
            if study_data[i][0] <= j:
                dp_table[i][j] = max(dp_table[i-1][j-study_data[i][0]]+study_data[i][1], dp_table[i-1][j])
            else:
                dp_table[i][j] = dp_table[i-1][j]

    print(dp_table[N-1][T])


if __name__ == "__main__":
    N, T = map(int, input().split())
    study_data = [[] for _ in range(N)]

    for i in range(N):
        study_data[i] = list(map(int, input().split()))

    sol(study_data)