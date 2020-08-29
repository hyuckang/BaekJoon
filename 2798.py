N, M = map(int, input().split(' '))
A = list(map(int, input().split(' ')))

min_sub = 987654321
res = 0

for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            tmp = A[i] + A[j] + A[k]
            if(tmp > M):
                continue
            if(M - tmp < min_sub):
                min_sub = M - tmp
                res = tmp

print(res)
