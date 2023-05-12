from math import *

n = int(input())
used = [0 for _ in range(n)]
ans = []

def isPrime(num):
    if num < 2:
        return False
    for i in range(2,round(sqrt(num))+1):
        if num%i == 0:
            return False
    return True

def sol(depth,num,sum):
    global used, ans

    if depth==n-1 and isPrime(sum):
        for i in range(1,10):
            res = sum*10+i
            if res not in ans and isPrime(res):
                ans.append(res)
        return

    sum = sum*10 + num

    if not isPrime(sum):
        return

    for i in range(1,10):
        sol(depth+1, i, sum)

if n == 1:
    print(2,3,5,7,sep="\n")
    exit()

for i in range(1,10):
    if isPrime(i):
        sol(0,i,0)

for result in ans:
    print(result)
