import collections

N = int(input())
N_nums_counter = collections.Counter(map(int, input().split()))

M = int(input())
M_nums_list = map(int, input().split())

for i in M_nums_list:
    print(N_nums_counter[i], end=' ')
