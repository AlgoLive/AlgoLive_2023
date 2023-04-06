n = int(input())
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int,input().split()))

f_cnt = 0 #1
s_cnt = 0 #0
t_cnt = 0 #-1

def sol(s,f,size):
    global f_cnt, s_cnt, t_cnt
    if size == 0:
        return
    flag = arr[s][f]

    for i in range(s, s+size):
        for j in range(f, f+size):
            if arr[i][j] != flag:
                s_size = size//3
                for i in range(3):
                    for j in range(3):
                        sol(s+s_size*i,f+s_size*j, s_size)
                return None
    if flag == 1:
        f_cnt += 1
    elif flag == 0:
        s_cnt += 1
    elif flag == -1:
        t_cnt += 1

sol(0,0,n)
print(t_cnt)
print(s_cnt)
print(f_cnt)



