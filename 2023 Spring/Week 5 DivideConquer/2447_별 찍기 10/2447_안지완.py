n = int(input())
arr = [[0 for _ in range(n)] for _ in range(n)]

def sol(r,c,size):
    s_size = size//3
    if size == 3:
        for i in range(r,r+size):
            for j in range(c,c+size):
                arr[i][j] = 1
    else:
        for i in range(3):
            for j in range(3):
                sol(r+s_size*i, c+s_size*j,s_size)
    b_r = r+s_size
    b_c = c+s_size
    for i in range(b_r, b_r+s_size):
        for j in range(b_c, b_c+s_size):
            arr[i][j] = 0

sol(0,0,n)
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            print("*", end = "")
        else:
            print(" ", end = "")
    print()
