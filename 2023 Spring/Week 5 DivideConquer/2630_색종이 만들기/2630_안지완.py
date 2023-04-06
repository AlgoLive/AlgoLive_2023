n = int(input())
arr = [[] for _ in range(n)]
b_cnt = 0
w_cnt = 0

for i in range(n):
    arr[i] = list(map(int,input().split()))

def sol(s,f,size):
    global b_cnt, w_cnt
    if size == 0:
        return
    b_flag = 0
    w_flag = 0

    for i in range(s,s+size):
        for j in range(f,f+size):
            if arr[i][j] == 1:
                b_flag = 1
            elif arr[i][j] == 0:
                w_flag = 1
    if b_flag == 1 and w_flag == 0:
        b_cnt += 1
    elif b_flag == 0 and w_flag == 1:
        w_cnt += 1
    else:
        s_size = size//2
        sol(s,f,s_size)
        sol(s+s_size,f,s_size)
        sol(s,f+s_size,s_size)
        sol(s+s_size,f+s_size,s_size)

sol(0,0,n)
print(w_cnt)
print(b_cnt)



