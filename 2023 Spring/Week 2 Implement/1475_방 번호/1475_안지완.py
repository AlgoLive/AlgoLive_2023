p_set = {}
n = str(input())

for i in range(0,10):
    p_set[str(i)] = 1

cnt = 1

for i in n:
    if p_set[i] > 0:
        p_set[i] -= 1
    else:
        if i == '6' and p_set['9'] > 0:
            p_set['9'] -= 1
        elif i == '9' and p_set['6'] > 0:
            p_set['6'] -= 1
        else:
            cnt+=1
            for j in range(0,10):
                p_set[str(j)] += 1
            p_set[i] -= 1

print(cnt)