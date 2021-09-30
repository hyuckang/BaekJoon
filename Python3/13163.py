N = int(input())
for _ in range(N):
    S = str(input()).split(' ')
    res = "god"
    for i in S[1:]:
        res += i
    print(res)
