n = int(input())
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int,input().split()))

def sol(s,f, size):

    if size == 2:
        sarr = []
        for i in range(s, s+size):
            for j in range(f, f+size):
                sarr.append(arr[i][j])
        return sorted(sarr,reverse=True)[1]

    s_size = size//2
    ans = []
    for i in range(2):
        for j in range(2):
            val = sol(s+i*s_size,f+j*s_size,s_size)
            ans.append(val)
    return sorted(ans,reverse=True)[1]

print(sol(0,0,n))

