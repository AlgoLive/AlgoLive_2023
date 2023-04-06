n = int(input())
arr = [[] for _ in range(n)]

for i in range(n):
    arr[i] = list(map(int,input().rstrip()))

def sol(s,f,size):
    global arr

    flag = arr[s][f]

    if size == 1:
        print(flag, end = "")
        return None

    for row in range(s,s+size):
        for col in range(f, f+size):
            if flag != arr[row][col]:
                s_size = size//2
                print("(", end = "")
                sol(s,f,s_size)
                sol(s,f+s_size,s_size)
                sol(s+s_size,f,s_size)
                sol(s+s_size,f+s_size,s_size)
                print(")", end = "")
                return

    print(flag, end = "")

sol(0,0,n)
