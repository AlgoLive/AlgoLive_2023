from math import ceil

no_list = [0 for _ in range(10)]
nums = input()

for n in nums:
    no_list[int(n)] += 1

for n in no_list:
    tmp6=no_list[6]
    tmp9=no_list[9]
    no_list[6] = ceil(((tmp6 + tmp9) / 2))
    no_list[9] = ceil(((tmp6 + tmp9) / 2))

print(int(max(no_list)))