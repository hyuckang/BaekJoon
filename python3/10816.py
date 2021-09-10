import collections

N = int(input())
N_nums = list(map(int, input().split()))
N_nums_counter = collections.Counter(N_nums)

M = int(input())
M_nums = list(map(int, input().split()))

for i in M_nums:
    print(N_nums_counter[i], end=' ')
