import sys
sys.setrecursionlimit(10 ** 6) # 숫자는 예시

paper_cnt = {0: 0, 1: 0}

def sol(n, x, y):
    global papers
    p_len = n//2
    flag = papers[y][x]

    for i in range(p_len):
        for j in range(p_len):
            if flag != papers[j][i]:
                sol(p_len, x, y)
                sol(p_len, x + p_len, y)
                sol(p_len, x, y + p_len)
                sol(p_len, x + p_len, y + p_len)

    print(x, y, papers[y][x])
    paper_cnt[papers[y][x]] += 1


if __name__ == "__main__":
    N = int(input())
    papers = [[0 for _ in range(N)] for _ in range(N)]
    paper_cnt = {0: 0, 1: 0}

    for y in range(N):
        papers[y] = list(map(int, input().split()))

    sol(N, 0, 0)
    print(paper_cnt)

# import sys
# sys.setrecursionlimit(10 ** 6) # 숫자는 예시
#
# N = int(input())
# papers = [[0 for _ in range(N)] for _ in range(N)]
# paper_cnt = {0: 0, 1: 0}
#
# for y in range(N):
#     papers[y] = list(map(int, input().split()))
#
# def solve(n, x, y):
#     global papers
#     length = int(n / 2)
#     if n == 2:
#         paper1 = papers[x][y]
#         paper2 = papers[x+length][y]
#         paper3 = papers[x][y+length]
#         paper4 = papers[x+length][y+length]
#         if paper1 == paper2 == paper3 == paper4:
#             return True
#         else:
#             paper_cnt[paper1] += 1
#             paper_cnt[paper2] += 1
#             paper_cnt[paper3] += 1
#             paper_cnt[paper4] += 1
#             return False
#     else:
#         paper1 = solve(length, x, y)
#         paper2 = solve(length, x+length, y)
#         paper3 = solve(length, x, y+length)
#         paper4 = solve(length, x+length, y+length)
#
#         if paper1 and paper2 and paper3 and paper4:
#             return True
#         else:
#             paper_cnt[papers[x][y]] += 1
#             paper_cnt[papers[x+length][y]] += 1
#             paper_cnt[papers[x][y+length]] += 1
#             paper_cnt[papers[x+length][y+length]] += 1
#             return False
#
#
# if __name__ == "__main__":
#     solve(N, 0, 0)
#     print(paper_cnt[0])
#     print(paper_cnt[1])