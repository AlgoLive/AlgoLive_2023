a,b,c = map(int,input().split())
def sol(n):
    if n == 1:
        return a%c
    tmp = sol(n//2)
    if n%2 == 0:
        ans = (tmp*tmp)%c
        return ans
    else:
        ans = (tmp*tmp*a)%c
        return ans
print(sol(b))